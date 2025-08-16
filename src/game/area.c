#include <PR/ultratypes.h>

#include "config.h"
#include "area.h"
#include "sm64.h"
#include "gfx_dimensions.h"
#include "behavior_data.h"
#include "game_init.h"
#include "object_list_processor.h"
#include "engine/surface_load.h"
#include "fail_warp.h"
#include "ingame_menu.h"
#include "screen_transition.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "print.h"
#include "hud.h"
#include "audio/external.h"
#include "area.h"
#include "rendering_graph_node.h"
#include "level_update.h"
#include "engine/geo_layout.h"
#include "save_file.h"
#include "level_table.h"
#include "dialog_ids.h"
#include "puppyprint.h"
#include "debug_box.h"
#include "engine/colors.h"
#include "profiling.h"
#include "emutest.h"
#include "debug.h"
#ifdef S2DEX_TEXT_ENGINE
#include "s2d_engine/init.h"
#endif

struct SpawnInfo gPlayerSpawnInfos[1];
struct GraphNode *gGraphNodePointers[MODEL_ID_COUNT];
struct Area gAreaData[AREA_COUNT];

struct WarpTransition gWarpTransition;

s16 gCurrCourseNum;
s16 gCurrActNum = 1;
s16 gCurrAreaIndex;
s16 gSavedCourseNum;
s16 gMenuOptSelectIndex;
s16 gSaveOptSelectIndex;

// struct SpawnInfo *gMarioSpawnInfo = &gPlayerSpawnInfos[0];
// struct GraphNode **gLoadedGraphNodes = gGraphNodePointers;
// struct Area *gAreas = gAreaData;
struct Area *gCurrentArea = NULL;
struct CreditsEntry *gCurrCreditsEntry = NULL;

Vp *gViewportOverride = NULL;
Vp *gViewportClip = NULL;
s16 gWarpTransDelay = 0;
RGBA16FILL gFBSetColor = 0;
RGBA16FILL gWarpTransFBSetColor = 0;
Color gWarpTransRed= 0;
Color gWarpTransGreen = 0;
Color gWarpTransBlue = 0;
s16 gCurrSaveFileNum = 1;
s16 gCurrLevelNum = LEVEL_MIN;

/*
 * The following two tables are used in get_mario_spawn_type() to determine spawn type
 * from warp behavior.
 * When looping through sWarpBhvSpawnTable, if the behavior function in the table matches
 * the spawn behavior executed, the index of that behavior is used with sSpawnTypeFromWarpBhv
*/

static const BehaviorScript *sWarpBhvSpawnTable[] = {
    bhvDoorWarp,                bhvStar,                   bhvExitPodiumWarp,          bhvWarp,
    bhvWarpPipe,                bhvFadingWarp,             bhvInstantActiveWarp,       bhvAirborneWarp,
    bhvHardAirKnockBackWarp,    bhvSpinAirborneCircleWarp, bhvDeathWarp,               bhvSpinAirborneWarp,
    bhvFlyingWarp,              bhvSwimmingWarp,           bhvPaintingStarCollectWarp, bhvPaintingDeathWarp,
    bhvAirborneStarCollectWarp, bhvAirborneDeathWarp,      bhvLaunchStarCollectWarp,   bhvLaunchDeathWarp,
    bhvCheckpoint, bhvGoal
};

static const u8 sSpawnTypeFromWarpBhv[] = {
    MARIO_SPAWN_DOOR_WARP,             MARIO_SPAWN_IDLE,                 MARIO_SPAWN_PIPE,                  MARIO_SPAWN_PIPE,
    MARIO_SPAWN_PIPE,                  MARIO_SPAWN_TELEPORT,             MARIO_SPAWN_INSTANT_ACTIVE,        MARIO_SPAWN_AIRBORNE,
    MARIO_SPAWN_HARD_AIR_KNOCKBACK,    MARIO_SPAWN_SPIN_AIRBORNE_CIRCLE, MARIO_SPAWN_DEATH,                 MARIO_SPAWN_SPIN_AIRBORNE,
    MARIO_SPAWN_FLYING,                MARIO_SPAWN_SWIMMING,             MARIO_SPAWN_PAINTING_STAR_COLLECT, MARIO_SPAWN_PAINTING_DEATH,
    MARIO_SPAWN_AIRBORNE_STAR_COLLECT, MARIO_SPAWN_AIRBORNE_DEATH,       MARIO_SPAWN_AIRBORNE_STAR_COLLECT, MARIO_SPAWN_LAUNCH_DEATH,
    MARIO_SPAWN_DEATH,                 MARIO_SPAWN_DEATH,
};

