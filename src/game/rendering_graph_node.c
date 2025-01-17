#include <PR/ultratypes.h>

#include "area.h"
#include "engine/math_util.h"
#include "game_init.h"
#include "gfx_dimensions.h"
#include "main.h"
#include "memory.h"
#include "print.h"
#include "rendering_graph_node.h"
#include "shadow.h"
#include "sm64.h"
#include "game_init.h"
#include "puppyprint.h"
#include "debug_box.h"
#include "level_update.h"
#include "behavior_data.h"
#include "string.h"
#include "color_presets.h"
#include "emutest.h"
#include "flipbook.h"
#include "game/tile_scroll.h"

#include "config.h"
#include "config/config_world.h"
#include "actors/common1.h"

/**
 * This file contains the code that processes the scene graph for rendering.
 * The scene graph is responsible for drawing everything except the HUD / text boxes.
 * First the root of the scene graph is processed when geo_process_root
 * is called from level_script.c. The rest of the tree is traversed recursively
 * using the function geo_process_node_and_siblings, which switches over all
 * geo node types and calls a specialized function accordingly.
 * The types are defined in engine/graph_node.h
 *
 * The scene graph typically looks like:
 * - Root (viewport)
 *  - Master list
 *   - Ortho projection
 *    - Background (skybox)
 *  - Master list
 *   - Perspective
 *    - Camera
 *     - <area-specific display lists>
 *     - Object parent
 *      - <group with 240 object nodes>
 *  - Master list
 *   - Script node (Cannon overlay)
 *
 */

s16 gMatStackIndex = 0;
ALIGNED16 Mat4 gMatStack[32];
ALIGNED16 Mtx *gMatStackFixed[32];
f32 sAspectRatio;

/**
 * Animation nodes have state in global variables, so this struct captures
 * the animation state so a 'context switch' can be made when rendering the
 * held object.
 */
struct GeoAnimState {
    /*0x00*/ u8 type;
    /*0x01*/ u8 enabled;
    /*0x02*/ s16 frame;
    /*0x04*/ f32 translationMultiplier;
    /*0x08*/ u16 *attribute;
    /*0x0C*/ s16 *data;
};

// For some reason, this is a GeoAnimState struct, but the current state consists
// of separate global variables. It won't match EU otherwise.
struct GeoAnimState gGeoTempState;

u8 gCurrAnimType;
u8 gCurrAnimEnabled;
s16 gCurrAnimFrame;
f32 gCurrAnimTranslationMultiplier;
u16 *gCurrAnimAttribute;
s16 *gCurrAnimData;

/* Rendermode settings for cycle 1 for all 8 or 13 layers. */
static const struct RenderModeContainer renderModeTable_1Cycle[2] = { 
    [RENDER_NO_ZB] = { {
        [LAYER_FORCE] = G_RM_OPA_SURF,
        [LAYER_OPAQUE] = G_RM_AA_OPA_SURF,
        [LAYER_OPAQUE_INTER] = G_RM_AA_OPA_SURF,
        [LAYER_OPAQUE_DECAL] = G_RM_AA_OPA_SURF,
        [LAYER_ALPHA] = G_RM_AA_TEX_EDGE,
#if SILHOUETTE
        [LAYER_ALPHA_DECAL] = G_RM_AA_TEX_EDGE | ZMODE_DEC,
        [LAYER_SILHOUETTE_OPAQUE] = G_RM_AA_OPA_SURF,
        [LAYER_SILHOUETTE_ALPHA] = G_RM_AA_TEX_EDGE,
        [LAYER_OCCLUDE_SILHOUETTE_OPAQUE] = G_RM_AA_OPA_SURF,
        [LAYER_OCCLUDE_SILHOUETTE_ALPHA] = G_RM_AA_TEX_EDGE,
#endif
        [LAYER_CLD] = G_RM_CLD_SURF,
        [LAYER_TRANSPARENT_DECAL] = G_RM_AA_XLU_SURF,
        [LAYER_TRANSPARENT] = G_RM_AA_XLU_SURF,
        [LAYER_TRANSPARENT_INTER] = G_RM_AA_XLU_SURF,
    } },
    [RENDER_ZB] = { {
        [LAYER_FORCE] = G_RM_ZB_OPA_SURF,
        [LAYER_OPAQUE] = G_RM_AA_ZB_OPA_SURF,
        [LAYER_OPAQUE_INTER] = G_RM_AA_ZB_OPA_INTER,
        [LAYER_OPAQUE_DECAL] = G_RM_AA_ZB_OPA_DECAL,
        [LAYER_ALPHA] = G_RM_AA_ZB_TEX_EDGE,
#if SILHOUETTE
        [LAYER_ALPHA_DECAL] = G_RM_AA_ZB_TEX_EDGE | ZMODE_DEC,
        [LAYER_SILHOUETTE_OPAQUE] = G_RM_AA_ZB_OPA_SURF,
        [LAYER_SILHOUETTE_ALPHA] = G_RM_AA_ZB_TEX_EDGE,
        [LAYER_OCCLUDE_SILHOUETTE_OPAQUE] = G_RM_AA_ZB_OPA_SURF,
        [LAYER_OCCLUDE_SILHOUETTE_ALPHA] = G_RM_AA_ZB_TEX_EDGE,
#endif
        [LAYER_CLD] = G_RM_ZB_CLD_SURF,
        [LAYER_TRANSPARENT_DECAL] = G_RM_AA_ZB_XLU_DECAL,
        [LAYER_TRANSPARENT] = G_RM_AA_ZB_XLU_SURF,
        [LAYER_TRANSPARENT_INTER] = G_RM_AA_ZB_XLU_INTER,
    } } };

/* Rendermode settings for cycle 2 for all 13 layers. */
static const struct RenderModeContainer renderModeTable_2Cycle[2] = {
    [RENDER_NO_ZB] = { {
        [LAYER_FORCE] = G_RM_OPA_SURF2,
        [LAYER_OPAQUE] = G_RM_AA_OPA_SURF2,
        [LAYER_OPAQUE_INTER] = G_RM_AA_OPA_SURF2,
        [LAYER_OPAQUE_DECAL] = G_RM_AA_OPA_SURF2,
        [LAYER_ALPHA] = G_RM_AA_TEX_EDGE2,
#if SILHOUETTE
        [LAYER_ALPHA_DECAL] = G_RM_AA_TEX_EDGE2 | ZMODE_DEC,
        [LAYER_SILHOUETTE_OPAQUE] = G_RM_AA_OPA_SURF2,
        [LAYER_SILHOUETTE_ALPHA] = G_RM_AA_TEX_EDGE2,
        [LAYER_OCCLUDE_SILHOUETTE_OPAQUE] = G_RM_AA_OPA_SURF2,
        [LAYER_OCCLUDE_SILHOUETTE_ALPHA] = G_RM_AA_TEX_EDGE2,
#endif
        [LAYER_CLD] = G_RM_CLD_SURF2,
        [LAYER_TRANSPARENT_DECAL] = G_RM_AA_XLU_SURF2,
        [LAYER_TRANSPARENT] = G_RM_AA_XLU_SURF2,
        [LAYER_TRANSPARENT_INTER] = G_RM_AA_XLU_SURF2,
    } },
    [RENDER_ZB] = { {
        [LAYER_FORCE] = G_RM_ZB_OPA_SURF2,
        [LAYER_OPAQUE] = G_RM_AA_ZB_OPA_SURF2,
        [LAYER_OPAQUE_INTER] = G_RM_AA_ZB_OPA_INTER2,
        [LAYER_OPAQUE_DECAL] = G_RM_AA_ZB_OPA_DECAL2,
        [LAYER_ALPHA] = G_RM_AA_ZB_TEX_EDGE2,
#if SILHOUETTE
        [LAYER_ALPHA_DECAL] = G_RM_AA_ZB_TEX_EDGE2 | ZMODE_DEC,
        [LAYER_SILHOUETTE_OPAQUE] = G_RM_AA_ZB_OPA_SURF2,
        [LAYER_SILHOUETTE_ALPHA] = G_RM_AA_ZB_TEX_EDGE2,
        [LAYER_OCCLUDE_SILHOUETTE_OPAQUE] = G_RM_AA_ZB_OPA_SURF2,
        [LAYER_OCCLUDE_SILHOUETTE_ALPHA] = G_RM_AA_ZB_TEX_EDGE2,
#endif
        [LAYER_CLD] = G_RM_ZB_CLD_SURF2,
        [LAYER_TRANSPARENT_DECAL] = G_RM_AA_ZB_XLU_DECAL2,
        [LAYER_TRANSPARENT] = G_RM_AA_ZB_XLU_SURF2,
        [LAYER_TRANSPARENT_INTER] = G_RM_AA_ZB_XLU_INTER2,
    } } };

ALIGNED16 struct GraphNodeRoot *gCurGraphNodeRoot = NULL;
ALIGNED16 struct GraphNodeMasterList *gCurGraphNodeMasterList = NULL;
ALIGNED16 struct GraphNodePerspective *gCurGraphNodeCamFrustum = NULL;
ALIGNED16 struct GraphNodeCamera *gCurGraphNodeCamera = NULL;
ALIGNED16 struct GraphNodeObject *gCurGraphNodeObject = NULL;
ALIGNED16 struct GraphNodeHeldObject *gCurGraphNodeHeldObject = NULL;
u16 gAreaUpdateCounter = 0;
static LookAt* gCurLookAt;

