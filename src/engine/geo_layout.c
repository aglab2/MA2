#include <ultra64.h>
#include "sm64.h"

#include "geo_layout.h"
#include "math_util.h"
#include "game/memory.h"
#include "graph_node.h"
#include "game/debug.h"
#include "batch_ht.h"
#include "flipbook.h"
#include "game/area.h"
#include "game/emutest.h"

typedef void (*GeoLayoutCommandProc)(void);

static const GeoLayoutCommandProc GeoLayoutJumpTable[] = {
    /*GEO_CMD_BRANCH_AND_LINK           */ geo_layout_cmd_branch_and_link,
    /*GEO_CMD_END                       */ geo_layout_cmd_end,
    /*GEO_CMD_BRANCH                    */ geo_layout_cmd_branch,
    /*GEO_CMD_RETURN                    */ geo_layout_cmd_return,
    /*GEO_CMD_OPEN_NODE                 */ geo_layout_cmd_open_node,
    /*GEO_CMD_CLOSE_NODE                */ geo_layout_cmd_close_node,
    /*GEO_CMD_ASSIGN_AS_VIEW            */ geo_layout_cmd_assign_as_view,
    /*GEO_CMD_UPDATE_NODE_FLAGS         */ geo_layout_cmd_update_node_flags,
    /*GEO_CMD_NODE_ROOT                 */ geo_layout_cmd_node_root,
    /*GEO_CMD_NODE_ORTHO_PROJECTION     */ geo_layout_cmd_node_ortho_projection,
    /*GEO_CMD_NODE_PERSPECTIVE          */ geo_layout_cmd_node_perspective,
    /*GEO_CMD_NODE_START                */ geo_layout_cmd_node_start,
    /*GEO_CMD_NODE_MASTER_LIST          */ geo_layout_cmd_node_master_list,
    /*GEO_CMD_NODE_LEVEL_OF_DETAIL      */ geo_layout_cmd_node_level_of_detail,
    /*GEO_CMD_NODE_SWITCH_CASE          */ geo_layout_cmd_node_switch_case,
    /*GEO_CMD_NODE_CAMERA               */ geo_layout_cmd_node_camera,
    /*GEO_CMD_NODE_TRANSLATION_ROTATION */ geo_layout_cmd_node_translation_rotation,
    /*GEO_CMD_NODE_TRANSLATION          */ geo_layout_cmd_node_translation,
    /*GEO_CMD_NODE_ROTATION             */ geo_layout_cmd_node_rotation,
    /*GEO_CMD_NODE_ANIMATED_PART        */ geo_layout_cmd_node_animated_part,
    /*GEO_CMD_NODE_BILLBOARD            */ geo_layout_cmd_node_billboard,
    /*GEO_CMD_NODE_DISPLAY_LIST         */ geo_layout_cmd_node_display_list,
    /*GEO_CMD_NODE_SHADOW               */ geo_layout_cmd_node_shadow,
    /*GEO_CMD_NODE_OBJECT_PARENT        */ geo_layout_cmd_node_object_parent,
    /*GEO_CMD_NODE_GENERATED            */ geo_layout_cmd_node_generated,
    /*GEO_CMD_NODE_BACKGROUND           */ geo_layout_cmd_node_background,
    /*GEO_CMD_NOP_1A                    */ geo_layout_cmd_nop,
    /*GEO_CMD_COPY_VIEW                 */ geo_layout_cmd_copy_view,
    /*GEO_CMD_NODE_HELD_OBJ             */ geo_layout_cmd_node_held_obj,
    /*GEO_CMD_NODE_SCALE                */ geo_layout_cmd_node_scale,
    /*GEO_CMD_NOP_1E                    */ geo_layout_cmd_nop2,
    /*GEO_CMD_NODE_CULL                 */ geo_layout_cmd_node_cull,
    /*GEO_CMD_NODE_CULLING_RADIUS       */ geo_layout_cmd_node_culling_radius,
    /*GEO_CMD_NODE_COIN      */            geo_layout_cmd_coin,

    /* GEO_CMD_LVL_NODE_TRANSLATION_ROTATION */ geo_layout_cmd_lvl_translation_rotation,
    /* GEO_CMD_LVL_NODE_TRANSLATION */          geo_layout_cmd_lvl_translation,
    /* GEO_CMD_CRUMBLE_NODE_TRANSLATION */      geo_layout_cmd_break_translation,
    /* GEO_CMD_OBJ_NODE_TRANSLATION_ROTATION */ geo_layout_cmd_obj_node_translation_rotation,
    /* GEO_CMD_OBJ_ROCKET_NODE_TRANSLATION */   geo_layout_cmd_obj_rocket_node_translation,
    /* GEO_CMD_OBJ_NODE_TRANSLATION */          geo_layout_cmd_obj_node_translation,
    /* GEO_CMD_CRUMBLE_NODE_TRANSLATION_ROTATION */ geo_layout_cmd_break_translation_rotation,
    /* GEO_CMD_BATCHSET_NODE */                 geo_layout_cmd_batchset_node,
    /* GEO_CMD_NODE_BATCH_DISPLAY_LIST */       geo_layout_cmd_node_batch_display_list,
    /* GEO_CMD_NODE_BATCH_GENERATED */          geo_layout_cmd_node_batch_generated,
    /* GEO_CMD_NODE_BATCH_DISPLAY_LIST_ANIM */  geo_layout_cmd_node_batch_display_list_anim,
    /* GEO_CMD_NODE_BATCH_START */              geo_layout_cmd_node_batch_start,
    /* GEO_CMD_BATCHSET_NODE_TRANSLATION */     geo_layout_cmd_batchset_node_translation,
    /* GEO_CMD_BATCHSET_NODE_TRANSLATION_ROTATION */ geo_layout_cmd_batchset_node_translation_rotation,
};

struct GraphNode gObjParentGraphNode;
struct GraphNode *gCurRootGraphNode;