#ifdef F3DEX3
Vp gViewport = { {
    { (SCREEN_WIDTH/2)*4, -(SCREEN_HEIGHT/2)*4, G_NEW_MAXZ/2, 0, },
    { (SCREEN_WIDTH/2)*4,  (SCREEN_HEIGHT/2)*4, G_NEW_MAXZ/2, 0, },
} };
#else
Vp gViewport = { {
    { 640, 480, 511, 0 },
    { 640, 480, 511, 0 },
} };
#endif

LangArray gNoControllerMsg = DEFINE_LANGUAGE_ARRAY(
    "NO CONTROLLER",
    "MANETTE DEBRANCHEE",
    "CONTROLLER FEHLT",
    "NO CONTROLLER",
    "NO HAY MANDO");

void override_viewport_and_clip(Vp *vpOverride, Vp *vpClip, Color red, Color green, Color blue) {
    RGBA16 color = ((red >> 3) << IDX_RGBA16_R) | ((green >> 3) << IDX_RGBA16_G) | ((blue >> 3) << IDX_RGBA16_B) | MSK_RGBA16_A;

    gFBSetColor = (color << 16) | color;
    gViewportOverride = vpOverride;
    gViewportClip = vpClip;
}

void set_warp_transition_rgb(Color red, Color green, Color blue) {
    RGBA16 warpTransitionRGBA16 = ((red >> 3) << IDX_RGBA16_R) | ((green >> 3) << IDX_RGBA16_G) | ((blue >> 3) << IDX_RGBA16_B) | MSK_RGBA16_A;

    gWarpTransFBSetColor = (warpTransitionRGBA16 << 16) | warpTransitionRGBA16;
    gWarpTransRed = red;
    gWarpTransGreen = green;
    gWarpTransBlue = blue;
}

void print_intro_text(void) {
    if ((gGlobalTimer & 31) < 20) {
        if (gControllerBits == 0) {
            print_text_aligned(SCREEN_CENTER_X, 20, LANG_ARRAY(gNoControllerMsg), TEXT_ALIGN_CENTER);
        } else {
            print_text_aligned(60, 38, "PRESS", TEXT_ALIGN_CENTER);
            print_text_aligned(60, 20, "START", TEXT_ALIGN_CENTER);
        }
    }
}

u32 get_mario_spawn_type(struct Object *obj) {
    s32 i;
    const BehaviorScript *behavior = obj->behavior;

    for (i = 0; i < ARRAY_COUNT(sWarpBhvSpawnTable); i++) {
        if (sWarpBhvSpawnTable[i] == behavior) {
            return sSpawnTypeFromWarpBhv[i];
        }
    }
    return MARIO_SPAWN_NONE;
}

static int warpIdBase()
{
    if (gCurrLevelNum <= LEVEL_SS2)
    {
        return gCurrLevelNum - LEVEL_CE;
    }
    if (gCurrLevelNum <= LEVEL_SS1)
    {
        return gCurrLevelNum - LEVEL_IG;
    }

    return 0xa;
}

extern void LevelReset_markObjectsForRespawn();
struct ObjectWarpNode *area_get_warp_node(u8 id) {
    if (id == WARP_NODE_FAIL_WARP || id == WARP_NODE_FAIL_WARP2 || (0xe0 <= id && id < 0xf0))
    {
        return fail_warp_area_get_warp_node(id);
    }

    struct ObjectWarpNode *node = NULL;

    for (node = gCurrentArea->warpNodes; node != NULL; node = node->next) {
        if (node->node.id == id) {
            break;
        }
    }

    if (gCurrCourseNum != COURSE_SS2 && id == WARP_NODE_DEFAULT) {
        node->node.destArea = 1;
        node->node.destLevel = LEVEL_CASTLE_GROUNDS;
        node->node.destNode = 0x50 + warpIdBase();
    }
    if (id == WARP_NODE_DEATH && gCurrCourseNum != COURSE_NONE) {
        node->node.destArea = 1;
        node->node.destLevel = LEVEL_CASTLE_GROUNDS;
        node->node.destNode = 0x80 + warpIdBase();
    }

