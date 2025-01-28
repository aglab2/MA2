#include "fail_warp.h"

#include "behavior_data.h"
#include "game/area.h"
#include "game/level_update.h"
#include "game/mario.h"

extern void set_camera_mode_8_directions(struct Camera *c);
extern s16 s8DirModeYawOffset;

#define bool char

static int sSafePosArea = 0;
static int sSafePosLevel = 0;
static Vec3s sSafePos = {};
static s16 sSafePosAngle;
static s16 sSafePosCameraYaw;

static void fail_warp_set_safe_pos(struct MarioState *m)
{
    // print_text_fmt_int(20, 20, "X %d", (int) m->pos[0]);
    // print_text_fmt_int(20, 40, "Y %d", (int) m->pos[1]);
    // print_text_fmt_int(20, 60, "Z %d", (int) m->pos[2]);
    sSafePos[0] = m->pos[0];
    sSafePos[1] = m->pos[1];
    sSafePos[2] = m->pos[2];
    sSafePosAngle = m->faceAngle[1];
    sSafePosCameraYaw = s8DirModeYawOffset;
    sSafePosArea = gCurrAreaIndex;
    sSafePosLevel = gCurrLevelNum;
    m->extraGravityEnabled = 0;
}

void fail_warp_mario_set_safe_pos(struct MarioState *m, struct Surface *floor)
{
    // print_text(20, 80, "POS CHECK");
    // print_text_fmt_int(20, 100, "FLOOR %x", ((int) floor) & 0xffffff);
    m->floorHeight = m->pos[1];
    if (!floor)
        return;

    // object generated floors might be unsafe so avoid them
    if (floor->object)
        return;

    if (sSafePosArea != gCurrAreaIndex || sSafePosLevel != gCurrLevelNum) 
    {
        return fail_warp_set_safe_pos(m);
    }
    
    bool slideTerrain = (m->area->terrainType & TERRAIN_MASK) == TERRAIN_SLIDE;
    if (slideTerrain)
        return;

    s16 type = floor->type;
    if (!SURFACE_IS_UNSAFE(type) && type != SURFACE_VERY_SLIPPERY && floor->normal.y >= 0.8f)
    {
        return fail_warp_set_safe_pos(m);
    }
}

static struct ObjectWarpNode sSpoofedWarpNode = { };
struct Object gFailWarpSpoofedWarpObject = { };
struct ObjectWarpNode* fail_warp_area_get_warp_node(void)
{
    sSpoofedWarpNode.node.id = WARP_NODE_FAIL_WARP;
    sSpoofedWarpNode.node.destLevel = gCurrLevelNum;
    sSpoofedWarpNode.node.destArea = gCurrAreaIndex;
    sSpoofedWarpNode.node.destNode = WARP_NODE_FAIL_WARP;
    sSpoofedWarpNode.next = NULL;
    gFailWarpSpoofedWarpObject.oPosX = sSafePos[0];
    gFailWarpSpoofedWarpObject.oPosY = sSafePos[1];
    gFailWarpSpoofedWarpObject.oPosZ = sSafePos[2];
    gFailWarpSpoofedWarpObject.oFaceAngleYaw = sSafePosAngle;
    gFailWarpSpoofedWarpObject.oMoveAngleYaw = sSafePosAngle;
    gFailWarpSpoofedWarpObject.behavior = bhvInstantActiveWarp;
    
    return &sSpoofedWarpNode;
}

static void spoof_warp(struct MarioState *m)
{
    m->usedObj = &gFailWarpSpoofedWarpObject;
    gFailWarpSpoofedWarpObject.oBehParams = WARP_NODE_FAIL_WARP << 16;
    gFailWarpSpoofedWarpObject.oBehParams2ndByte = WARP_NODE_FAIL_WARP;
}

void fail_warp_pre_level_trigger_warp(struct MarioState *m, s32* warpOp)
{
    int damage = 0;
    if (*warpOp != WARP_OP_DEATH && *warpOp != WARP_OP_WARP_FLOOR)
    {
        return;
    }

    damage = 0x400;
    if (m->health <= damage + 0x80)
        return;

    m->health = (m->health & (~0xff)) + 0x80;
    if ((m->action == ACT_BURNING_JUMP) || (m->action == ACT_BURNING_FALL) || (m->action == ACT_BURNING_GROUND))
    {
        drop_and_set_mario_action(m, ACT_FREEFALL, 0);
    }

    m->hurtCounter = damage / 0x40;
    *warpOp = WARP_OP_TELEPORT;
    spoof_warp(m);
}

void fail_warp_init_mario_after_quick_warp(struct MarioState *m)
{
    set_mario_action(m, ACT_IDLE, 0);
    struct Camera* camera = gCurrentArea->camera;
    set_camera_mode_8_directions(camera);
    reset_camera(camera);
    s8DirModeYawOffset = sSafePosCameraYaw & 0xe000;
    // makes paracam not trigger after escaping water
    // *((u32*) 0x80286d20) = 0x80286CC4U;

    bool slideTerrain = (m->area->terrainType & TERRAIN_MASK) == TERRAIN_SLIDE;
    if (slideTerrain)
        level_control_timer(TIMER_CONTROL_HIDE);
}

void fail_warp_init_mario_after_quick_warp_reset_camera(struct Object* spawnObject)
{
    if (spawnObject != &gFailWarpSpoofedWarpObject)
    {
        reset_camera(gCurrentArea->camera);
        s8DirModeYawOffset = (gMarioStates->faceAngle[1] + 0x9000) & 0xe000;
    }
}

void fail_warp_trigger(struct MarioState* m)
{
    spoof_warp(m);
    level_trigger_warp(m, WARP_OP_TELEPORT);
}