/* The gGeoViews array is a mysterious one. Some background:
 *
 * If there are e.g. multiple Goombas, the multiple Goomba objects share one
 * Geo node tree describing the goomba 3D model. Since every node has a single
 * parent field and not a parent array, the parent is dynamically rebinded to
 * each goomba instance just before rendering and set to null afterwards.
 * The same happens for ObjectParentNode, which has as his sharedChild a group
 * of all 240 object nodes. Why does the ObjectParentNode exist at all, if its
 * only purpose is to temporarily bind the actual group with objects? This might
 * be another remnant to Luigi.
 *
 * When creating a root node, room for (2 + cmd+0x02) pointers is allocated in
 * gGeoViews. Except for the title screen, cmd+0x02 is 10. The 2 default ones
 * might be for Mario and Luigi, and the other 10 could be different cameras for
 * different rooms / boss fights. An area might be structured like this:
 *
 * geo_camera mode_player //Mario cam
 * geo_open_node
 *   geo_render_obj
 *   geo_assign_as_view 1   // currently unused geo command
 * geo_close_node
 *
 * geo_camera mode_player //Luigi cam
 * geo_open_node
 *   geo_render_obj
 *   geo_copy_view 1        // currently unused geo command
 *   geo_assign_as_view 2
 * geo_close_node
 *
 * geo_camera mode_boss //boss fight cam
 * geo_assign_as_view 3
 * ...
 *
 * There might also be specific geo nodes for Mario or Luigi only. Or a fixed camera
 * might not have display list nodes of parts of the level that are out of view.
 * In the end Luigi got scrapped and the multiple-camera design did not pan out,
 * so everything was reduced to a single ObjectParent with a single group, and
 * camera switching was all done in one node. End of speculation.
 */
struct GraphNode **gGeoViews;
u16 gGeoNumViews; // length of gGeoViews array

uintptr_t gGeoLayoutStack[16];
struct GraphNode *gCurGraphNodeList[32];
s16 gCurGraphNodeIndex;
s16 gGeoLayoutStackIndex; // similar to SP register in MIPS
s16 gGeoLayoutReturnIndex; // similar to RA register in MIPS
u8 *gGeoLayoutCommand;

/*
  0x00: Branch and store return address
   cmd+0x04: void *branchTarget
*/
void geo_layout_cmd_branch_and_link(void) {
    gGeoLayoutStack[gGeoLayoutStackIndex++] = (uintptr_t) (gGeoLayoutCommand + CMD_PROCESS_OFFSET(8));
    gGeoLayoutStack[gGeoLayoutStackIndex++] = (gCurGraphNodeIndex << 16) + gGeoLayoutReturnIndex;
    gGeoLayoutReturnIndex = gGeoLayoutStackIndex;
    gGeoLayoutCommand = segmented_to_virtual(cur_geo_cmd_ptr(0x04));
}

// 0x01: Terminate geo layout
void geo_layout_cmd_end(void) {
    gGeoLayoutStackIndex = gGeoLayoutReturnIndex;
    gGeoLayoutReturnIndex = gGeoLayoutStack[--gGeoLayoutStackIndex] & 0xFFFF;
    gCurGraphNodeIndex = gGeoLayoutStack[gGeoLayoutStackIndex] >> 16;
    gGeoLayoutCommand = (u8 *) gGeoLayoutStack[--gGeoLayoutStackIndex];
}

/*
  0x02: Branch
   cmd+0x04: void *branchTarget
*/
void geo_layout_cmd_branch(void) {
    if (cur_geo_cmd_u8(0x01) == 1) {
        gGeoLayoutStack[gGeoLayoutStackIndex++] = (uintptr_t) (gGeoLayoutCommand + CMD_PROCESS_OFFSET(8));
    }

    gGeoLayoutCommand = segmented_to_virtual(cur_geo_cmd_ptr(0x04));
}

#define DEBUG_ASSERTIONS
#ifdef DEBUG_ASSERTIONS
#define ASSERT_PRINTF(cond, fmt, ...) do{ if (!(cond)) { char msg[40]; sprintf(msg, fmt, ##__VA_ARGS__); error(msg); } }while(0)
#else
#define ASSERT_PRINTF(cond, fmt, ...) do{}while(0)
#endif

// 0x03: Return from branch
static struct GraphNodeMasterList *gMasterNode = NULL;
void geo_layout_cmd_return(void) {
    gGeoLayoutCommand = (u8 *) gGeoLayoutStack[--gGeoLayoutStackIndex];
}

