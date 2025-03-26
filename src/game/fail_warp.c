#include "fail_warp.h"

#include "behavior_data.h"
#include "game/area.h"
#include "game/level_update.h"
#include "game/mario.h"
#include "engine/math_util.h"

extern void set_camera_mode_8_directions(struct Camera *c);
extern s16 s8DirModeYawOffset;

#define bool char

static int sSafePosArea;
static int sSafePosLevel;
static Vec3s sSafePos = {};
static s16 sSafePosAngle;
static s16 sSafePosCameraYaw;

u8 sSafeWarpId;

static void* sCheckpointNodes[16];

static int sSafe2PosArea;
static int sSafe2PosLevel;
static Vec3s sSafe2Pos;
static s16 sSafe2PosAngle;
static s16 sSafe2PosCameraYaw;

static s16 sCamAngleToSet;

static void fail_warp_set_safe_pos2(f32* pos, s16 angle, s16 camAngle, int areaIndex, int levelNum)
{
    sSafe2Pos[0] = pos[0];
    sSafe2Pos[1] = pos[1];
    sSafe2Pos[2] = pos[2];
    sSafe2PosAngle = angle;
    sSafe2PosCameraYaw = camAngle;
    sSafe2PosArea = areaIndex;
    sSafe2PosLevel = levelNum;
}

void fail_warp_set_safe_pos(f32* pos, s16 angle, int areaIndex, int levelNum)
{
    fail_warp_set_safe_pos2(pos, angle, angle + 0x8000, areaIndex, levelNum);

    sSafePos[0] = pos[0];
    sSafePos[1] = pos[1];
    sSafePos[2] = pos[2];
    sSafePosAngle = angle;
    sSafePosCameraYaw = angle + 0x8000;
    sSafePosArea = areaIndex;
    sSafePosLevel = levelNum;
    sSafeWarpId = WARP_NODE_FAIL_WARP;
}

extern s16 sDelayedWarpOp;

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

    if (sDelayedWarpOp != WARP_OP_NONE)
        return;

    m->extraGravityEnabled = 0;
    m->extraAirAction = 0;
    s16 type = floor->type;
    if (!SURFACE_IS_UNSAFE(type) && type != SURFACE_DEATH_PLANE && type != SURFACE_VERY_SLIPPERY && absf(floor->normal.y) >= 0.8f)
    {
        return fail_warp_set_safe_pos2(m->pos, m->faceAngle[1], s8DirModeYawOffset, gCurrAreaIndex, gCurrLevelNum);
    }
}

static struct ObjectWarpNode sSpoofedWarpNode = { };
struct Object gFailWarpSpoofedWarpObject = { };
struct ObjectWarpNode* fail_warp_area_get_warp_node(int id)
{
    if (id == WARP_NODE_FAIL_WARP)
    {
        sSpoofedWarpNode.node.id = WARP_NODE_FAIL_WARP;
        sSpoofedWarpNode.node.destLevel = sSafePosLevel;
        sSpoofedWarpNode.node.destArea = sSafePosArea;
        sSpoofedWarpNode.node.destNode = WARP_NODE_FAIL_WARP;
        sSpoofedWarpNode.next = NULL;
        gFailWarpSpoofedWarpObject.oPosX = sSafePos[0];
        gFailWarpSpoofedWarpObject.oPosY = sSafePos[1];
        gFailWarpSpoofedWarpObject.oPosZ = sSafePos[2];
        gFailWarpSpoofedWarpObject.oFaceAngleYaw = sSafePosAngle;
        gFailWarpSpoofedWarpObject.oMoveAngleYaw = sSafePosAngle;
        gFailWarpSpoofedWarpObject.behavior = bhvCheckpoint;
        
        return &sSpoofedWarpNode;
    }
    else if (id == WARP_NODE_FAIL_WARP2)
    {
        sSpoofedWarpNode.node.id = WARP_NODE_FAIL_WARP2;
        sSpoofedWarpNode.node.destLevel = sSafe2PosLevel;
        sSpoofedWarpNode.node.destArea = sSafe2PosArea;
        sSpoofedWarpNode.node.destNode = WARP_NODE_FAIL_WARP2;
        sSpoofedWarpNode.next = NULL;
        gFailWarpSpoofedWarpObject.oPosX = sSafe2Pos[0];
        gFailWarpSpoofedWarpObject.oPosY = sSafe2Pos[1];
        gFailWarpSpoofedWarpObject.oPosZ = sSafe2Pos[2];
        gFailWarpSpoofedWarpObject.oFaceAngleYaw = sSafe2PosAngle;
        gFailWarpSpoofedWarpObject.oMoveAngleYaw = sSafe2PosAngle;
        gFailWarpSpoofedWarpObject.behavior = bhvCheckpoint;
        
        return &sSpoofedWarpNode;
    }
    else
    {
        return sCheckpointNodes[id - 0xe0];
    }
}