#if SILHOUETTE
// AA_EN        Enable anti aliasing (not actually used for AA in this case).
// IM_RD        Enable reading coverage value.
// CLR_ON_CVG   Don't change the color unless coverage overflows. This helps prevent triangle overlap.
// CVG_DST_WRAP Wrap the coverage value on overflow.
// CVG_X_ALPHA  Coverage and alpha will be multiplied and both will be the same. This makes texture alpha work (eg. Wing Cap wings).
// FORCE_BL     Force Blending.
#define SIL_CVG_THRESHOLD    0x3F // 32..255, 63 seems to give best results
#define SCHWA (AA_EN | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | CVG_X_ALPHA | FORCE_BL)
static const Gfx dl_silhouette_begin[] = {
    gsDPPipeSync(),
    // Set the render mode for the silhouette so that it gets its color and alpha from the fog register.
    gsDPSetRenderMode((SCHWA | GBL_c1(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1MA)),
                      (SCHWA | GBL_c2(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1MA))),
    // Set the silhouette's color & alpha.
    gsDPSetFogColor(0, 0, 0, SILHOUETTE),
    // Hacky way to prevent triangle overlap. 32..255. 63 seems to give best results.
    gsDPSetEnvColor(0, 0, 0, 0x3F),
    gsSPEndDisplayList(),
};

static const Gfx dl_silhouette_end[] = {
    gsDPPipeSync(),
    gsDPSetFogColor(  0,   0,   0, 255), // Reset fog color & alpha
    gsDPSetEnvColor(255, 255, 255, 255), // Reset env color & alpha
    gsSPEndDisplayList(),
};
#undef SCHWA
#endif

struct RenderPhase {
    u8 startLayer;
    u8 endLayer;
};

static const struct RenderPhase sRenderPhases[] = {
#if SILHOUETTE
    [RENDER_PHASE_ZEX_BEFORE_SILHOUETTE]   = {
        .startLayer = LAYER_FIRST,
        .endLayer   = LAYER_LAST_BEFORE_SILHOUETTE,
    },

    [RENDER_PHASE_ZEX_SILHOUETTE]          = {
        .startLayer = LAYER_SILHOUETTE_FIRST,
        .endLayer   = LAYER_SILHOUETTE_LAST,
    },

    [RENDER_PHASE_ZEX_NON_SILHOUETTE]      = {
        .startLayer = LAYER_SILHOUETTE_FIRST,
        .endLayer   = LAYER_SILHOUETTE_LAST,
    },

    [RENDER_PHASE_ZEX_OCCLUDE_SILHOUETTE]  = {
        .startLayer = LAYER_OCCLUDE_SILHOUETTE_FIRST,
        .endLayer   = LAYER_OCCLUDE_SILHOUETTE_LAST,
    },

    [RENDER_PHASE_ZEX_AFTER_SILHOUETTE]    = {
        .startLayer = LAYER_NON_ZB_FIRST,
        .endLayer   = LAYER_LAST,
    },
#else
    [RENDER_PHASE_ZEX_ALL]                 = {
        .startLayer = LAYER_FIRST,
        .endLayer   = LAYER_LAST,
    },
#endif
};

extern const Gfx init_rsp[];

#define UPPER_FIXED(x) ((int)((unsigned int)((x) * 0x10000) >> 16))
#define LOWER_FIXED(x) ((int)((unsigned int)((x) * 0x10000) & 0xFFFF))

// Fixed-point identity matrix with the inverse of world scale
static const Mtx identityMatrixWorldScale = {{
    {UPPER_FIXED(1.0f / WORLD_SCALE) << 16, 0x00000000,
     UPPER_FIXED(1.0f / WORLD_SCALE) <<  0, 0x00000000},
    {0x00000000,                            UPPER_FIXED(1.0f / WORLD_SCALE) << 16,
     0x00000000,                            UPPER_FIXED(1.0f)               <<  0},
    {LOWER_FIXED(1.0f / WORLD_SCALE) << 16, 0x00000000,
     LOWER_FIXED(1.0f / WORLD_SCALE) <<  0, 0x00000000},
    {0x00000000,                            LOWER_FIXED(1.0f / WORLD_SCALE) << 16,
     0x00000000,                            LOWER_FIXED(1.0f)               <<  0}
}};

/**
 * Process a master list node. This has been modified, so now it runs twice, for each microcode.
 * It iterates through the first 5 layers of if the first index using F3DLX2.Rej, then it switches
 * to F3DZEX and iterates through all layers, then switches back to F3DLX2.Rej and finishes the last
 * 3. It does this, because layers 5-7 are non zbuffered, and just doing 0-7 of ZEX, then 0-7 of REJ
 * would make the ZEX 0-4 render on top of Rej's 5-7.
 */

static ALWAYS_INLINE void render_lists(Gfx **ptempGfxHead, Mtx **pprevMtx, struct DisplayListNode* currList)
{
#define tempGfxHead (*ptempGfxHead)
#define prevMtx (*pprevMtx)
    do {
        if (prevMtx != currList->transform)
        {
            gSPMatrix(tempGfxHead++, VIRTUAL_TO_PHYSICAL(currList->transform), (G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH));
            prevMtx = currList->transform;
        }
        gSPDisplayList(tempGfxHead++, currList->displayList);
        currList = currList->next;
    } while (currList != NULL);
#undef prevMtx
#undef tempGfxHead
}

extern const Gfx dl_course_common_revert[];
static int render_batches(Gfx **ptempGfxHead, struct BatchArray* arr, u32 wantMode1, u32 wantMode2, int course)
{
#define tempGfxHead (*ptempGfxHead)
    int amountRendered = 0;
    if (!arr)
        return 0;

    Mtx* prevMtx = NULL;
    // Some "fun" display lists before may decide to change the render mode, so we need to reset it.
    gDPSetRenderMode(tempGfxHead++, wantMode1, wantMode2);

    for (int batch = 0; batch < arr->count; batch++) {
        struct DisplayListLinks* batchLinks = &arr->batches[batch];
        if (!batchLinks->head)
            continue;

        const struct BatchDisplayLists* batchDisplayLists = &arr->batchDLs[batch];
        gSPDisplayList(tempGfxHead++, batchDisplayLists->startDl);
        amountRendered++;
        render_lists(&tempGfxHead, &prevMtx, batchLinks->head);
        gSPDisplayList(tempGfxHead++, batchDisplayLists->endDl);

        if (course) {
            gSPDisplayList(tempGfxHead++, dl_course_common_revert);
        }
    }
#undef tempGfxHead

    return amountRendered;
}

static void apply_flipbooks(struct MasterLayer* masterLayer)
{
    struct FlipbookArray* flipbooks = masterLayer->flipbooks;
    if (!flipbooks)
        return;

    for (int i = 0; i < flipbooks->count; i++)
    {
        const struct FlipbookData* flipData = &flipbooks->data[i];
        struct FlipbookDls* flipDls = &flipbooks->dls[i];

        // switch dl frames and patch the display list
        int frame = (gGlobalTimer / flipData->frames) % flipData->count;
        u8* startDl = (u8*) flipDls->startDls[gGlobalTimer & 1];
        *(u8**) &startDl[flipDls->offCI4] = flipData->ci4s + frame * 2048;
        *(u8**) &startDl[flipDls->offPal] = flipData->pals + frame * 32;

        SetTileSize* tile = (SetTileSize*) &startDl[flipDls->offTile];
        // tile->u += gGlobalTimer * flipData->tileScrollX;
        // tile->v += gGlobalTimer * flipData->tileScrollY;
        tile->t = gGlobalTimer * flipData->tileScrollX;
        tile->s = gGlobalTimer * flipData->tileScrollY;

        // this bending constness rules a bit but trust me, it's fine
        struct BatchDisplayLists* batchDLs = (struct BatchDisplayLists*) masterLayer->course->batchDLs;
        batchDLs[flipData->batchId].startDl = VIRTUAL_TO_PHYSICAL(startDl);

        return;
    }
}