    return node;
}

struct Object *get_destination_warp_object(u8 warpDestId) {
    if (warpDestId == WARP_NODE_FAIL_WARP || warpDestId == WARP_NODE_FAIL_WARP2)
    {
        return &gFailWarpSpoofedWarpObject;
    }

    struct Object *children = (struct Object *) gObjParentGraphNode.children;

    do {
        struct Object *obj = children;

        u8 bparam2 = GET_BPARAM2(obj->oBehParams);
        if (warpDestId == bparam2 && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && get_mario_spawn_type(obj) != MARIO_SPAWN_NONE) {
            return obj;
        }
    } while ((children = (struct Object *) children->header.gfx.node.next)
             != (struct Object *) gObjParentGraphNode.children);

    return NULL;
}

void clear_areas(void) {
    s32 i, j;

    gCurrentArea = NULL;
    gWarpTransition.isActive = FALSE;
    gWarpTransition.pauseRendering = FALSE;
    gMarioSpawnInfo->areaIndex = -1;

    for (i = 0; i < AREA_COUNT; i++) {
        gAreaData[i].index = i;
        gAreaData[i].flags = AREA_FLAG_UNLOAD;
        gAreaData[i].terrainType = TERRAIN_GRASS;
        gAreaData[i].graphNode = NULL;
        gAreaData[i].terrainData = NULL;
        gAreaData[i].surfaceRooms = NULL;
        gAreaData[i].warpNodes = NULL;
        gAreaData[i].paintingWarpNodes = NULL;
        gAreaData[i].instantWarps = NULL;
        gAreaData[i].objectSpawnInfos = NULL;
        gAreaData[i].camera = NULL;
        gAreaData[i].unused = NULL;
        for (j = 0; j < ARRAY_COUNT(gAreaData[i].whirlpools); j++) {
            gAreaData[i].whirlpools[j] = NULL;
        }
        gAreaData[i].dialog[0] = DIALOG_NONE;
        gAreaData[i].dialog[1] = DIALOG_NONE;
        gAreaData[i].musicParam = 0;
        gAreaData[i].musicParam2 = 0;
        gAreaData[i].useEchoOverride = FALSE;
        gAreaData[i].echoOverride = 0;
#ifdef BETTER_REVERB
        gAreaData[i].betterReverbPreset = 0;
#endif
    }
}

void clear_area_graph_nodes(void) {
    s32 i;

    if (gCurrentArea != NULL) {
        geo_call_global_function_nodes(&gCurrentArea->graphNode->node, GEO_CONTEXT_AREA_UNLOAD);
        gCurrentArea = NULL;
        gWarpTransition.isActive = FALSE;
    }

    for (i = 0; i < AREA_COUNT; i++) {
        if (gAreaData[i].graphNode != NULL) {
            geo_call_global_function_nodes(&gAreaData[i].graphNode->node, GEO_CONTEXT_AREA_INIT);
            gAreaData[i].graphNode = NULL;
        }
    }
}

typedef struct
{
    /* 0x0 */ f32 factor;
    /* 0x4 */ u16 offset;
    /* 0x8 */ u32 scale;
} __OSViScale;

typedef struct
{
    /* 0x0 */ u16 state;
    /* 0x2 */ u16 retraceCount;
    /* 0x4 */ void *framep;
    /* 0x8 */ OSViMode *modep;
    /* 0xC */ u32 control;
    /* 0x10 */ OSMesgQueue *msgq;
    /* 0x14 */ OSMesg msg;
    /* 0x18 */ __OSViScale x;
    /* 0x24 */ __OSViScale y;
} __OSViContext; // 0x30 bytes

#define VI_STATE_XSCALE_UPDATED 0x02

extern __OSViContext *__osViNext __attribute__((section(".data")));

extern void __osRestoreInt(u32);
extern u32 __osDisableInt();

static void osViSetXScaleRaw(u32 scale) {
    register u32 nomValue;
    register u32 saveMask = __osDisableInt();
    
    __osViNext->x.factor = 0;
    __osViNext->state |= VI_STATE_XSCALE_UPDATED;
    __osViNext->x.scale = scale;
    __osRestoreInt(saveMask);
}