static void spoof_warp(struct MarioState *m)
{
    m->usedObj = &gFailWarpSpoofedWarpObject;
    gFailWarpSpoofedWarpObject.oBehParams = sSafeWarpId << 16;
    gFailWarpSpoofedWarpObject.oBehParams2ndByte = sSafeWarpId;
}

static void spoof_warp2(struct MarioState* m)
{
    m->usedObj = &gFailWarpSpoofedWarpObject;
    gFailWarpSpoofedWarpObject.oBehParams = WARP_NODE_FAIL_WARP2 << 16;
    gFailWarpSpoofedWarpObject.oBehParams2ndByte = WARP_NODE_FAIL_WARP2;
}

s32 fail_warp_pre_level_trigger_warp(struct MarioState *m, s32* warpOp)
{
    if (!sSafeWarpId)
        return 0;

    s32 warpOpOg = *warpOp;
    if (warpOpOg != WARP_OP_DEATH && warpOpOg != WARP_OP_WARP_FLOOR)
    {
        return 0;
    }

    m->health = (m->health & (~0xff)) + 0x80;
    if ((m->action == ACT_BURNING_JUMP) || (m->action == ACT_BURNING_FALL) || (m->action == ACT_BURNING_GROUND))
    {
        drop_and_set_mario_action(m, ACT_FREEFALL, 0);
    }

    *warpOp = WARP_OP_TELEPORT;
    if (warpOpOg == WARP_OP_WARP_FLOOR && (gCurrCourseNum == COURSE_FR || (gCurrCourseNum == COURSE_CG && gCurrAreaIndex == 3)))
    {
        sCamAngleToSet = sSafe2PosCameraYaw;
        spoof_warp2(m);
        return 0;
    }
    else
    {
        sCamAngleToSet = sSafePosCameraYaw;
        spoof_warp(m);
        return 1;    
    }
}

void fail_warp_init_mario_after_quick_warp(struct MarioState *m)
{
    set_mario_action(m, ACT_IDLE, 0);
    struct Camera* camera = gCurrentArea->camera;
    set_camera_mode_8_directions(camera);
    reset_camera(camera);
    s8DirModeYawOffset = sCamAngleToSet & 0xe000;
    // makes paracam not trigger after escaping water
    // *((u32*) 0x80286d20) = 0x80286CC4U;
}

void fail_warp_init_mario_after_quick_warp_reset_camera()
{
    s8DirModeYawOffset = sCamAngleToSet & 0xe000;
    gMarioStates->invincTimer = 120;
}

s16 fail_warp_trigger(struct MarioState* m)
{
    sCamAngleToSet = sSafe2PosCameraYaw;
    spoof_warp2(m);
    return level_trigger_warp(m, WARP_OP_TELEPORT);
}

void fail_warp_register_checkpoint_node(void* node, int id)
{
    sCheckpointNodes[id - 0xe0] = node;
}