static void adjust_view_range();
void geo_process_master_list_sub(struct GraphNodeMasterList *node) {
    const struct RenderPhase *renderPhase;
    s32 currLayer     = LAYER_FIRST;
    s32 startLayer    = LAYER_FIRST;
    s32 endLayer      = LAYER_LAST;
    s32 phaseIndex    = RENDER_PHASE_FIRST;
    s32 enableZBuffer = (node->node.flags & GRAPH_RENDER_Z_BUFFER) != 0;
    s32 finalPhase    = enableZBuffer ? RENDER_PHASE_END : 1;
    const struct RenderModeContainer *mode1List = &renderModeTable_1Cycle[enableZBuffer];
    const struct RenderModeContainer *mode2List = &renderModeTable_2Cycle[enableZBuffer];
    Gfx *tempGfxHead = gDisplayListHead;

    adjust_view_range();

    // Loop through the render phases
    for (phaseIndex = RENDER_PHASE_FIRST; phaseIndex < finalPhase; phaseIndex++) {
        if (enableZBuffer) {
            // Get the render phase information.
            renderPhase = &sRenderPhases[phaseIndex];
            startLayer  = renderPhase->startLayer;
            endLayer    = renderPhase->endLayer;
            // Enable z buffer.
            gDPPipeSync(tempGfxHead++);
            gSPSetGeometryMode(tempGfxHead++, G_ZBUFFER);
        } else {
            startLayer = LAYER_FORCE;
            endLayer = LAYER_TRANSPARENT;
        }
        // Iterate through the layers on the current render phase.
        for (currLayer = startLayer; currLayer <= endLayer; currLayer++) {
            // Set 'currList' to the first DisplayListNode on the current layer.
            struct MasterLayer* masterLayer = &node->layers[currLayer];
            apply_flipbooks(masterLayer);
            struct DisplayListNode *currList = masterLayer->list.head;
            u32 wantMode1 = mode1List->modes[currLayer];
            u32 wantMode2 = mode2List->modes[currLayer];
            if (currList)
            {
                // Set the render mode for the current layer.
    #if defined(DISABLE_AA) || !SILHOUETTE
                // - do nothing...
    #else
                if (phaseIndex == RENDER_PHASE_NON_SILHOUETTE) {
                    wantMode1 &= ~IM_RD;
                    wantMode2 &= ~IM_RD;
                }
    #endif
                gDPSetRenderMode(tempGfxHead++, wantMode1, wantMode2);

                // Iterate through all the displaylists on the current layer.
                do {
                    // Add the display list's transformation to the master list.
                    gSPMatrix(tempGfxHead++, VIRTUAL_TO_PHYSICAL(currList->transform),
                            (G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH));
    #if SILHOUETTE
                    if (phaseIndex == RENDER_PHASE_SILHOUETTE) {
                        // Add the current display list to the master list, with silhouette F3D.
                        gSPDisplayList(tempGfxHead++, dl_silhouette_begin);
                        gSPDisplayList(tempGfxHead++, currList->displayList);
                        gSPDisplayList(tempGfxHead++, dl_silhouette_end);
                    } else {
                        // Add the current display list to the master list.
                        gSPDisplayList(tempGfxHead++, currList->displayList);
                    }
    #else
                    // Add the current display list to the master list.
                    gSPDisplayList(tempGfxHead++, currList->displayList);
    #endif
                    // Move to the next DisplayListNode.
                    currList = currList->next;
                }
                while (currList != NULL);
            }

            int amt = render_batches(&tempGfxHead, masterLayer->course, wantMode1, wantMode2, 1);
            // if (amt)
            //     print_text_fmt_int(20, 20 + currLayer * 20, "%d", amt);
            render_batches(&tempGfxHead, masterLayer->objects, wantMode1, wantMode2, 0);
        }
    }

    if (enableZBuffer) {
        // Disable z buffer.
        gDPPipeSync(tempGfxHead++);
        gSPClearGeometryMode(tempGfxHead++, G_ZBUFFER);
#ifdef VISUAL_DEBUG
        // Load the world scale identity matrix
        gSPMatrix(tempGfxHead++, &identityMatrixWorldScale, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        if (surfaceView) visual_surface_loop(&tempGfxHead);
        render_debug_boxes(&tempGfxHead);
#endif
    }

    gDisplayListHead = tempGfxHead;
}

static void append_dl(struct DisplayListLinks* list, void* dl)
{
    struct DisplayListNode *listNode = main_pool_alloc(sizeof(struct DisplayListNode));

    listNode->transform = gMatStackFixed[gMatStackIndex];
    listNode->displayList = dl;
    listNode->next = NULL;
    if (list->head == NULL) {
        list->head = listNode;
    } else {
        list->tail->next = listNode;
    }
    list->tail = listNode;
}

/**
 * Appends the display list to one of the master lists based on the layer
 * parameter. Look at the RenderModeContainer struct to see the corresponding
 * render modes of layers.
 */
void geo_append_display_list(void *displayList, s32 layer) {
#ifdef F3DEX_GBI_2
    // gSPLookAt(gDisplayListHead++, gCurLookAt);
#endif
#if SILHOUETTE
    if (gCurGraphNodeObject != NULL) {
        if (gCurGraphNodeObject->node.flags & GRAPH_RENDER_SILHOUETTE) {
            switch (layer) {
                case LAYER_OPAQUE: layer = LAYER_SILHOUETTE_OPAQUE; break;
                case LAYER_ALPHA:  layer = LAYER_SILHOUETTE_ALPHA;  break;
            }
        }
        if (gCurGraphNodeObject->node.flags & GRAPH_RENDER_OCCLUDE_SILHOUETTE) {
            switch (layer) {
                case LAYER_OPAQUE: layer = LAYER_OCCLUDE_SILHOUETTE_OPAQUE; break;
                case LAYER_ALPHA:  layer = LAYER_OCCLUDE_SILHOUETTE_ALPHA;  break;
            }
        }
    }
#endif // F3DEX_GBI_2 || SILHOUETTE
    struct MasterLayer* masterLayer = &gCurGraphNodeMasterList->layers[layer];
    append_dl(&masterLayer->list, displayList);
}

static void geo_append_batched_display_list(void *displayList, enum RenderLayers layer, enum LayerBatches batch) {
    struct MasterLayer* masterLayer = &gCurGraphNodeMasterList->layers[layer];
    append_dl(&masterLayer->objects->batches[batch], displayList);
}

static void inc_mat_stack() {
    Mtx *mtx = alloc_display_list(sizeof(*mtx));
    gMatStackIndex++;
    mtxf_to_mtx(mtx, gMatStack[gMatStackIndex]);
    gMatStackFixed[gMatStackIndex] = mtx;
}

static void append_dl_and_return(struct GraphNodeDisplayList *node) {
    if (node->displayList != NULL) {
        geo_append_display_list(node->displayList, GET_GRAPH_NODE_LAYER(node->node.flags));
    }
    if (node->node.children != NULL) {
        geo_process_node_and_siblings(node->node.children);
    }
    gMatStackIndex--;
}

/**
 * Process the master list node.
 */

static void batches_clean(struct BatchArray* task)
{
    if (task) {
        for (int batch = 0; batch < task->count; batch++) {
            task->batches[batch].head = NULL;
        }
    }
}

void geo_process_master_list(struct GraphNodeMasterList *node) {
    if (gCurGraphNodeMasterList == NULL && node->node.children != NULL) {
        gCurGraphNodeMasterList = node;
        for (int layer = LAYER_FIRST; layer < LAYER_COUNT; layer++) {
            struct MasterLayer* masterLayer = &node->layers[layer];
            masterLayer->list.head = NULL;
            batches_clean(masterLayer->objects);
            batches_clean(masterLayer->course);
        }
        geo_process_node_and_siblings(node->node.children);
        geo_process_master_list_sub(gCurGraphNodeMasterList);
        gCurGraphNodeMasterList = NULL;
    }
}

/**
 * Process an orthographic projection node.
 */
 void geo_process_ortho_projection(struct GraphNodeOrthoProjection *node) {
    if (node->node.children != NULL) {
        Mtx *mtx = alloc_display_list(sizeof(*mtx));
        f32 scale = node->scale / 2.0f;
        f32 left = (gCurGraphNodeRoot->x - gCurGraphNodeRoot->width) * scale;
        f32 right = (gCurGraphNodeRoot->x + gCurGraphNodeRoot->width) * scale;
        f32 top = (gCurGraphNodeRoot->y - gCurGraphNodeRoot->height) * scale;
        f32 bottom = (gCurGraphNodeRoot->y + gCurGraphNodeRoot->height) * scale;

        guOrtho(mtx, left, right, bottom, top, -2.0f, 2.0f, 1.0f);
        gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);

        geo_process_node_and_siblings(node->node.children);
    }
}

/**
 * Process a perspective projection node.
 */
void geo_process_perspective(struct GraphNodePerspective *node) {
    if (node->fnNode.func != NULL) {
        node->fnNode.func(GEO_CONTEXT_RENDER, &node->fnNode.node, gMatStack[gMatStackIndex]);
    }
    if (node->fnNode.node.children != NULL) {
        u16 perspNorm;
        Mtx *mtx = alloc_display_list(sizeof(*mtx));
#ifdef WIDE
        if (gConfig.widescreen && gCurrLevelNum != 0x01){
            sAspectRatio = 16.0f / 9.0f; // 1.775f
        } else {
            sAspectRatio = 4.0f / 3.0f; // 1.33333f
        }
#else
        sAspectRatio = 4.0f / 3.0f; // 1.33333f
#endif

        f32 vHalfFov = ( ((node->fov * 4096.f) + 8192.f) ) / 45.f;

        // We need to account for aspect ratio changes by multiplying by the widescreen horizontal stretch 
        // (normally 1.775).
        node->halfFovHorizontal = tans(vHalfFov * sAspectRatio);

#ifdef VERTICAL_CULLING
        node->halfFovVertical = tans(vHalfFov);
#endif

        // With low fovs, coordinate overflow can occur more easily. This slightly reduces precision only while zoomed in.
        f32 scale = node->fov < 28.0f ? remap(MAX(node->fov, 15), 15, 28, 0.5f, 1.0f): 1.0f;
        guPerspective(mtx, &perspNorm, node->fov, sAspectRatio, node->near / WORLD_SCALE, node->far / WORLD_SCALE, scale);

        gSPPerspNormalize(gDisplayListHead++, perspNorm);

        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);

        gCurGraphNodeCamFrustum = node;
        geo_process_node_and_siblings(node->fnNode.node.children);
        gCurGraphNodeCamFrustum = NULL;
    }
}

static f32 get_dist_from_camera(Vec3f pos) {
    return -((gCameraTransform[0][2] * pos[0])
           + (gCameraTransform[1][2] * pos[1])
           + (gCameraTransform[2][2] * pos[2])
           +  gCameraTransform[3][2]);
}

/**
 * Process a level of detail node. From the current transformation matrix,
 * the perpendicular distance to the camera is extracted and the children
 * of this node are only processed if that distance is within the render
 * range of this node.
 */