void set_vi_mode(void)
{
    if (!gIsConsole)
        return;

    const int enabled = 7;
    register u32 saveMask = __osDisableInt();
    if (enabled & 1)
    {
        __osViNext->control |= VI_CTRL_ANTIALIAS_MODE_1;
        osViSetXScaleRaw(0x201);
    }
    else
    {
        __osViNext->control &= ~VI_CTRL_ANTIALIAS_MODE_1;
    }

    if (enabled & 2)
    {
        __osViNext->control |= VI_CTRL_ANTIALIAS_MODE_2;
    }
    else
    {
        __osViNext->control &= ~VI_CTRL_ANTIALIAS_MODE_2;
    }

    if (enabled & 4)
    {
        __osViNext->control &= ~VI_CTRL_DITHER_FILTER_ON;
    }
    else
    {
        __osViNext->control |= VI_CTRL_DITHER_FILTER_ON;
    }

    __osRestoreInt(saveMask);
}

extern void *memcpy(void *dst, const void *src, size_t size);
extern struct GraphNodeStart* gBatchNode;
static void warm_up_batch_node(void)
{
    if (!gBatchNode)
        return;

    f32 areaX = gCurrentArea->renderOffset[0];
    f32 areaY = gCurrentArea->renderOffset[1];
    f32 areaZ = gCurrentArea->renderOffset[2];

    // Pass 1: calculate the size for allocations and amount of nodes
    int allocSize = sizeof(int);
    int amount = 0;
    {
        struct GraphNode *firstNode = gBatchNode->node.children;
        struct GraphNode *curGraphNode = firstNode;
        do
        {
            struct GraphNodeLvlTranslation* lvlNode = NULL;
            int size = 0;
            switch (curGraphNode->type)
            {
                case GRAPH_NODE_TYPE_LVL_TRANSLATION_ROTATION_COLD:
                    size = sizeof(struct LightGraphLvlNodeTranslationRotation);
                    lvlNode = (struct GraphNodeLvlTranslation*) curGraphNode;
                    break;
                case GRAPH_NODE_TYPE_LVL_TRANSLATION_COLD:
                    size = sizeof(struct LightGraphLvlNodeTranslation);
                    lvlNode = (struct GraphNodeLvlTranslation*) curGraphNode;
                    break;
                case GRAPH_NODE_TYPE_GENERATED_LIST:
                    size = sizeof(struct GraphNodeGenerated);
                    break;
                case GRAPH_NODE_TYPE_SWITCH_CASE:
                    size = sizeof(struct GraphNodeSwitchCase);
                    break;
                case GRAPH_NODE_TYPE_TRANSLATION:
                    size = sizeof(struct GraphNodeTranslation);
                    break;
            }

#ifdef DEBUG_ASSERTIONS
            if (!size) {
                static char errorMsg[40];
                sprintf(errorMsg, "Unknown node type %d", curGraphNode->type);
                error(errorMsg);
            }
#endif

            if (lvlNode)
            {
                f32 dx = lvlNode->translation[0] - areaX;
                f32 dy = lvlNode->translation[1] - areaY;
                f32 dz = lvlNode->translation[2] - areaZ;
                f32 dist = dx * dx + dy * dy + dz * dz;
                // this is incredibly far - the furthest point on 30k units + 20k max range
                if (dist > (65000.f * 65000.f))
                {
                    continue;
                }   
            }
            
            amount++;
            allocSize += size;
        } while ((curGraphNode = curGraphNode->next) != firstNode);
    }

    int* content = (int*) main_pool_alloc(allocSize);
    gBatchNode->node.parent = (struct GraphNode*) content;
    *content = amount;

    // Pass 2: copy in the data
    {
        void* buf = (void*) ((u8*) content + sizeof(int));
        struct GraphNode *firstNode = gBatchNode->node.children;
        struct GraphNode *curGraphNode = firstNode;
        struct GraphNode** pnext = NULL;
        do
        {
            struct GraphNodeLvlTranslationRotation* lvlNode = NULL;
            int copySize = 0;
            int freshNodeSize = 0;
            switch (curGraphNode->type)
            {
                case GRAPH_NODE_TYPE_LVL_TRANSLATION_ROTATION_COLD:
                    copySize = sizeof(struct GraphNode);
                    freshNodeSize = sizeof(struct LightGraphLvlNodeTranslationRotation);
                    lvlNode = (struct GraphNodeLvlTranslationRotation*) curGraphNode;
                    break;
                case GRAPH_NODE_TYPE_LVL_TRANSLATION_COLD:
                    copySize = sizeof(struct GraphNode);
                    freshNodeSize = sizeof(struct LightGraphLvlNodeTranslation);
                    lvlNode = (struct GraphNodeLvlTranslationRotation*) curGraphNode;
                    break;
                case GRAPH_NODE_TYPE_GENERATED_LIST:
                    copySize = freshNodeSize = sizeof(struct GraphNodeGenerated);
                    break;
                case GRAPH_NODE_TYPE_SWITCH_CASE:
                    copySize = freshNodeSize = sizeof(struct GraphNodeSwitchCase);
                    break;
                case GRAPH_NODE_TYPE_TRANSLATION:
                    copySize = freshNodeSize = sizeof(struct GraphNodeTranslation);
                    break;
            }

            if (lvlNode)
            {
                f32 dx = lvlNode->translation[0] - areaX;
                f32 dy = lvlNode->translation[1] - areaY;
                f32 dz = lvlNode->translation[2] - areaZ;
                f32 dist = dx * dx + dy * dy + dz * dz;
                // this is incredibly far - the furthest point on 30k units (*sqrt(3)) + 20k max range
                if (dist > (65000.f * 65000.f))
                {
                    continue;
                }   
            }

            memcpy(buf, curGraphNode, copySize);
            struct GraphNode* freshNode = (struct GraphNode*) buf;
            freshNode->size = freshNodeSize;

            if (pnext)
            {
                *pnext = freshNode;
                pnext = NULL;
            }

            if (lvlNode)
            {
                struct LightGraphLvlNodeTranslationRotation* freshLvlNode = (struct LightGraphLvlNodeTranslationRotation*) freshNode;
                freshLvlNode->x = lvlNode->translation[0];
                freshLvlNode->y = lvlNode->translation[1];
                freshLvlNode->z = lvlNode->translation[2];
                if (GRAPH_NODE_TYPE_LVL_TRANSLATION_ROTATION_COLD == curGraphNode->type)
                {
                    freshLvlNode->rotation[0] = lvlNode->rotation[0];
                    freshLvlNode->rotation[1] = lvlNode->rotation[1];
                    freshLvlNode->rotation[2] = lvlNode->rotation[2];
                }
                freshNode->type += GRAPH_NODE_TYPE_LVL_TRANSLATION_ROTATION - GRAPH_NODE_TYPE_LVL_TRANSLATION_ROTATION_COLD;
                freshNode->parent = lvlNode->dl;
            }

            if (GRAPH_NODE_TYPE_GENERATED_LIST == curGraphNode->type)
            {
                pnext = &freshNode->next;
            }

            buf += freshNodeSize;
        } while ((curGraphNode = curGraphNode->next) != firstNode);
    }
}