// 0x04: Open node
void geo_layout_cmd_open_node(void) {
    gCurGraphNodeList[gCurGraphNodeIndex + 1] = gCurGraphNodeList[gCurGraphNodeIndex];
    gCurGraphNodeIndex++;
    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

// 0x05: Close node
void geo_layout_cmd_close_node(void) {
    gCurGraphNodeIndex--;
    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

/*
  0x06: Register the current node as a view
   cmd+0x02: index

  Register the current node in the gGeoViews array at the given index
*/
void geo_layout_cmd_assign_as_view(void) {
    u16 index = cur_geo_cmd_s16(0x02);

    if (index < gGeoNumViews) {
        gGeoViews[index] = gCurGraphNodeList[gCurGraphNodeIndex];
    }

    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

/*
  0x07: Update current scene graph node flags
   cmd+0x01: u8 operation (0 = reset, 1 = set, 2 = clear)
   cmd+0x02: s16 bits
*/
void geo_layout_cmd_update_node_flags(void) {
    u16 operation = cur_geo_cmd_u8(0x01);
    u16 flagBits = cur_geo_cmd_s16(0x02);

    switch (operation) {
        case GEO_CMD_FLAGS_RESET:
            gCurGraphNodeList[gCurGraphNodeIndex]->flags = flagBits;
            break;
        case GEO_CMD_FLAGS_SET:
            gCurGraphNodeList[gCurGraphNodeIndex]->flags |= flagBits;
            break;
        case GEO_CMD_FLAGS_CLEAR:
            gCurGraphNodeList[gCurGraphNodeIndex]->flags &= ~flagBits;
            break;
    }

    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

/*
  0x08: Create a scene graph root node that specifies the viewport
   cmd+0x02: s16 num entries (+2) to allocate for gGeoViews
   cmd+0x04: s16 x
   cmd+0x06: s16 y
   cmd+0x08: s16 width
   cmd+0x0A: s16 height
*/
void geo_layout_cmd_node_root(void) {
    s32 i;
    struct GraphNodeRoot *graphNode;

    s16 x = cur_geo_cmd_s16(0x04);
    s16 y = cur_geo_cmd_s16(0x06);
    s16 width = cur_geo_cmd_s16(0x08);
    s16 height = cur_geo_cmd_s16(0x0A);

    // number of entries to allocate for gGeoViews array
    // at least 2 are allocated by default
    // cmd+0x02 = 0x00: Mario face, 0x0A: all other levels
    gGeoNumViews = cur_geo_cmd_s16(0x02) + 2;

    graphNode = init_graph_node_root(NULL, 0, x, y, width, height);

    // TODO: check type
    gGeoViews = main_pool_alloc(gGeoNumViews * sizeof(struct GraphNode *));

    graphNode->views = gGeoViews;
    graphNode->numViews = gGeoNumViews;

    for (i = 0; i < gGeoNumViews; i++) {
        gGeoViews[i] = NULL;
    }

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x0C << CMD_SIZE_SHIFT;
}

/*
  0x09: Create orthographic projection scene graph node
   cmd+0x02: s16 scale as a percentage (usually it's 100)
*/
void geo_layout_cmd_node_ortho_projection(void) {
    struct GraphNodeOrthoProjection *graphNode;
    f32 scale = (f32) cur_geo_cmd_s16(0x02) / 100.0f;

    graphNode = init_graph_node_ortho_projection(NULL, scale);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

/*
  0x0A: Create camera frustum scene graph node
   cmd+0x01: u8  if nonzero, enable frustumFunc field
   cmd+0x02: s16 field of view
   cmd+0x04: u16 near
   cmd+0x06: u16 far
   [cmd+0x08: GraphNodeFunc frustumFunc]
*/
void geo_layout_cmd_node_perspective(void) {
    struct GraphNodePerspective *graphNode;
    GraphNodeFunc frustumFunc = NULL;
    s16 fov = cur_geo_cmd_s16(0x02);
    u16 near = cur_geo_cmd_u16(0x04);
    u16 far = cur_geo_cmd_u16(0x06);

    if (cur_geo_cmd_u8(0x01) != 0) {
        // optional asm function
        frustumFunc = (GraphNodeFunc) cur_geo_cmd_ptr(0x08);
        gGeoLayoutCommand += 4 << CMD_SIZE_SHIFT;
    }

    graphNode = init_graph_node_perspective(NULL, (f32) fov, near, far, frustumFunc);

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

/*
  0x0B: Create a scene graph node that groups other nodes without any
  additional functionality
*/
void geo_layout_cmd_node_start(void) {
    struct GraphNodeStart *graphNode = init_graph_node_start(NULL);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

struct CloneResult
{
    void* clonedDl;
    u8 offCI4;
    u8 offPal;
    u8 offTile;
    u8 offPrimColor;
};

static struct CloneResult clone_dl(const void* _dl)
{
    struct CloneResult result = { 0 };
    const u8* start = _dl;
    const u8* dl = _dl;
    while (G_ENDDL != *dl)
    {
        if (G_SETTIMG == *dl)
        {
            u8 b1 = dl[1];
            int fmt = b1 >> 5;
            int texOff = dl - start + 4;
            if (fmt == G_IM_FMT_CI)
            {
                result.offCI4 = texOff;
            }
            else if (fmt == G_IM_FMT_RGBA)
            {
                result.offPal = texOff;
            }
        }
        if (G_SETTILESIZE == *dl)
        {
            result.offTile = dl - start;
        }
        if (G_SETPRIMCOLOR == *dl)
        {
            result.offPrimColor = dl - start;
        }

        dl += 8;
    }

    // I need very good alignment guarantees for gfx dls
    void* clonedDl = main_pool_alloc_aligned(2, dl - start + 8, 8);
    memcpy(clonedDl, start, dl - start + 8);
    result.clonedDl = clonedDl;

    return result;
}

static struct FlipbookArray* make_flipbooks(struct FlipbookLayer* flipbooksLayers, int layer, const struct BatchDisplayLists* batchDLs)
{
    if (!flipbooksLayers)
        return NULL;

    struct FlipbookLayer* layerFlipbooks = &flipbooksLayers[layer];
    if (!layerFlipbooks->count)
        return NULL;

    struct FlipbookArray* flipbooks = main_pool_alloc(sizeof(struct FlipbookArray) + layerFlipbooks->count * sizeof(struct FlipbookDls));
    flipbooks->count = layerFlipbooks->count;
    flipbooks->data = segmented_to_virtual(layerFlipbooks->data);
    for (int flipId = 0; flipId < layerFlipbooks->count; flipId++)
    {
        const struct FlipbookData* flipData = &flipbooks->data[flipId];
        struct FlipbookDls* flipDls = &flipbooks->dls[flipId];
        void* dl = segmented_to_virtual(batchDLs[flipData->batchId].startDl);
        struct CloneResult cloneResult = clone_dl(dl);
        flipDls->startDls[0] = dl;
        flipDls->startDls[1] = cloneResult.clonedDl;
        flipDls->offCI4 = cloneResult.offCI4;
        flipDls->offPal = cloneResult.offPal;
        flipDls->offTile = cloneResult.offTile;
        flipDls->offPrimColor = cloneResult.offPrimColor;
    }

    return flipbooks;
}

void geo_layout_cmd_node_batch_start(void) {
    struct BatchLevelDisplayLists* dls = (struct BatchLevelDisplayLists*) cur_geo_cmd_ptr(0x04);
    struct FlipbookLayer* flipbooksLayers = (struct FlipbookLayer*) cur_geo_cmd_ptr(0x08);
    dls = segmented_to_virtual(dls);
    if (flipbooksLayers)
        flipbooksLayers = segmented_to_virtual(flipbooksLayers);

    struct GraphNodeStart *graphNode = init_graph_node_start(NULL);

    register_scene_graph_node(&graphNode->node);

    for (int layer = LAYER_FIRST; layer < LAYER_COUNT; layer++)
    {
        int total = dls[layer].count;
        if (0 == total)
            continue;

        struct MasterLayer* masterLayer = &gMasterNode->layers[layer];
        struct BatchArray* batches = main_pool_alloc(sizeof(struct BatchArray) + total * sizeof(struct DisplayListLinks));
        batches->count = total;
        const struct BatchDisplayLists* batchDLs = segmented_to_virtual(dls[layer].lists);
        batches->batchDLs = batchDLs;

        masterLayer->course = batches;
        masterLayer->flipbooks = make_flipbooks(flipbooksLayers, layer, batchDLs);
    }

    gGeoLayoutCommand += 0x0C << CMD_SIZE_SHIFT;
}

// 0x1F: No operation
void geo_layout_cmd_node_cull(void) {
    s16 x0 = cur_geo_cmd_s16(0x04);
    s16 x1 = cur_geo_cmd_s16(0x06);
    s16 y0 = cur_geo_cmd_s16(0x08);
    s16 y1 = cur_geo_cmd_s16(0x0a);
    s16 z0 = cur_geo_cmd_s16(0x0c);
    s16 z1 = cur_geo_cmd_s16(0x0e);
    s16 style = cur_geo_cmd_s16(0x02);

    struct GraphNodeCull *graphNode = init_graph_node_cull(NULL, x0, x1, y0, y1, z0, z1, style);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x10 << CMD_SIZE_SHIFT;
}

/*
  0x0C: Create z-buffer-toggling scene graph node
   cmd+0x01: u8 enableZBuffer (1 = on, 0 = off)
*/
void geo_layout_cmd_node_master_list(void) {
    struct GraphNodeMasterList *graphNode = init_graph_node_master_list(NULL, cur_geo_cmd_u8(0x01));

    gMasterNode = graphNode;
    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

/*
  0x0D: Create a level of detail graph node, which only renders at a certain
  distance interval from the camera.
   cmd+0x04: s16 minDistance
   cmd+0x06: s16 maxDistance
*/
void geo_layout_cmd_node_level_of_detail(void) {
    s16 minDistance = cur_geo_cmd_s16(0x04);
    s16 maxDistance = cur_geo_cmd_s16(0x06);

    struct GraphNodeLevelOfDetail *graphNode =
        init_graph_node_render_range(NULL, minDistance, maxDistance);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

void geo_layout_cmd_coin()
{
    struct GraphNodeCoin *graphNode;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    void* displayList = cur_geo_cmd_ptr(0x04);
    void* displayList_r = cur_geo_cmd_ptr(0x08);

    graphNode = init_graph_node_coin(NULL, drawingLayer, displayList, displayList_r);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x0C << CMD_SIZE_SHIFT;
}

/*
  0x0E: Create switch-case scene graph node
   cmd+0x02: s16 initialSelectedCase
   cmd+0x04: GraphNodeFunc caseSelectorFunc

  caseSelectorFunc returns an index which is used to select the child node to render.
  Used for animating coins, blinking, color selection, etc.
*/
void geo_layout_cmd_node_switch_case(void) {
    struct GraphNodeSwitchCase *graphNode =
        init_graph_node_switch_case(NULL,
                                    cur_geo_cmd_s16(0x02), // case which is initially selected
                                    0,
                                    (GraphNodeFunc) cur_geo_cmd_ptr(0x04), // case update function
                                    0);

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

/*
 0x0F: Create a camera scene graph node (GraphNodeCamera). The focus sets the Camera's areaCen position.
  cmd+0x02: s16 camera type (changes from course to course)
  cmd+0x04: s16 posX
  cmd+0x06: s16 posY
  cmd+0x08: s16 posZ
  cmd+0x0A: s16 focusX
  cmd+0x0C: s16 focusY
  cmd+0x0E: s16 focusZ
  cmd+0x10: GraphNodeFunc func
*/
struct GraphNodeCamera* sCameraCache = NULL;
struct GraphNodeMasterList* sCameraCacheMasterNode = NULL;
void geo_layout_cmd_node_camera(void) {
    struct GraphNodeCamera *graphNode;
    s16 *cmdPos = (s16 *) &gGeoLayoutCommand[4];

    Vec3f pos, focus;

    cmdPos = read_vec3s_to_vec3f(pos, cmdPos);
    cmdPos = read_vec3s_to_vec3f(focus, cmdPos);

    graphNode = init_graph_node_camera(NULL, pos, focus,
                                       (GraphNodeFunc) cur_geo_cmd_ptr(0x10), cur_geo_cmd_s16(0x02));

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoViews[0] = &graphNode->fnNode.node;

    if (sCameraCache)
    {
        // copy in shared data
        graphNode->fnNode.node.children = sCameraCache->fnNode.node.children;
        // also copy in batches from cached master node, references are ok
        // TODO: Perform the same for objects
        for (int i = 0; i < LAYER_COUNT; i++)
        {
            gMasterNode->layers[i].course = sCameraCacheMasterNode->layers[i].course;
            gMasterNode->layers[i].flipbooks = sCameraCacheMasterNode->layers[i].flipbooks;
        }

        // When cache is hit, the following pattern is seen
        /*
        GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -10, 0, geo_camera_main),
        GEO_OPEN_NODE(),
            GEO_BRANCH(1, ce_area_1_geo),
            GEO_RENDER_OBJ(),
            GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
        GEO_CLOSE_NODE(),
        */
        gGeoLayoutCommand += (0x14 << CMD_SIZE_SHIFT) 
                           + (0x4  << CMD_SIZE_SHIFT) 
                           + (0x8  << CMD_SIZE_SHIFT) 
                           + (0x4  << CMD_SIZE_SHIFT) 
                           + (0x8  << CMD_SIZE_SHIFT) 
                           + (0x4  << CMD_SIZE_SHIFT);
    }
    else
    {
        sCameraCache = graphNode;
        sCameraCacheMasterNode = gMasterNode;
        gGeoLayoutCommand += 0x14 << CMD_SIZE_SHIFT;
    }
}

/*
  0x10: Create translation & rotation scene graph node with optional display list
   cmd+0x01: u8 params
     (params & 0x80): if set, enable displayList field and drawingLayer
     ((params & 0x70)>>4): fieldLayout
     (params & 0x0F): drawingLayer

   fieldLayout == 0:
    cmd+0x04: s16 xTranslation
    cmd+0x06: s16 yTranslation
    cmd+0x08: s16 zTranslation
    cmd+0x0A: s16 xRotation
    cmd+0x0C: s16 yRotation
    cmd+0x0E: s16 zRotation

   fieldLayout == 1:
    cmd+0x02: s16 xTranslation
    cmd+0x04: s16 yTranslation
    cmd+0x06: s16 zTranslation
    (rotation gets copied from gVec3sZero)

   fieldLayout == 2:
    cmd+0x02: s16 xRotation
    cmd+0x04: s16 yRotation
    cmd+0x06: s16 zRotation
    (translation gets copied from gVec3sZero)

   fieldLayout == 3:
    cmd+0x02: s16 yRotation
    (translation gets copied from gVec3sZero)
    (x and z translation are set to 0)

   [cmd+var: void *displayList]
*/
static void geo_layout_cmd_node_translation_rotation_impl(int style, int devirt) {
    struct GraphNodeTranslationRotation *graphNode;

    Vec3s translation, rotation;

    void *displayList = NULL;
    s16 drawingLayer = LAYER_FIRST;

    s16 params = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;

#if 0
    switch ((params & 0x70) >> 4) {
        case 0:
            cmdPos = read_vec3s(translation, &cmdPos[2]);
            cmdPos = read_vec3s_angle(rotation, cmdPos);
            break;
        case 1:
            cmdPos = read_vec3s(translation, &cmdPos[1]);
            vec3s_copy(rotation, gVec3sZero);
            break;
        case 2:
            cmdPos = read_vec3s_angle(rotation, &cmdPos[1]);
            vec3s_copy(translation, gVec3sZero);
            break;
        case 3:
            vec3s_copy(translation, gVec3sZero);
            vec3s_set(rotation, 0, (cmdPos[1] << 15) / 180, 0); // degrees
            cmdPos += 2 << CMD_SIZE_SHIFT;
            break;
    }
#else
    cmdPos = read_vec3s(translation, &cmdPos[2]);
    cmdPos = read_vec3s_angle(rotation, cmdPos);
#endif

    if (params & 0x80) {
        displayList = *(void **) &cmdPos[0];
        drawingLayer = params & 0x7F;
        cmdPos += 2 << CMD_SIZE_SHIFT;
    }

    graphNode = init_graph_node_translation_rotation(NULL, drawingLayer, devirt ? segmented_to_virtual(displayList) : displayList,
                                                     translation, rotation, style);
    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

void geo_layout_cmd_node_translation_rotation(void) {
    geo_layout_cmd_node_translation_rotation_impl(GRAPH_NODE_TYPE_TRANSLATION_ROTATION, 0);
}

void geo_layout_cmd_obj_node_translation_rotation(void) {
    geo_layout_cmd_node_translation_rotation_impl(GRAPH_NODE_TYPE_OBJ_TRANSLATION_ROTATION, 0);
}

void geo_layout_cmd_break_translation_rotation(void) {
    geo_layout_cmd_node_translation_rotation_impl(GRAPH_NODE_TYPE_BREAK_TRANSLATION_ROTATION, 0);
}

void geo_layout_cmd_batchset_node_translation_rotation(void) {
    struct GraphNodeBatchsetTranslationRotation *graphNode;

    Vec3s translation, rotation;

    void *displayList = NULL;
    s16 drawingLayer = LAYER_FIRST;

    s16 params = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;

    cmdPos = read_vec3s(translation, &cmdPos[2]);
    cmdPos = read_vec3s_angle(rotation, cmdPos);

    if (params & 0x80) {
        displayList = *(void **) &cmdPos[0];
        drawingLayer = params & 0x7F;
        cmdPos += 2 << CMD_SIZE_SHIFT;
    }

    graphNode = main_pool_alloc(sizeof(struct GraphNodeBatchsetTranslationRotation));
    init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_BATCHSET_TRANSLATION_ROTATION);

    vec3s_copy(graphNode->translation, translation);
    vec3s_copy(graphNode->rotation, rotation);
    SET_GRAPH_NODE_LAYER(graphNode->node.flags, drawingLayer);

    register_scene_graph_node(&graphNode->node);

    GRAPH_NODE_LVL_DL_ASSIGN(graphNode, segmented_to_virtual(displayList));

    gGeoLayoutCommand = (u8 *) cmdPos;
}

/*
  0x11: Create translation scene graph node with optional display list
   cmd+0x01: u8 params
     (params & 0x80): if set, enable displayList field and drawingLayer
     (params & 0x0F): drawingLayer
   cmd+0x02: s16 xTranslation
   cmd+0x04: s16 yTranslation
   cmd+0x06: s16 zTranslation
  [cmd+0x08: void *displayList]
*/
static void geo_layout_cmd_node_translation_impl(int style, int devirt) {
    struct GraphNodeTranslation *graphNode;

    Vec3s translation;

    s16 drawingLayer = LAYER_FIRST;
    s16 params = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    void *displayList = NULL;

    cmdPos = read_vec3s(translation, &cmdPos[1]);

    if (params & 0x80) {
        displayList = *(void **) &cmdPos[0];
        drawingLayer = params & 0x7F;
        cmdPos += 2 << CMD_SIZE_SHIFT;
    }

    graphNode =
        init_graph_node_translation(NULL, drawingLayer, devirt ? segmented_to_virtual(displayList) : displayList, translation, style);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

void geo_layout_cmd_node_translation(void) {
    geo_layout_cmd_node_translation_impl(GRAPH_NODE_TYPE_TRANSLATION, 0);
}

void geo_layout_cmd_obj_rocket_node_translation(void) {
    geo_layout_cmd_node_translation_impl(GRAPH_NODE_TYPE_OBJ_ROCKET_TRANSLATION, 0);
}

void geo_layout_cmd_obj_node_translation(void) {
    geo_layout_cmd_node_translation_impl(GRAPH_NODE_TYPE_OBJ_TRANSLATION, 0);
}

void geo_layout_cmd_batchset_node_translation(void) {
    struct GraphNodeBatchsetTranslation *graphNode;

    Vec3s translation;

    s16 drawingLayer = LAYER_FIRST;
    s16 params = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    void *displayList = NULL;

    cmdPos = read_vec3s(translation, &cmdPos[1]);

    if (params & 0x80) {
        displayList = *(void **) &cmdPos[0];
        drawingLayer = params & 0x7F;
        cmdPos += 2 << CMD_SIZE_SHIFT;
    }

    graphNode = main_pool_alloc(sizeof(struct GraphNodeBatchsetTranslation));
    init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_BATCHSET_TRANSLATION);

    vec3s_copy(graphNode->translation, translation);
    SET_GRAPH_NODE_LAYER(graphNode->node.flags, drawingLayer);

    register_scene_graph_node(&graphNode->node);

    GRAPH_NODE_LVL_DL_ASSIGN(graphNode, segmented_to_virtual(displayList));

    gGeoLayoutCommand = (u8 *) cmdPos;
}

/*
  0x12: Create ? scene graph node
   cmd+0x01: u8 params
     (params & 0x80): if set, enable displayList field and drawingLayer
     (params & 0x0F): drawingLayer
   cmd+0x02: s16 unkX
   cmd+0x04: s16 unkY
   cmd+0x06: s16 unkZ
  [cmd+0x08: void *displayList]
*/
void geo_layout_cmd_node_rotation(void) {
    struct GraphNodeRotation *graphNode;

    Vec3s angle;

    s16 drawingLayer = LAYER_FIRST;
    s16 params = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    void *displayList = NULL;

    cmdPos = read_vec3s_angle(angle, &cmdPos[1]);

    if (params & 0x80) {
        displayList = *(void **) &cmdPos[0];
        drawingLayer = params & 0x7F;
        cmdPos += 2 << CMD_SIZE_SHIFT;
    }

    graphNode = init_graph_node_rotation(NULL, drawingLayer, displayList, angle);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

/*
  0x1D: Create scale scene graph node with optional display list
   cmd+0x01: u8 params
     (params & 0x80): if set, enable displayList field and drawingLayer
     (params & 0x0F): drawingLayer
   cmd+0x04: u32 scale (0x10000 = 1.0)
  [cmd+0x08: void *displayList]
*/
void geo_layout_cmd_node_scale(void) {
    struct GraphNodeScale *graphNode;

    s16 drawingLayer = LAYER_FIRST;
    s16 params = cur_geo_cmd_u8(0x01);
    f32 scale = cur_geo_cmd_u32(0x04) / 65536.0f;
    void *displayList = NULL;

    if (params & 0x80) {
        displayList = cur_geo_cmd_ptr(0x08);
        drawingLayer = params & 0x7F;
        gGeoLayoutCommand += 4 << CMD_SIZE_SHIFT;
    }

    graphNode = init_graph_node_scale(NULL, drawingLayer, displayList, scale);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

// 0x1E: No operation
void geo_layout_cmd_nop2(void) {
    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

/*
  0x13: Create a scene graph node that is rotated by the object's animation.
   cmd+0x01: u8 drawingLayer
   cmd+0x02: s16 xTranslation
   cmd+0x04: s16 yTranslation
   cmd+0x06: s16 zTranslation
   cmd+0x08: void *displayList
*/
void geo_layout_cmd_node_animated_part(void) {
    struct GraphNodeAnimatedPart *graphNode;
    Vec3s translation;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    void *displayList = cur_geo_cmd_ptr(0x08);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;

    read_vec3s(translation, &cmdPos[1]);

    graphNode =
        init_graph_node_animated_part(NULL, drawingLayer, displayList, translation);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x0C << CMD_SIZE_SHIFT;
}

/*
  0x14: Create billboarding node with optional display list
   cmd+0x01: u8 params
     (params & 0x80): if set, enable displayList field and drawingLayer
     (params & 0x0F): drawingLayer
   cmd+0x02: s16 xTranslation
   cmd+0x04: s16 yTranslation
   cmd+0x06: s16 zTranslation
  [cmd+0x08: void *displayList]
*/
void geo_layout_cmd_node_billboard(void) {
    struct GraphNodeBillboard *graphNode;
    Vec3s translation;
    s16 drawingLayer = LAYER_FIRST;
    s16 params = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    void *displayList = NULL;

    cmdPos = read_vec3s(translation, &cmdPos[1]);

    if (params & 0x80) {
        displayList = *(void **) &cmdPos[0];
        drawingLayer = params & 0x7F;
        cmdPos += 2 << CMD_SIZE_SHIFT;
    }

    graphNode = init_graph_node_billboard(NULL, drawingLayer, displayList, translation);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

/*
  0x15: Create plain display list scene graph node
   cmd+0x01: u8 drawingLayer
   cmd+0x04: void *displayList
*/
static void geo_layout_cmd_node_display_list_impl(int style, int devirt) {
    struct GraphNodeDisplayList *graphNode;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    void *displayList = cur_geo_cmd_ptr(0x04);

    graphNode = init_graph_node_display_list(NULL, drawingLayer, devirt ? segmented_to_virtual(displayList) : displayList, style);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

void geo_layout_cmd_node_display_list(void) {
    return geo_layout_cmd_node_display_list_impl(GRAPH_NODE_TYPE_DISPLAY_LIST, 0);
}

void geo_layout_cmd_node_batch_display_list(void) {
    struct GraphNodeBatchDisplayList *graphNode;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    s16 batch = cur_geo_cmd_s16(0x02);
    void *displayList = cur_geo_cmd_ptr(0x04);

    graphNode = init_graph_node_batch_display_list(NULL, drawingLayer, displayList, batch);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

void geo_layout_cmd_node_batch_display_list_anim(void) {
    struct GraphNodeBatchAnimDisplayList *graphNode;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    s16 batch = cur_geo_cmd_s16(0x02);
    void *displayList = cur_geo_cmd_ptr(0x04);
    int animLimit = cur_geo_cmd_s32(0x08);

    graphNode = init_graph_node_batch_display_list_anim(NULL, drawingLayer, displayList, batch, animLimit);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x0C << CMD_SIZE_SHIFT;
}

static int dropped_for_console(void* dl, s32 layer);
void geo_layout_cmd_batchset_node(void) {
    struct GraphNode *graphNode;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    void *displayList = cur_geo_cmd_ptr(0x04);
    if (dropped_for_console(displayList, drawingLayer))
        goto fini;

    graphNode = main_pool_alloc(sizeof(struct GraphNode));
    init_scene_graph_node_links(graphNode, GRAPH_NODE_TYPE_BATCHSET);
    SET_GRAPH_NODE_LAYER(graphNode->flags, drawingLayer);

    register_scene_graph_node(graphNode);

    GRAPH_NODE_LVL_DL_ASSIGN_RAW(graphNode,  segmented_to_virtual(displayList));

fini:
    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

/*
  0x16: Create shadow scene graph node
   cmd+0x02: s16 shadowType
   cmd+0x04: s16 shadowSolidity
   cmd+0x06: s16 shadowScale
*/
void geo_layout_cmd_node_shadow(void) {
    struct GraphNodeShadow *graphNode;
    u8 shadowType = cur_geo_cmd_s16(0x02);
    u8 shadowSolidity = cur_geo_cmd_s16(0x04);
    s16 shadowScale = cur_geo_cmd_s16(0x06);

    graphNode = init_graph_node_shadow(NULL, shadowScale, shadowSolidity, shadowType);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

// 0x17: Create scene graph node that manages the group of all object nodes
void geo_layout_cmd_node_object_parent(void) {
    struct GraphNodeObjectParent *graphNode = init_graph_node_object_parent(NULL, &gObjParentGraphNode);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

/*
  0x18: Create dynamically generated displaylist scene graph node
   cmd+0x02: s16 parameter
   cmd+0x04: GraphNodeFunc func
*/
void geo_layout_cmd_node_generated(void) {
    struct GraphNodeGenerated *graphNode =
        init_graph_node_generated(NULL,
                                  (GraphNodeFunc) cur_geo_cmd_ptr(0x04), // asm function
                                  cur_geo_cmd_s16(0x02));                // parameter

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

void geo_layout_cmd_node_batch_generated(void) {
    struct GraphNodeBatchGenerated *graphNode =
        init_graph_node_batch_generated(NULL,
                                        (GraphNodeFunc) cur_geo_cmd_ptr(0x04), // asm function
                                        cur_geo_cmd_s16(0x02));

    register_scene_graph_node(&graphNode->genNode.fnNode.node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

/*
  0x19: Create background scene graph node
   cmd+0x02: s16 background // background ID, or RGBA5551 color if backgroundFunc is null
   cmd+0x04: GraphNodeFunc backgroundFunc
*/
void geo_layout_cmd_node_background(void) {
    struct GraphNodeBackground *graphNode = init_graph_node_background(
        NULL,
        cur_geo_cmd_s16(0x02), // background ID, or RGBA5551 color if asm function is null
        (GraphNodeFunc) cur_geo_cmd_ptr(0x04), // asm function
        0);

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

// 0x1A: No operation
void geo_layout_cmd_nop(void) {
    gGeoLayoutCommand += 0x08 << CMD_SIZE_SHIFT;
}

/*
  0x1B: Copy the shared children from the object parent from a specific view
  to a newly created object parent node.
   cmd+0x02: s16 index (of gGeoViews)
*/
void geo_layout_cmd_copy_view(void) {
    struct GraphNodeObjectParent *graphNode;
    struct GraphNode *node = NULL;
    s16 index = cur_geo_cmd_s16(0x02);

    if (index >= 0) {
        node = gGeoViews[index];

        if (node->type == GRAPH_NODE_TYPE_OBJECT_PARENT) {
            node = ((struct GraphNodeObjectParent *) node)->sharedChild;
        } else {
            node = NULL;
        }
    }

    graphNode = init_graph_node_object_parent(NULL, node);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

/*
  0x1C: Create a held object scene graph node
   cmd+0x01: u8 unused
   cmd+0x02: s16 offsetX
   cmd+0x04: s16 offsetY
   cmd+0x06: s16 offsetZ
   cmd+0x08: GraphNodeFunc nodeFunc
*/
void geo_layout_cmd_node_held_obj(void) {
    struct GraphNodeHeldObject *graphNode;
    Vec3s offset;

    read_vec3s(offset, (s16 *) &gGeoLayoutCommand[0x02]);

    graphNode = init_graph_node_held_object(
        NULL, NULL, offset, (GraphNodeFunc) cur_geo_cmd_ptr(0x08), cur_geo_cmd_u8(0x01));

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoLayoutCommand += 0x0C << CMD_SIZE_SHIFT;
}

/*
  0x20: Create a scene graph node that specifies for an object the radius that
   is used for frustum culling.
   cmd+0x02: s16 cullingRadius
*/
void geo_layout_cmd_node_culling_radius(void) {
    struct GraphNodeCullingRadius *graphNode = init_graph_node_culling_radius(NULL, cur_geo_cmd_s16(0x02));
    register_scene_graph_node(&graphNode->node);
    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

#define next_s32_in_geo_script(src) (*(*src)++)

extern u32 ce_dl_1848_object_00D228F4_mesh_layer_1[];
extern u32 ce_dl_1139_object_00D2AED4_mesh_layer_1[];
extern u32 ce_dl_2309_object_00C55280_mesh_layer_1[];
extern u32 ce_dl_0083_object_00D383E4_mesh_layer_1[];
extern u32 ce_dl_0530_object_00D3236C_mesh_layer_1[];
extern u32 ce_dl_0463_object_00D331DC_mesh_layer_1[];
extern u32 ce_dl_0236_object_00CF0DD4_mesh_layer_1[];
extern u32 ce_dl_0211_object_00D3681C_mesh_layer_1[];
extern u32 ce_dl_0208_object_00D368C4_mesh_layer_1[];
extern u32 ce_dl_0058_object_00D3895C_mesh_layer_1[];

static const u32* kCEBannedDls[] = {
    ce_dl_0530_object_00D3236C_mesh_layer_1,
    ce_dl_0463_object_00D331DC_mesh_layer_1,
    ce_dl_0236_object_00CF0DD4_mesh_layer_1,
    ce_dl_0211_object_00D3681C_mesh_layer_1,
    ce_dl_0208_object_00D368C4_mesh_layer_1,
    ce_dl_0058_object_00D3895C_mesh_layer_1,
    ce_dl_1848_object_00D228F4_mesh_layer_1,
    ce_dl_2309_object_00C55280_mesh_layer_1,
    ce_dl_0083_object_00D383E4_mesh_layer_1,
    ce_dl_1139_object_00D2AED4_mesh_layer_1,
};

extern u32 dc_dl_object_007AF9CC_mesh_layer_1[];
extern u32 dc_dl_object_007AE93C_mesh_layer_1[];
extern u32 dc_dl_0273_object_0104E10C_mesh_layer_1[];

static int dropped_for_console(void* dl, s32 layer)
{
    if (!gIsConsole)
        return 0;

    if (gCurrCourseNum == COURSE_CE)
    {
        if (LAYER_OPAQUE_DECAL == layer || LAYER_TRANSPARENT == layer)
            return 1;

        for (int i = 0; i < ARRAY_COUNT(kCEBannedDls); i++)
        {
            if (dl == kCEBannedDls[i])
                return 1;
        }

        return 0;
    }
    if (gCurrCourseNum == COURSE_DC)
    {
        if (dl == dc_dl_object_007AF9CC_mesh_layer_1)
            return 1;
        if (dl == dc_dl_object_007AE93C_mesh_layer_1)
            return 1;
        if (dl == dc_dl_0273_object_0104E10C_mesh_layer_1)
            return 1;
    }

    return 0;
}

void geo_layout_cmd_lvl_translation_rotation(void) {
    struct GraphNodeLvlTranslationRotation *graphNode;

    Vec3s rotation;
    Vec3f translation;

    void *displayList = NULL;
    s16 drawingLayer = LAYER_FIRST;

    s16 params = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    cmdPos += 1;
    rotation[0] = next_s32_in_geo_script(&cmdPos);
    rotation[1] = next_s32_in_geo_script(&cmdPos);
    rotation[2] = next_s32_in_geo_script(&cmdPos);
    s32* cmdPos_f = (s32*)cmdPos;
    translation[0] = GEO_INT_TO_FLOAT(next_s32_in_geo_script(&cmdPos_f));
    translation[1] = GEO_INT_TO_FLOAT(next_s32_in_geo_script(&cmdPos_f));
    translation[2] = GEO_INT_TO_FLOAT(next_s32_in_geo_script(&cmdPos_f));
    cmdPos = (s16*)cmdPos_f;
    drawingLayer = params & 0x7F;
    if (!(params & 0x80))
    {
        displayList = *(void **) &cmdPos[0];
        cmdPos += 2 << CMD_SIZE_SHIFT;
    }

    graphNode = init_graph_node_lvl_translation_rotation(NULL, drawingLayer, translation, rotation);
    register_scene_graph_node(&graphNode->node);

    if (!dropped_for_console(displayList, drawingLayer))
        GRAPH_NODE_LVL_DL_ASSIGN(graphNode, segmented_to_virtual(displayList));
    else
        GRAPH_NODE_LVL_DL_ASSIGN(graphNode, NULL);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

void geo_layout_cmd_lvl_translation(void) {
    struct GraphNodeLvlTranslation *graphNode;

    Vec3f translation;

    s16 drawingLayer = LAYER_FIRST;
    s16 params = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    void *displayList = NULL;

    cmdPos += 2;
    s32* cmdPos_f = (s32*)cmdPos;
    translation[0] = GEO_INT_TO_FLOAT(next_s32_in_geo_script(&cmdPos_f));
    translation[1] = GEO_INT_TO_FLOAT(next_s32_in_geo_script(&cmdPos_f));
    translation[2] = GEO_INT_TO_FLOAT(next_s32_in_geo_script(&cmdPos_f));
    cmdPos = (s16*)cmdPos_f;
    drawingLayer = params & 0x7F;
    if (params & 0x80)
    {
        displayList = *(void **) &cmdPos[0];
        cmdPos += 2 << CMD_SIZE_SHIFT;
    }

    graphNode = init_graph_node_lvl_translation(NULL, drawingLayer, translation);

    register_scene_graph_node(&graphNode->node);

    if (!dropped_for_console(displayList, drawingLayer))
        GRAPH_NODE_LVL_DL_ASSIGN(graphNode, segmented_to_virtual(displayList));
    else
        GRAPH_NODE_LVL_DL_ASSIGN(graphNode, NULL);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

void geo_layout_cmd_break_translation(void) {
    struct GraphNodeTranslation *graphNode;

    Vec3s translation;

    s16 drawingLayer = LAYER_FIRST;
    s16 params = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    void *displayList = NULL;

    cmdPos = read_vec3s(translation, &cmdPos[1]);
    displayList = *(void **) &cmdPos[0];
    drawingLayer = params & 0x7F;
    cmdPos += 2 << CMD_SIZE_SHIFT;

    graphNode =
        init_graph_node_break_translation(NULL, drawingLayer, displayList, translation);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

struct GraphNode *process_geo_layout(void *segptr) {
    // set by register_scene_graph_node when gCurGraphNodeIndex is 0
    // and gCurRootGraphNode is NULL
    gCurRootGraphNode = NULL;

    gGeoNumViews = 0; // number of entries in gGeoViews

    gCurGraphNodeList[0] = 0;
    gCurGraphNodeIndex = 0; // incremented by cmd_open_node, decremented by cmd_close_node

    gGeoLayoutStackIndex = 2;
    gGeoLayoutReturnIndex = 2; // stack index is often copied here?

    gGeoLayoutCommand = segmented_to_virtual(segptr);

    gGeoLayoutStack[0] = 0;
    gGeoLayoutStack[1] = 0;

    while (gGeoLayoutCommand != NULL) {
        assert((gGeoLayoutCommand[0x00] < GEO_CMD_COUNT), "Invalid or unloaded geo layout detected.");
        GeoLayoutJumpTable[gGeoLayoutCommand[0x00]]();
    }

    return gCurRootGraphNode;
}