void geo_process_level_of_detail(struct GraphNodeLevelOfDetail *node) {
#ifdef AUTO_LOD
    f32 distanceFromCam = (gEmulator & EMU_CONSOLE) ? get_dist_from_camera(gMatStack[gMatStackIndex][3]) : 50.0f;
#else
    f32 distanceFromCam = get_dist_from_camera(gMatStack[gMatStackIndex][3]);
#endif

    if ((f32)node->minDistance <= distanceFromCam
        && distanceFromCam < (f32)node->maxDistance
        && node->node.children != 0) {
        geo_process_node_and_siblings(node->node.children);
    }
}

void geo_process_cull(struct GraphNodeCull* node)
{
    s16 active = TRUE;
#ifdef AUTO_LOD
    // if (!__unlikely(!gIsConsole))
#endif
    {
        active = node->x0 < gMarioStates->pos[0] && gMarioStates->pos[0] < node->x1
                && node->y0 < gMarioStates->pos[1] && gMarioStates->pos[1] < node->y1
                && node->z0 < gMarioStates->pos[2] && gMarioStates->pos[2] < node->z1;
    }

    if ((active ^ node->style) && node->node.children != 0) {
        geo_process_node_and_siblings(node->node.children);
    }
}

void geo_process_coin(struct GraphNodeCoin *node)
{
    int* panimState = &gCurGraphNodeObjectNode->oAnimState;
    if (*panimState >= 8)
        *panimState = 0;

    int frame = *panimState;
    enum LayerBatches batch = LAYER_ALPHA_COINS_FIRST + (frame < 5 ? frame : 8 - frame);
    void* dl = frame < 5 ? node->displayList : node->displayList_r;
    geo_append_batched_display_list(dl, LAYER_ALPHA, batch);
}

/**
 * Process a switch case node. The node's selection function is called
 * if it is 0, and among the node's children, only the selected child is
 * processed next.
 */
void geo_process_switch(struct GraphNodeSwitchCase *node) {
    struct GraphNode *selectedChild = node->fnNode.node.children;
    s32 i;

    if (node->fnNode.func != NULL) {
        node->fnNode.func(GEO_CONTEXT_RENDER, &node->fnNode.node, gMatStack[gMatStackIndex]);
    }
    for (i = 0; selectedChild != NULL && node->selectedCase > i; i++) {
        selectedChild = selectedChild->next;
    }
    if (selectedChild != NULL) {
        geo_process_node_and_siblings(selectedChild);
    }
}

Mat4 gCameraTransform;

static const Lights1 defaultLight = gdSPDefLights1(
    0x3F, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00
);

#ifdef F3DEX3
Vec3f globalLightDirection = { 0x49, 0x49, 0x49 };
#else
Vec3f globalLightDirection = { 0x28, 0x28, 0x28 };
#endif

void setup_global_light() {
    Lights1* curLight = (Lights1*)alloc_display_list(sizeof(Lights1));
    *curLight = defaultLight;

#ifdef WORLDSPACE_LIGHTING
    curLight->l->l.dir[0] = (s8)(globalLightDirection[0]);
    curLight->l->l.dir[1] = (s8)(globalLightDirection[1]);
    curLight->l->l.dir[2] = (s8)(globalLightDirection[2]);
#else
    Vec3f transformedLightDirection;
    linear_mtxf_transpose_mul_vec3f(gCameraTransform, transformedLightDirection, globalLightDirection);
    curLight->l->l.dir[0] = (s8)(transformedLightDirection[0]);
    curLight->l->l.dir[1] = (s8)(transformedLightDirection[1]);
    curLight->l->l.dir[2] = (s8)(transformedLightDirection[2]);
#endif

    gSPSetLights1(gDisplayListHead++, (*curLight));
}

/**
 * Process a camera node.
 */
void geo_process_camera(struct GraphNodeCamera *node) {
    Mtx *rollMtx = alloc_display_list(sizeof(*rollMtx));
    Mtx *viewMtx = alloc_display_list(sizeof(Mtx));

    if (node->fnNode.func != NULL) {
        node->fnNode.func(GEO_CONTEXT_RENDER, &node->fnNode.node, gMatStack[gMatStackIndex]);
    }
    mtxf_rotate_xy(rollMtx, node->rollScreen);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(rollMtx), G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);

    mtxf_lookat(gCameraTransform, node->pos, node->focus, node->roll);

    // Calculate the lookAt
#ifdef F3DEX_GBI_2
    // @bug This is where the LookAt values should be calculated but aren't.
    // As a result, environment mapping is broken on Fast3DEX2 without the
    // changes below.
    Mat4* cameraMatrix = &gCameraTransform;
    /**
    * HackerSM64 2.1: Now uses the correct "up" vector for the guLookAtReflect call in geo_process_master_list_sub.
    * It was originally sideways in vanilla, with vanilla's environment map textures sideways to accommodate, but those
    * textures are now rotated automatically on extraction to allow for this to be fixed.
    */
    gCurLookAt->l[0].l.dir[0] = (s8)(127.0f * (*cameraMatrix)[0][0]);
    gCurLookAt->l[0].l.dir[1] = (s8)(127.0f * (*cameraMatrix)[1][0]);
    gCurLookAt->l[0].l.dir[2] = (s8)(127.0f * (*cameraMatrix)[2][0]);
    gCurLookAt->l[1].l.dir[0] = (s8)(127.0f * -(*cameraMatrix)[0][1]);
    gCurLookAt->l[1].l.dir[1] = (s8)(127.0f * -(*cameraMatrix)[1][1]);
    gCurLookAt->l[1].l.dir[2] = (s8)(127.0f * -(*cameraMatrix)[2][1]);
    gSPLookAt(gDisplayListHead++, gCurLookAt);
#endif // F3DEX_GBI_2

#if WORLD_SCALE > 1
    // Make a copy of the view matrix and scale its translation based on WORLD_SCALE
    Mat4 scaledCamera;
    mtxf_copy(scaledCamera, gCameraTransform);
    for (int i = 0; i < 3; i++) {
        scaledCamera[3][i] /= WORLD_SCALE;
    }

    // Convert the scaled matrix to fixed-point and integrate it into the projection matrix stack
    guMtxF2L(scaledCamera, viewMtx);
#else
    guMtxF2L(gCameraTransform, viewMtx);
#endif
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(viewMtx), G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
    setup_global_light();

    if (node->fnNode.node.children != 0) {
        gCurGraphNodeCamera = node;
        node->matrixPtr = &gCameraTransform;
        geo_process_node_and_siblings(node->fnNode.node.children);
        gCurGraphNodeCamera = NULL;
    }
}

/**
 * Process a translation / rotation node. A transformation matrix based
 * on the node's translation and rotation is created and pushed on both
 * the float and fixed point matrix stacks.
 * For the rest it acts as a normal display list node.
 */