u8* gCollisionStart = NULL;
void load_area(s32 index) {
    if (gCurrentArea == NULL && gAreaData[index].graphNode != NULL) {
        gCurrentArea = &gAreaData[index];
        gCurrAreaIndex = gCurrentArea->index;
        main_pool_pop_state();
        main_pool_push_state();

        warm_up_batch_node();
        gMarioCurrentRoom = 0;

        gCollisionStart = sMainPool.regions[0].start;
        if (gCurrentArea->terrainData != NULL) {
            load_area_terrain(gCurrentArea->terrainData, gCurrentArea->surfaceRooms);
        }

        if (gCurrentArea->objectSpawnInfos != NULL) {
            spawn_objects_from_info(0, gCurrentArea->objectSpawnInfos);
        }

        geo_call_global_function_nodes(&gCurrentArea->graphNode->node, GEO_CONTEXT_AREA_LOAD);
    }
}

void unload_area(void) {
    if (gCurrentArea != NULL) {
        unload_objects_from_area(0, gCurrentArea->index);
        geo_call_global_function_nodes(&gCurrentArea->graphNode->node, GEO_CONTEXT_AREA_UNLOAD);

        gCurrentArea->flags = AREA_FLAG_UNLOAD;
        gCurrentArea = NULL;
        gWarpTransition.isActive = FALSE;
    }
}

void load_mario_area(void) {
    stop_sounds_in_continuous_banks();
    load_area(gMarioSpawnInfo->areaIndex);

    if (gCurrentArea->index == gMarioSpawnInfo->areaIndex) {
        gCurrentArea->flags |= AREA_FLAG_LOAD;
        spawn_objects_from_info(0, gMarioSpawnInfo);
    }

#if 0
    if (gAreaSkyboxStart[gCurrAreaIndex - 1]) {
        load_segment_decompress(SEGMENT_SKYBOX, gAreaSkyboxStart[gCurrAreaIndex - 1], gAreaSkyboxEnd[gCurrAreaIndex - 1]);
    }
#endif
}

void unload_mario_area(void) {
    if ((gCurrentArea != NULL) && (gCurrentArea->flags & AREA_FLAG_LOAD)) {
        unload_objects_from_area(0, gMarioSpawnInfo->activeAreaIndex);

        gCurrentArea->flags &= ~AREA_FLAG_LOAD;
        if (gCurrentArea->flags == AREA_FLAG_UNLOAD) {
            unload_area();
        }
    }
}

void change_area(s32 index) {
    s32 areaFlags = gCurrentArea->flags;

    if (gCurrAreaIndex != index) {
        unload_area();
        load_area(index);

        gCurrentArea->flags = areaFlags;
        gMarioObject->oActiveParticleFlags = ACTIVE_PARTICLE_NONE;
    }

    if (areaFlags & AREA_FLAG_LOAD) {
        gMarioObject->header.gfx.areaIndex = index, gMarioSpawnInfo->areaIndex = index;
    }
}

void area_update_objects(void) {
    gAreaUpdateCounter++;
    update_objects(0);
}

/*
 * Sets up the information needed to play a warp transition, including the
 * transition type, time in frames, and the RGB color that will fill the screen.
 */
void play_transition(s16 transType, s16 time, Color red, Color green, Color blue) {
#ifndef L3DEX2_ALONE
    gWarpTransition.isActive = TRUE;
    gWarpTransition.type = transType;
    gWarpTransition.time = time;
    gWarpTransition.pauseRendering = FALSE;

    // The lowest bit of transType determines if the transition is fading in or out.
    if (transType & WARP_TRANSITION_FADE_INTO) {
        set_warp_transition_rgb(red, green, blue);
    } else {
        red = gWarpTransRed, green = gWarpTransGreen, blue = gWarpTransBlue;
    }

    if (transType & WARP_TRANSITION_TYPE_COLOR) {
        gWarpTransition.data.red = red;
        gWarpTransition.data.green = green;
        gWarpTransition.data.blue = blue;
    } else { // if transition is textured
        set_and_reset_transition_fade_timer(0); // Reset transition timers by passing in 0 for time

        gWarpTransition.data.red = red;
        gWarpTransition.data.green = green;
        gWarpTransition.data.blue = blue;

        // Both the start and end textured transition are always located in the middle of the screen.
        // If you really wanted to, you could place the start at one corner and the end at
        // the opposite corner. This will make the transition image look like it is moving
        // across the screen.
        gWarpTransition.data.startTexX = SCREEN_CENTER_X;
        gWarpTransition.data.startTexY = SCREEN_CENTER_Y;
        gWarpTransition.data.endTexX = SCREEN_CENTER_X;
        gWarpTransition.data.endTexY = SCREEN_CENTER_Y;

        gWarpTransition.data.angleSpeed = DEGREES(0);

        s16 fullRadius = GFX_DIMENSIONS_FULL_RADIUS;

#ifdef POLISHED_TRANSITIONS
        switch (transType){
            case WARP_TRANSITION_TYPE_BOWSER:
            case WARP_TRANSITION_FADE_INTO_BOWSER:
                fullRadius *= 4;
            break;

            case WARP_TRANSITION_FADE_FROM_MARIO:
            case WARP_TRANSITION_FADE_INTO_MARIO:

            case WARP_TRANSITION_FADE_FROM_STAR:
            case WARP_TRANSITION_FADE_INTO_STAR:
                fullRadius *= 1.5f;
            break;
        }
#endif

        if (transType & WARP_TRANSITION_FADE_INTO) { // Is the image fading in?
            gWarpTransition.data.startTexRadius = fullRadius;
            gWarpTransition.data.endTexRadius = 0;

        } else { // The image is fading out. (Reverses start & end circles)
            gWarpTransition.data.startTexRadius = 0;
            gWarpTransition.data.endTexRadius = fullRadius;
        }
    }
#endif
}