void geo_process_translation_rotation(struct GraphNodeTranslationRotation *node) {
    Vec3f translation;

    vec3s_to_vec3f(translation, node->translation);
    mtxf_rotate_zxy_and_translate_and_mul(node->rotation, translation, gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_dl_and_return((struct GraphNodeDisplayList *)node);
}

/**
 * Process a translation node. A transformation matrix based on the node's
 * translation is created and pushed on both the float and fixed point matrix stacks.
 * For the rest it acts as a normal display list node.
 */
void geo_process_translation(struct GraphNodeTranslation *node) {
    Vec3f translation;

    vec3s_to_vec3f(translation, node->translation);
    mtxf_translate_and_mul(translation[0], translation[1], translation[2], gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_dl_and_return((struct GraphNodeDisplayList *)node);
}

/**
 * Process a rotation node. A transformation matrix based on the node's
 * rotation is created and pushed on both the float and fixed point matrix stacks.
 * For the rest it acts as a normal display list node.
 */
void geo_process_rotation(struct GraphNodeRotation *node) {
    mtxf_rotate_zxy_and_translate_and_mul(node->rotation, gVec3fZero, gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_dl_and_return(((struct GraphNodeDisplayList *)node));
}

/**
 * Process a scaling node. A transformation matrix based on the node's
 * scale is created and pushed on both the float and fixed point matrix stacks.
 * For the rest it acts as a normal display list node.
 */
void geo_process_scale(struct GraphNodeScale *node) {
    Vec3f scaleVec;

    vec3f_set(scaleVec, node->scale, node->scale, node->scale);
    mtxf_scale_vec3f(gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex], scaleVec);

    inc_mat_stack();
    append_dl_and_return((struct GraphNodeDisplayList *)node);
}

/**
 * Process a billboard node. A transformation matrix is created that makes its
 * children face the camera, and it is pushed on the floating point and fixed
 * point matrix stacks.
 * For the rest it acts as a normal display list node.
 */
void geo_process_billboard(struct GraphNodeBillboard *node) {
    Vec3f translation;
    Vec3f scale = { 1.0f, 1.0f, 1.0f };

    vec3s_to_vec3f(translation, node->translation);

    if (gCurGraphNodeHeldObject != NULL) {
        vec3f_copy(scale, gCurGraphNodeHeldObject->objNode->header.gfx.scale);
    } else if (gCurGraphNodeObject != NULL) {
        vec3f_copy(scale, gCurGraphNodeObject->scale);
    }

    mtxf_billboard(gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex], translation, scale, gCurGraphNodeCamera->roll);

    inc_mat_stack();
    append_dl_and_return((struct GraphNodeDisplayList *)node);
}

/**
 * Process a display list node. It draws a display list without first pushing
 * a transformation on the stack, so all transformations are inherited from the
 * parent node. It processes its children if it has them.
 */
void geo_process_display_list(struct GraphNodeDisplayList *node) {
    append_dl_and_return((struct GraphNodeDisplayList *)node);

    gMatStackIndex++;
}

struct BatchCmd
{
    u32 idx;
    void* data;
};

static void geo_lvl_append_display_list(void *displayList, s32 layer) {
    // gSPLookAt(gDisplayListHead++, gCurLookAt);
#ifdef DISABLE_BATCHIFY
    append_dl(&gCurGraphNodeMasterList->layers[layer].list, displayList);
#else
    struct BatchArray* task = gCurGraphNodeMasterList->layers[layer].course;
#ifndef BATCH_SLOW_LOOP
    struct BatchCmd* data = segmented_to_virtual(displayList);
    while (data->idx)
    {
        append_dl(&task->batches[-data->idx - 1], data->data);
        data++;
    }
#else
    int batchIdx = 0;
    while (*data)
    {
        if (*data > 0)
        {
            append_dl(&task->batches[batchIdx], (void*)*data);
        }
        if (*data < 0)
        {
            batchIdx = -(1 + *data);
        }

        data++;
    }
#endif
#endif
}

static void append_lvl_dl_and_return(struct GraphNodeDisplayList *node) {
    if (node->displayList != NULL) {
        geo_lvl_append_display_list(node->displayList, GET_GRAPH_NODE_LAYER(node->node.flags));
    }
    if (node->node.children != NULL) {
        geo_process_node_and_siblings(node->node.children);
    }
    gMatStackIndex--;
}

void geo_process_batchset(struct GraphNodeDisplayList *node) {
    struct GraphNodeDisplayList *dlNode = node;
    append_lvl_dl_and_return(dlNode);
    gMatStackIndex++;
}

void geo_process_batch_display_list(struct GraphNodeBatchDisplayList *node) {
    geo_append_batched_display_list(node->displayList, GET_GRAPH_NODE_LAYER(node->node.flags), node->batch);
}

void geo_process_batch_anim_display_list(struct GraphNodeBatchAnimDisplayList *node) {
    int* panimState = &gCurGraphNodeObjectNode->oAnimState;
    if (*panimState >= node->animLimit)
        *panimState = 0;

    geo_append_batched_display_list(node->displayList, GET_GRAPH_NODE_LAYER(node->node.flags), node->batch + *panimState);
}

/**
 * Process a generated list. Instead of storing a pointer to a display list,
 * the list is generated on the fly by a function.
 */
void geo_process_generated_list(struct GraphNodeGenerated *node) {
    if (node->fnNode.func != NULL) {
        Gfx *list = node->fnNode.func(GEO_CONTEXT_RENDER, &node->fnNode.node, (struct AllocOnlyPool *) gMatStack[gMatStackIndex]);

        if (list != NULL) {
            geo_append_display_list((void *) VIRTUAL_TO_PHYSICAL(list), GET_GRAPH_NODE_LAYER(node->fnNode.node.flags));
        }
    }
    if (node->fnNode.node.children != NULL) {
        geo_process_node_and_siblings(node->fnNode.node.children);
    }
}

void geo_process_batch_generated_list(struct GraphNodeBatchGenerated *node) {
    if (node->genNode.fnNode.func != NULL) {
        Gfx *list = node->genNode.fnNode.func(GEO_CONTEXT_RENDER, &node->genNode.fnNode.node, (struct AllocOnlyPool *) gMatStack[gMatStackIndex]);

        if (list != NULL) {
            geo_append_batched_display_list((void *) VIRTUAL_TO_PHYSICAL(list), GET_GRAPH_NODE_LAYER(node->genNode.fnNode.node.flags), node->batch);
        }
    }
    if (node->genNode.fnNode.node.children != NULL) {
        geo_process_node_and_siblings(node->genNode.fnNode.node.children);
    }
}

/**
 * Process a background node. Tries to retrieve a background display list from
 * the function of the node. If that function is null or returns null, a black
 * rectangle is drawn instead.
 */
void geo_process_background(struct GraphNodeBackground *node) {
    Gfx *list = NULL;

    if (node->fnNode.func != NULL) {
        list = node->fnNode.func(GEO_CONTEXT_RENDER, &node->fnNode.node,
                                 gMatStack[gMatStackIndex]);
    }
    if (list != NULL) {
        geo_append_display_list((void *) VIRTUAL_TO_PHYSICAL(list), GET_GRAPH_NODE_LAYER(node->fnNode.node.flags));
    } else if (gCurGraphNodeMasterList != NULL) {
#ifndef F3DEX_GBI_2E
        Gfx *gfxStart = alloc_display_list(sizeof(Gfx) * 7);
#else
        Gfx *gfxStart = alloc_display_list(sizeof(Gfx) * 8);
#endif
        Gfx *gfx = gfxStart;

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetFillColor(gfx++, node->background);
        gDPFillRectangle(gfx++, GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(0), gBorderHeight,
        GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(0) - 1, SCREEN_HEIGHT - gBorderHeight - 1);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gSPEndDisplayList(gfx++);

        geo_append_display_list((void *) VIRTUAL_TO_PHYSICAL(gfxStart), LAYER_FORCE);
    }
    if (node->fnNode.node.children != NULL) {
        geo_process_node_and_siblings(node->fnNode.node.children);
    }
}

/**
 * Render an animated part. The current animation state is not part of the node
 * but set in global variables. If an animated part is skipped, everything afterwards desyncs.
 */
void geo_process_animated_part(struct GraphNodeAnimatedPart *node) {
    Vec3s rotation = { 0, 0, 0 };
    Vec3f translation = { node->translation[0], node->translation[1], node->translation[2] };

    if (gCurrAnimType == ANIM_TYPE_TRANSLATION) {
        translation[0] += gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)]
                          * gCurrAnimTranslationMultiplier;
        translation[1] += gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)]
                          * gCurrAnimTranslationMultiplier;
        translation[2] += gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)]
                          * gCurrAnimTranslationMultiplier;
        gCurrAnimType = ANIM_TYPE_ROTATION;
    } else {
        if (gCurrAnimType == ANIM_TYPE_LATERAL_TRANSLATION) {
            translation[0] +=
                gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)]
                * gCurrAnimTranslationMultiplier;
            gCurrAnimAttribute += 2;
            translation[2] +=
                gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)]
                * gCurrAnimTranslationMultiplier;
            gCurrAnimType = ANIM_TYPE_ROTATION;
        } else {
            if (gCurrAnimType == ANIM_TYPE_VERTICAL_TRANSLATION) {
                gCurrAnimAttribute += 2;
                translation[1] +=
                    gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)]
                    * gCurrAnimTranslationMultiplier;
                gCurrAnimAttribute += 2;
                gCurrAnimType = ANIM_TYPE_ROTATION;
            } else if (gCurrAnimType == ANIM_TYPE_NO_TRANSLATION) {
                gCurrAnimAttribute += 6;
                gCurrAnimType = ANIM_TYPE_ROTATION;
            }
        }
    }

    if (gCurrAnimType == ANIM_TYPE_ROTATION) {
        rotation[0] = gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)];
        rotation[1] = gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)];
        rotation[2] = gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)];
    }

    mtxf_rotate_xyz_and_translate_and_mul(rotation, translation, gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_dl_and_return(((struct GraphNodeDisplayList *)node));
}

/**
 * Initialize the animation-related global variables for the currently drawn
 * object's animation.
 */
void geo_set_animation_globals(struct AnimInfo *node, s32 hasAnimation) {
    struct Animation *anim = node->curAnim;

    if (hasAnimation) {
        node->animFrame = geo_update_animation_frame(node, &node->animFrameAccelAssist);
    }
    node->animTimer = gAreaUpdateCounter;
    if (anim->flags & ANIM_FLAG_HOR_TRANS) {
        gCurrAnimType = ANIM_TYPE_VERTICAL_TRANSLATION;
    } else if (anim->flags & ANIM_FLAG_VERT_TRANS) {
        gCurrAnimType = ANIM_TYPE_LATERAL_TRANSLATION;
    } else if (anim->flags & ANIM_FLAG_NO_TRANS) {
        gCurrAnimType = ANIM_TYPE_NO_TRANSLATION;
    } else {
        gCurrAnimType = ANIM_TYPE_TRANSLATION;
    }

    gCurrAnimFrame = node->animFrame;
    gCurrAnimEnabled = (anim->flags & ANIM_FLAG_DISABLED) == 0;
    gCurrAnimAttribute = segmented_to_virtual((void *) anim->index);
    gCurrAnimData = segmented_to_virtual((void *) anim->values);

    if (anim->animYTransDivisor == 0) {
        gCurrAnimTranslationMultiplier = 1.0f;
    } else {
        gCurrAnimTranslationMultiplier = (f32) node->animYTrans / (f32) anim->animYTransDivisor;
    }
}

/**
 * Process a shadow node. Renders a shadow under an object offset by the
 * translation of the first animated component and rotated according to
 * the floor below it.
 */