/*
 * Sets up the information needed to play a warp transition, including the
 * transition type, time in frames, and the RGB color that will fill the screen.
 * The transition will play only after a number of frames specified by 'delay'
 */
void play_transition_after_delay(s16 transType, s16 time, u8 red, u8 green, u8 blue, s16 delay) {
    gWarpTransDelay = delay; // Number of frames to delay playing the transition.
    play_transition(transType, time, red, green, blue);
}

extern int gQuickLookups;
extern int gSlowLookups;

u8 gWaterTutorial;
extern void shade_screen_yellow(void);
extern void shade_screen_yellow_alight(void);
void render_game(void) {
    PROFILER_GET_SNAPSHOT_TYPE(PROFILER_DELTA_COLLISION);
    if (gCurrentArea != NULL && !gWarpTransition.pauseRendering) {
        if (gCurrLevelNum == LEVEL_CCK)
            shade_screen_yellow_alight();

        if (gCurrentArea->graphNode) {
            geo_process_root(gCurrentArea->graphNode, gViewportOverride, gViewportClip, gFBSetColor);
        }
#ifdef PUPPYPRINT
        bzero(gCurrEnvCol, sizeof(ColorRGBA));
#endif

        gSPViewport(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gViewport));
        if (gCurrLevelNum == LEVEL_CCK)
            shade_screen_yellow();
        render_hud();

        if (gWaterTutorial && gWaterTutorial < 255)
        {
            if (gWaterTutorial != 230)
                gWaterTutorial++;

            gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
            if (gWaterTutorial < 120)
            {
                gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, CLAMP((int) gWaterTutorial * 16, 0, 255));
            }
            else
            {
                gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, CLAMP((int) (255 - gWaterTutorial) * 16, 0, 255));
            }
            
            print_generic_string_aligned(150, 40, "In water press A to go up, B to go down", TEXT_ALIGN_CENTER);
            gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

            if (gPlayer1Controller->buttonPressed & (A_BUTTON | B_BUTTON))
            {
                gWaterTutorial = 231;
            }
        }

        render_text_labels();
#ifdef PUPPYPRINT
        puppyprint_print_deferred();
#endif
        do_cutscene_handler();
        print_displaying_credits_entry();
        gMenuOptSelectIndex = render_menus_and_dialogs();

        if (gMenuOptSelectIndex != 0) {
            gSaveOptSelectIndex = gMenuOptSelectIndex;
        }

        if (gViewportClip != NULL) {
            make_viewport_clip_rect(gViewportClip);
        }

        if (gWarpTransition.isActive) {
            if (gWarpTransDelay == 0) {
                gWarpTransition.isActive = !render_screen_transition(gWarpTransition.type, gWarpTransition.time,
                                                                     &gWarpTransition.data);
                if (!gWarpTransition.isActive) {
                    if (gWarpTransition.type & WARP_TRANSITION_FADE_INTO) {
                        gWarpTransition.pauseRendering = TRUE;
                    } else {
                        set_warp_transition_rgb(0, 0, 0);
                    }
                }
            } else {
                gWarpTransDelay--;
            }
        }

// #define DEBUG_SURF
#ifdef DEBUG_SURF
        print_text_fmt_int(20, 20, "Q %d", gQuickLookups);
        print_text_fmt_int(20, 40, "S %d", gSlowLookups);
        gQuickLookups = 0;
        gSlowLookups = 0;
#endif

#ifdef S2DEX_TEXT_ENGINE
        s2d_init();

        // place any custom text engine code here if not using deferred prints

        s2d_handle_deferred();
        s2d_stop();
#endif
    } else {
        render_text_labels();
#ifdef PUPPYPRINT
        puppyprint_print_deferred();
#endif
        if (gViewportClip != NULL) {
            clear_viewport(gViewportClip, gWarpTransFBSetColor);
        } else {
            clear_framebuffer(gWarpTransFBSetColor);
        }
    }

    gViewportOverride = NULL;
    gViewportClip     = NULL;

    profiler_update(PROFILER_TIME_GFX, profiler_get_delta(PROFILER_DELTA_COLLISION) - first);
    profiler_print_times();
#ifdef PUPPYPRINT_DEBUG
    puppyprint_render_profiler();
#endif
}