void geo_process_shadow(struct GraphNodeShadow *node) {
#ifndef DISABLE_SHADOWS
    if (gCurGraphNodeCamera != NULL && gCurGraphNodeObject != NULL) {
        Vec3f shadowPos;
        f32 shadowScale;

        if (gCurGraphNodeHeldObject != NULL) {
            vec3f_copy(shadowPos, gMatStack[gMatStackIndex][3]);
            shadowScale = node->shadowScale * gCurGraphNodeHeldObject->objNode->header.gfx.scale[0];
        } else {
            vec3f_copy(shadowPos, gCurGraphNodeObject->pos);
            shadowScale = node->shadowScale * gCurGraphNodeObject->scale[0];
        }

        s8 shifted = (gCurrAnimEnabled
                      && (gCurrAnimType == ANIM_TYPE_TRANSLATION
                       || gCurrAnimType == ANIM_TYPE_LATERAL_TRANSLATION)
        );

        if (shifted) {
            struct GraphNode *geo = node->node.children;
            f32 objScale = 1.0f;
            if (geo != NULL && geo->type == GRAPH_NODE_TYPE_SCALE) {
                objScale = ((struct GraphNodeScale *) geo)->scale;
            }

            f32 animScale = gCurrAnimTranslationMultiplier * objScale;
            Vec3f animOffset;
            animOffset[0] = gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)] * animScale;
            animOffset[1] = 0.0f;
            gCurrAnimAttribute += 2;
            animOffset[2] = gCurrAnimData[retrieve_animation_index(gCurrAnimFrame, &gCurrAnimAttribute)] * animScale;
            gCurrAnimAttribute -= 6;

            // simple matrix rotation so the shadow offset rotates along with the object
            f32 sinAng = sins(gCurGraphNodeObject->angle[1]);
            f32 cosAng = coss(gCurGraphNodeObject->angle[1]);

            shadowPos[0] += animOffset[0] * cosAng + animOffset[2] * sinAng;
            shadowPos[2] += -animOffset[0] * sinAng + animOffset[2] * cosAng;
        }

        Gfx *shadowList = create_shadow_below_xyz(shadowPos, shadowScale * 0.5f,
                                                  node->shadowSolidity, node->shadowType, shifted);

        if (shadowList != NULL) {
            mtxf_shadow(gMatStack[gMatStackIndex + 1],
                gCurrShadow.floorNormal, shadowPos, gCurrShadow.scale, gCurGraphNodeObject->angle[1]);

            inc_mat_stack();

            s32 layer = gCurrShadow.isDecal ? LAYER_TRANSPARENT_DECAL : LAYER_CLD;
            if (node->shadowType == SHADOW_CIRCLE) {
                s32 batch = gCurrShadow.isDecal ? LAYER_TRANSPARENT_DECAL_SHADOW_CIRCLE : LAYER_CLD_SHADOW_CIRCLE;
                geo_append_batched_display_list((void *) VIRTUAL_TO_PHYSICAL(shadowList), layer, batch);
            } else {
                geo_append_display_list((void *) VIRTUAL_TO_PHYSICAL(shadowList), layer);
            }

            gMatStackIndex--;
        }
    }
#endif
    if (node->node.children != NULL) {
        geo_process_node_and_siblings(node->node.children);
    }
}

/**
 * Check whether an object is in view to determine whether if it should be drawn.
 * This is known as frustum culling.
 * It checks whether the object is far away, very close or behind the camera and 
 * vertically or horizontally out of view. 
 * The radius used is specified in DEFAULT_CULLING_RADIUS unless the object 
 * has a culling radius node that specifies another value.
 * 
 * The matrix parameter should be the top of the matrix stack, which is the
 * object's transformation matrix times the camera 'look-at' matrix. The math
 * is counter-intuitive, but it checks column 3 (translation vector) of this
 * matrix to determine where the origin (0,0,0) in object space will be once
 * transformed to camera space (x+ = right, y+ = up, z = 'coming out the screen').
 * 
 * In 3D graphics, you typically model the world as being moved in front of a
 * static camera instead of a moving camera through a static world, which in
 * this case simplifies calculations. Note that the perspective matrix is not
 * on the matrix stack, so there are still calculations with the fov to compute
 * the slope of the lines of the frustum, these are done once during geo_process_perspective.
 *
 *        z-
 *
 *  \     |     /
 *   \    |    /
 *    \   |   /
 *     \  |  /
 *      \ | /
 *       \|/
 *        C       x+
 *
 * Since (0,0,0) is unaffected by rotation, columns 0, 1 and 2 are ignored.
 */

#define NO_CULLING_EMULATOR_BLACKLIST (EMU_CONSOLE | EMU_WIIVC | EMU_ARES | EMU_SIMPLE64 | EMU_CEN64)

s32 obj_is_in_view(struct GraphNodeObject *node) {
    struct GraphNode *geo = node->sharedChild;

    s16 cullingRadius;

    if (geo != NULL && geo->type == GRAPH_NODE_TYPE_CULLING_RADIUS) {
        cullingRadius = ((struct GraphNodeCullingRadius *) geo)->cullingRadius;
    } else {
        cullingRadius = DEFAULT_CULLING_RADIUS;
    }

    // Check whether the object is not too far away or too close / behind the camera.
    // This makes the HOLP not update when the camera is far away, and it
    // makes PU travel safe when the camera is locked on the main map.
    // If Mario were rendered with a depth over 65536 it would cause overflow
    // when converting the transformation matrix to a fixed point matrix.
    f32 cameraToObjectDepth = node->cameraToObject[2];

    #define VALID_DEPTH_MIDDLE (-20100.f / 2.f)
    #define VALID_DEPTH_RANGE (19900 / 2.f)
    if (absf(cameraToObjectDepth - VALID_DEPTH_MIDDLE) >= VALID_DEPTH_RANGE + cullingRadius) {
        return FALSE;
    }

#ifndef CULLING_ON_EMULATOR
    // If an emulator is detected, skip any other culling.
    if(!(gEmulator & NO_CULLING_EMULATOR_BLACKLIST)){
        return TRUE;
    }
#endif

#ifdef VERTICAL_CULLING
    f32 vScreenEdge = -cameraToObjectDepth * gCurGraphNodeCamFrustum->halfFovVertical;

    // Unlike with horizontal culling, we only check if the object is bellow the screen
    // to prevent shadows from being culled.
    if (node->cameraToObject[1] < -vScreenEdge - cullingRadius) {
        return FALSE;
    }

#endif
    
    f32 hScreenEdge = -cameraToObjectDepth * gCurGraphNodeCamFrustum->halfFovHorizontal;

    if (absf(node->cameraToObject[0]) > hScreenEdge + cullingRadius) {
        return FALSE;
    }
    return TRUE;
}

#ifdef VISUAL_DEBUG
void visualise_object_hitbox(struct Object *node) {
    Vec3f bnds1, bnds2;
    // This will create a cylinder that visualises their hitbox.
    // If they do not have a hitbox, it will be a small white cube instead.
    if (node->oIntangibleTimer != -1) {
        vec3f_set(bnds1, node->oPosX, (node->oPosY - node->hitboxDownOffset), node->oPosZ);
        vec3f_set(bnds2, node->hitboxRadius, node->hitboxHeight-node->hitboxDownOffset, node->hitboxRadius);
        if (node->behavior == segmented_to_virtual(bhvWarp)
            || node->behavior == segmented_to_virtual(bhvDoorWarp)
            || node->behavior == segmented_to_virtual(bhvFadingWarp)) {
            debug_box_color(COLOR_RGBA32_DEBUG_WARP);
        } else {
            debug_box_color(COLOR_RGBA32_DEBUG_HITBOX);
        }

        debug_box(bnds1, bnds2, (DEBUG_SHAPE_CYLINDER));
        vec3f_set(bnds1, node->oPosX, (node->oPosY - node->hitboxDownOffset), node->oPosZ);
        vec3f_set(bnds2, node->hurtboxRadius, node->hurtboxHeight, node->hurtboxRadius);
        debug_box_color(COLOR_RGBA32_DEBUG_HURTBOX);
        debug_box(bnds1, bnds2, (DEBUG_SHAPE_CYLINDER));
    } else {
        vec3f_set(bnds1, node->oPosX, (node->oPosY - 15), node->oPosZ);
        vec3f_set(bnds2, 30, 30, 30);
        debug_box_color(COLOR_RGBA32_DEBUG_POSITION);
        debug_box(bnds1, bnds2, (DEBUG_SHAPE_BOX));
    }
}
#endif

/**
 * Process an object node.
 */
void geo_process_object(struct Object *node) {
    if (node->header.gfx.areaIndex == gCurGraphNodeRoot->areaIndex) {
        s32 isInvisible = (node->header.gfx.node.flags & GRAPH_RENDER_INVISIBLE);
        s32 noThrowMatrix = (node->header.gfx.throwMatrix == NULL);
        // Maintain throw matrix pointer if the game is paused as it won't be updated.
        Mat4 *oldThrowMatrix = (sCurrPlayMode == PLAY_MODE_PAUSED) ? node->header.gfx.throwMatrix : NULL;

        // If the throw matrix is null and the object is invisible, there is no need
        // to update billboarding, scale, rotation, etc. 
        // This still updates translation since it is needed for sound.
        if (isInvisible && noThrowMatrix) {
            mtxf_translate(gMatStack[gMatStackIndex + 1], node->header.gfx.pos);
        }
        else{
            if (!noThrowMatrix) {
                mtxf_scale_vec3f(gMatStack[gMatStackIndex + 1], *node->header.gfx.throwMatrix, node->header.gfx.scale);
            } else if (node->header.gfx.node.flags & GRAPH_RENDER_BILLBOARD) {
                mtxf_billboard(gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex],
                            node->header.gfx.pos, node->header.gfx.scale, gCurGraphNodeCamera->roll);
            } else {
                mtxf_rotate_zxy_and_translate(gMatStack[gMatStackIndex + 1], node->header.gfx.pos, node->header.gfx.angle);
                mtxf_scale_vec3f(gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex + 1], node->header.gfx.scale);
            }
        }

        node->header.gfx.throwMatrix = &gMatStack[++gMatStackIndex];
        linear_mtxf_mul_vec3f_and_translate(gCameraTransform, node->header.gfx.cameraToObject, (*node->header.gfx.throwMatrix)[3]);

        // FIXME: correct types
        if (node->header.gfx.animInfo.curAnim != NULL) {
            geo_set_animation_globals(&node->header.gfx.animInfo, (node->header.gfx.node.flags & GRAPH_RENDER_HAS_ANIMATION) != 0);
        }

        if (!isInvisible && obj_is_in_view(&node->header.gfx)) {
            gMatStackIndex--;
            inc_mat_stack();

            if (node->header.gfx.sharedChild != NULL) {
#ifdef VISUAL_DEBUG
                if (hitboxView) visualise_object_hitbox(node);
#endif
                gCurGraphNodeObject = (struct GraphNodeObject *) node;
                node->header.gfx.sharedChild->parent = &node->header.gfx.node;
                geo_process_node_and_siblings(node->header.gfx.sharedChild);
                node->header.gfx.sharedChild->parent = NULL;
                gCurGraphNodeObject = NULL;
            }
            if (node->header.gfx.node.children != NULL) {
                geo_process_node_and_siblings(node->header.gfx.node.children);
            }
        }

        gMatStackIndex--;
        gCurrAnimType = ANIM_TYPE_NONE;
        node->header.gfx.throwMatrix = oldThrowMatrix;
    }
}

/**
 * Process an object parent node. Temporarily assigns itself as the parent of
 * the subtree rooted at 'sharedChild' and processes the subtree, after which the
 * actual children are be processed. (in practice they are null though)
 */
void geo_process_object_parent(struct GraphNodeObjectParent *node) {
    if (node->sharedChild != NULL) {
        node->sharedChild->parent = (struct GraphNode *) node;
        geo_process_node_and_siblings(node->sharedChild);
        node->sharedChild->parent = NULL;
    }
    if (node->node.children != NULL) {
        geo_process_node_and_siblings(node->node.children);
    }
}

/**
 * Process a held object node.
 */
void geo_process_held_object(struct GraphNodeHeldObject *node) {
    Mat4 mat;
    Vec3f translation;
    Mat4 tempMtx;

#ifdef F3DEX_GBI_2
    gSPLookAt(gDisplayListHead++, gCurLookAt);
#endif

    if (node->fnNode.func != NULL) {
        node->fnNode.func(GEO_CONTEXT_RENDER, &node->fnNode.node, gMatStack[gMatStackIndex]);
    }
    if (node->objNode != NULL && node->objNode->header.gfx.sharedChild != NULL) {
        vec3_scale_dest(translation, node->translation, 0.25f);

        mtxf_translate(mat, translation);
        mtxf_copy(gMatStack[gMatStackIndex + 1], *gCurGraphNodeObject->throwMatrix);
        vec3f_copy(gMatStack[gMatStackIndex + 1][3], gMatStack[gMatStackIndex][3]);
        mtxf_copy(tempMtx, gMatStack[gMatStackIndex + 1]);
        mtxf_mul(gMatStack[gMatStackIndex + 1], mat, tempMtx);
        mtxf_scale_vec3f(gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex + 1], node->objNode->header.gfx.scale);

        if (node->fnNode.func != NULL) {
            node->fnNode.func(GEO_CONTEXT_HELD_OBJ, &node->fnNode.node, gMatStack[gMatStackIndex + 1]);
        }

        inc_mat_stack();
        gGeoTempState.type = gCurrAnimType;
        gGeoTempState.enabled = gCurrAnimEnabled;
        gGeoTempState.frame = gCurrAnimFrame;
        gGeoTempState.translationMultiplier = gCurrAnimTranslationMultiplier;
        gGeoTempState.attribute = gCurrAnimAttribute;
        gGeoTempState.data = gCurrAnimData;
        gCurrAnimType = ANIM_TYPE_NONE;
        gCurGraphNodeHeldObject = (void *) node;
        if (node->objNode->header.gfx.animInfo.curAnim != NULL) {
            geo_set_animation_globals(&node->objNode->header.gfx.animInfo, (node->objNode->header.gfx.node.flags & GRAPH_RENDER_HAS_ANIMATION) != 0);
        }

        geo_process_node_and_siblings(node->objNode->header.gfx.sharedChild);
        gCurGraphNodeHeldObject = NULL;
        gCurrAnimType = gGeoTempState.type;
        gCurrAnimEnabled = gGeoTempState.enabled;
        gCurrAnimFrame = gGeoTempState.frame;
        gCurrAnimTranslationMultiplier = gGeoTempState.translationMultiplier;
        gCurrAnimAttribute = gGeoTempState.attribute;
        gCurrAnimData = gGeoTempState.data;
        gMatStackIndex--;
    }

    if (node->fnNode.node.children != NULL) {
        geo_process_node_and_siblings(node->fnNode.node.children);
    }
}

/**
 * Processes the children of the given GraphNode if it has any
 */
void geo_try_process_children(struct GraphNode *node) {
    if (node->children != NULL) {
        geo_process_node_and_siblings(node->children);
    }
}

extern f32 profiler_get_fps();
static const f32 sViewRangeMax = 400000000.0f;
static const f32 sViewRangeMin = 30000000.0f;
static f32 sViewRange = 400000000.0f;
static const f32 sViewRangeChangeRate = 0.0004f * 400000000.0f;

static void adjust_view_range()
{
    if (!gIsConsole)
    {
        return;
    }

    f32 fps = profiler_get_fps();
    
    print_text_fmt_int(20, 20, "FPS %d", fps * 100);
    print_text_fmt_int(20, 40, "VR: %d", sViewRange / 1000);

    if (fps < 29.0f) 
    {
        sViewRange -= sViewRangeChangeRate * (30.f - fps);
        if (sViewRange < sViewRangeMin)
            sViewRange = sViewRangeMin;
    }
    else
    {
        sViewRange += sViewRangeChangeRate;
        if (sViewRange > sViewRangeMax)
            sViewRange = sViewRangeMax;
    }
}

static int is_far_from_mario(Vec3f loc)
{
    f32 dx = loc[0] - gCurGraphNodeCamera->focus[0];
    f32 dy = loc[1] - gCurGraphNodeCamera->focus[1];
    f32 dz = loc[2] - gCurGraphNodeCamera->focus[2];
    f32 dist = dx*dx + dy*dy + dz*dz;

    f32 range = sViewRange;
    if (gCurrCourseNum == COURSE_FR)
        range *= 3.f;

    return dist > range;
}

void geo_process_lvl_translation_rotation(struct GraphNodeLvlTranslationRotation *node) {
    Vec3f translation;
    translation[0] = node->translation[0] - gCurrentArea->renderOffset[0];
    translation[1] = node->translation[1] - gCurrentArea->renderOffset[1];
    translation[2] = node->translation[2] - gCurrentArea->renderOffset[2];
    if (is_far_from_mario(translation)) {
        return;
    }

    mtxf_rotate_zxy_and_translate_and_mul(node->rotation, translation, gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    struct GraphNodeDisplayList *dlNode = (struct GraphNodeDisplayList *)node;
    return append_lvl_dl_and_return(dlNode);
}

void geo_process_lvl_translation(struct GraphNodeLvlTranslation *node) {
    Vec3f translation;
    translation[0] = node->translation[0] - gCurrentArea->renderOffset[0];
    translation[1] = node->translation[1] - gCurrentArea->renderOffset[1];
    translation[2] = node->translation[2] - gCurrentArea->renderOffset[2];
    if (is_far_from_mario(translation)) {
        return;
    }

    mtxf_translate_and_mul(translation[0], translation[1], translation[2], gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    struct GraphNodeDisplayList *dlNode = (struct GraphNodeDisplayList *)node;
    return append_lvl_dl_and_return(dlNode);
}

void geo_process_break_translation(struct GraphNodeTranslation *node) {
    Vec3f translation;
    
    struct Object* obj = (struct Object*)gCurGraphNodeObject;
    Vec3f dir = { node->translation[0], 0,  node->translation[2] };
    f32 mag = sqrtf(dir[0]*dir[0] + dir[2]*dir[2]);
    if (mag > 0.1f) {
        dir[0] /= mag;
        dir[2] /= mag;
    }

    translation[0] = node->translation[0] - dir[0] * obj->oHomeX;
    translation[1] = node->translation[1] - obj->oHomeY;
    translation[2] = node->translation[2] - dir[2] * obj->oHomeZ;
    mtxf_translate_and_mul(translation[0], translation[1], translation[2], gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_dl_and_return((struct GraphNodeDisplayList *)node);
}

void geo_process_break_translation_rotation(struct GraphNodeTranslationRotation *node) {
    Vec3f translation;
    
    struct Object* obj = (struct Object*)gCurGraphNodeObject;
    Vec3f dir = { node->translation[0], 0,  node->translation[2] };
    Vec3s rotation;
    f32 mag = sqrtf(dir[0]*dir[0] + dir[2]*dir[2]);
    if (mag > 0.1f) {
        dir[0] /= mag;
        dir[2] /= mag;
    }

    translation[0] = node->translation[0] - dir[0] * obj->oHomeX;
    translation[1] = node->translation[1] - obj->oHomeY;
    translation[2] = node->translation[2] - dir[2] * obj->oHomeZ;
    rotation[0] = node->rotation[0];
    rotation[1] = node->rotation[1];
    rotation[2] = node->rotation[2];
    mtxf_translate_and_mul(translation[0], translation[1], translation[2], gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_dl_and_return((struct GraphNodeDisplayList *)node);
}

void geo_process_obj_translation_rotation(struct GraphNodeTranslationRotation *node) {
    struct Object* obj = (struct Object*)gCurGraphNodeObject;
    Vec3f translation;
    Vec3s rotation;

    translation[0] = node->translation[0] + obj->oHomeX;
    translation[1] = node->translation[1] + obj->oHomeY;
    translation[2] = node->translation[2] + obj->oHomeZ;
    rotation[0] = node->rotation[0] + obj->oGeoPitch;
    rotation[1] = node->rotation[1] + obj->oGeoYaw;
    rotation[2] = node->rotation[2] + obj->oGeoRoll;
    mtxf_rotate_zxy_and_translate_and_mul(rotation, translation, gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_dl_and_return((struct GraphNodeDisplayList *)node);
}

void geo_process_obj_rocket_translation(struct GraphNodeTranslation *node) {
    struct Object* obj = (struct Object*)gCurGraphNodeObject;
    Vec3f translation;
    translation[0] = node->translation[0] + obj->oHomeX;
    translation[1] = node->translation[1] + obj->oHomeY;
    translation[2] = node->translation[2] + (node->translation[2] < 0 ? -obj->oHomeZ : obj->oHomeZ);
    mtxf_translate_and_mul(translation[0], translation[1], translation[2], gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_dl_and_return((struct GraphNodeDisplayList *)node);
}

void geo_process_obj_translation(struct GraphNodeTranslation *node) {
    struct Object* obj = (struct Object*)gCurGraphNodeObject;
    Vec3f translation;
    translation[0] = node->translation[0] + obj->oHomeX;
    translation[1] = node->translation[1] + obj->oHomeY;
    translation[2] = node->translation[2] + obj->oHomeZ;
    mtxf_translate_and_mul(translation[0], translation[1], translation[2], gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_dl_and_return((struct GraphNodeDisplayList *)node);
}

static geo_process_batchset_translation(struct GraphNodeTranslation *node) {
    Vec3f translation;
    translation[0] = node->translation[0];
    translation[1] = node->translation[1];
    translation[2] = node->translation[2];
    mtxf_translate_and_mul(translation[0], translation[1], translation[2], gMatStack[gMatStackIndex + 1], gMatStack[gMatStackIndex]);

    inc_mat_stack();
    append_lvl_dl_and_return((struct GraphNodeDisplayList *)node);
}

typedef void (*GeoProcessFunc)();

// See enum 'GraphNodeTypes' in 'graph_node.h'.
static const GeoProcessFunc GeoProcessJumpTable[] = {
    [GRAPH_NODE_TYPE_ORTHO_PROJECTION    ] = geo_process_ortho_projection,
    [GRAPH_NODE_TYPE_PERSPECTIVE         ] = geo_process_perspective,
    [GRAPH_NODE_TYPE_MASTER_LIST         ] = geo_process_master_list,
    [GRAPH_NODE_TYPE_LEVEL_OF_DETAIL     ] = geo_process_level_of_detail,
    [GRAPH_NODE_TYPE_SWITCH_CASE         ] = geo_process_switch,
    [GRAPH_NODE_TYPE_CAMERA              ] = geo_process_camera,
    [GRAPH_NODE_TYPE_TRANSLATION_ROTATION] = geo_process_translation_rotation,
    [GRAPH_NODE_TYPE_TRANSLATION         ] = geo_process_translation,
    [GRAPH_NODE_TYPE_ROTATION            ] = geo_process_rotation,
    [GRAPH_NODE_TYPE_OBJECT              ] = geo_process_object,
    [GRAPH_NODE_TYPE_ANIMATED_PART       ] = geo_process_animated_part,
    [GRAPH_NODE_TYPE_BILLBOARD           ] = geo_process_billboard,
    [GRAPH_NODE_TYPE_DISPLAY_LIST        ] = geo_process_display_list,
    [GRAPH_NODE_TYPE_SCALE               ] = geo_process_scale,
    [GRAPH_NODE_TYPE_SHADOW              ] = geo_process_shadow,
    [GRAPH_NODE_TYPE_OBJECT_PARENT       ] = geo_process_object_parent,
    [GRAPH_NODE_TYPE_GENERATED_LIST      ] = geo_process_generated_list,
    [GRAPH_NODE_TYPE_BACKGROUND          ] = geo_process_background,
    [GRAPH_NODE_TYPE_HELD_OBJ            ] = geo_process_held_object,
    [GRAPH_NODE_TYPE_CULLING_RADIUS      ] = geo_try_process_children,
    [GRAPH_NODE_TYPE_ROOT                ] = geo_try_process_children,
    [GRAPH_NODE_TYPE_START               ] = geo_try_process_children,
    [GRAPH_NODE_TYPE_CULL                ] = geo_process_cull,
    [GRAPH_NODE_TYPE_COIN                ] = geo_process_coin,

    [GRAPH_NODE_TYPE_LVL_TRANSLATION_ROTATION] = geo_process_lvl_translation_rotation,
    [GRAPH_NODE_TYPE_LVL_TRANSLATION         ] = geo_process_lvl_translation,
    [GRAPH_NODE_TYPE_BREAK_TRANSLATION       ] = geo_process_break_translation,
    [GRAPH_NODE_TYPE_OBJ_TRANSLATION_ROTATION] = geo_process_obj_translation_rotation,
    [GRAPH_NODE_TYPE_OBJ_ROCKET_TRANSLATION  ] = geo_process_obj_rocket_translation,
    [GRAPH_NODE_TYPE_OBJ_TRANSLATION  ]        = geo_process_obj_translation,
    [GRAPH_NODE_TYPE_BREAK_TRANSLATION_ROTATION] = geo_process_break_translation_rotation,
    [GRAPH_NODE_TYPE_BATCHSET]                 = geo_process_batchset,
    [GRAPH_NODE_TYPE_BATCH_DISPLAY_LIST]       = geo_process_batch_display_list,
    [GRAPH_NODE_TYPE_BATCH_GENERATED_LIST]     = geo_process_batch_generated_list,
    [GRAPH_NODE_TYPE_BATCH_ANIM_DISPLAY_LIST]  = geo_process_batch_anim_display_list,
    [GRAPH_NODE_TYPE_BATCHSET_TRANSLATION]     = geo_process_batchset_translation,
};

/**
 * Process a generic geo node and its siblings.
 * The first argument is the start node, and all its siblings will
 * be iterated over.
 */
void geo_process_node_and_siblings(struct GraphNode *firstNode) {
    s32 iterateChildren = TRUE;
    struct GraphNode *curGraphNode = firstNode;
    struct GraphNode *parent = curGraphNode->parent;

    // In the case of a switch node, exactly one of the children of the node is
    // processed instead of all children like usual
    if (parent != NULL) {
        iterateChildren = (parent->type != GRAPH_NODE_TYPE_SWITCH_CASE);
    }

    do {
        if (curGraphNode->flags & GRAPH_RENDER_ACTIVE) {
            if (curGraphNode->flags & GRAPH_RENDER_CHILDREN_FIRST) {
                geo_try_process_children(curGraphNode);
            } else {
                GeoProcessJumpTable[curGraphNode->type](curGraphNode);
            }
        } else {
            if (curGraphNode->type == GRAPH_NODE_TYPE_OBJECT) {
                ((struct GraphNodeObject *) curGraphNode)->throwMatrix = NULL;
            }
        }
    } while (iterateChildren && (curGraphNode = curGraphNode->next) != firstNode);
}

/**
 * Process a root node. This is the entry point for processing the scene graph.
 * The root node itself sets up the viewport, then all its children are processed
 * to set up the projection and draw display lists.
 */
void geo_process_root(struct GraphNodeRoot *node, Vp *b, Vp *c, s32 clearColor) {
    if (node->node.flags & GRAPH_RENDER_ACTIVE) {
        Mtx *initialMatrix;
        Vp *viewport = alloc_display_list(sizeof(*viewport));

        main_pool_push_state();
        initialMatrix = alloc_display_list(sizeof(*initialMatrix));
        gCurLookAt = (LookAt*)alloc_display_list(sizeof(LookAt));
        bzero(gCurLookAt, sizeof(LookAt));

        gMatStackIndex = 0;
        gCurrAnimType = ANIM_TYPE_NONE;
#ifdef F3DEX3
        const int maxz = G_NEW_MAXZ / 2;
#else
        const int maxz = 511;
#endif
        vec3s_set(viewport->vp.vtrans, node->x * 4, node->y * 4, maxz);
        viewport->vp.vtrans[3] = 0;
        vec3s_set(viewport->vp.vscale, node->width * 4, node->height * 4, maxz);
        viewport->vp.vscale[3] = 0;
#ifdef F3DEX3
        viewport->vp.vscale[1] = -viewport->vp.vscale[1];
#endif

        if (b != NULL) {
            clear_framebuffer(clearColor);
            make_viewport_clip_rect(b);
            *viewport = *b;
        }

        else if (c != NULL) {
            clear_framebuffer(clearColor);
            make_viewport_clip_rect(c);
        }

        mtxf_identity(gMatStack[gMatStackIndex]);
        mtxf_to_mtx(initialMatrix, gMatStack[gMatStackIndex]);
        gMatStackFixed[gMatStackIndex] = initialMatrix;
        gSPViewport(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(viewport));
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(gMatStackFixed[gMatStackIndex]),
                  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gCurGraphNodeRoot = node;
        if (node->node.children != NULL) {
            geo_process_node_and_siblings(node->node.children);
        }
        gCurGraphNodeRoot = NULL;
#ifdef VANILLA_DEBUG
        if (gShowDebugText) {
            print_text_fmt_int(180, 36, "MEM %d", gDisplayListHeap->totalSpace - gDisplayListHeap->usedSpace);
        }
#endif
        main_pool_pop_state();
    }
}
