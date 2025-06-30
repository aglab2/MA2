#ifndef MAIN_H
#define MAIN_H

#include "config.h"

enum VIModes {
    MODE_NTSC,
    MODE_MPAL,
    MODE_PAL,
};

#define THREAD1_STACK 0x100
#define THREAD2_STACK 0x800
#define THREAD3_STACK 0x200
#define THREAD4_STACK 0x2000
#define THREAD5_STACK 0x2400
#define THREAD6_STACK 0x400

enum ThreadID {
    THREAD_0,
    THREAD_1_IDLE,
    THREAD_2_CRASH_SCREEN,
    THREAD_3_MAIN,
    THREAD_4_SOUND,
    THREAD_5_GAME_LOOP,
    THREAD_6_RUMBLE,
    THREAD_7_HVQM,
    THREAD_8_TIMEKEEPER,
    THREAD_9_DA_COUNTER,
};

struct RumbleData {
    u8  comm;
    u8  level;
    s16 time;
    s16 decay;
};

struct RumbleSettings {
    s16 event;
    s16 level;
    s16 timer;
    s16 count;
    s16 start;
    s16 slip;
    s16 vibrate;
    s16 decay;
};

extern struct Config gConfig __attribute__((section(".data")));

// extern OSThread gUnkThread;
extern OSThread gIdleThread __attribute__((section(".data")));
extern OSThread gMainThread __attribute__((section(".data")));
extern OSThread gGameLoopThread __attribute__((section(".data")));
extern OSThread gSoundThread __attribute__((section(".data")));
extern OSThread hvqmThread __attribute__((section(".data")));
#if ENABLE_RUMBLE
extern OSThread gRumblePakThread __attribute__((section(".data")));

extern OSPfs gRumblePakPfs __attribute__((section(".data")));
#endif

extern OSMesgQueue gPIMesgQueue __attribute__((section(".data")));
extern OSMesgQueue gIntrMesgQueue __attribute__((section(".data")));
extern OSMesgQueue gSPTaskMesgQueue __attribute__((section(".data")));
#if ENABLE_RUMBLE
extern OSMesgQueue gRumblePakSchedulerMesgQueue __attribute__((section(".data")));
extern OSMesgQueue gRumbleThreadVIMesgQueue __attribute__((section(".data")));
#endif
extern OSMesg gDmaMesgBuf[1] __attribute__((section(".data")));
extern OSMesg gPIMesgBuf[32] __attribute__((section(".data")));
extern OSMesg gSIEventMesgBuf[1] __attribute__((section(".data")));
extern OSMesg gIntrMesgBuf[16] __attribute__((section(".data")));
extern OSMesg gUnknownMesgBuf[16] __attribute__((section(".data")));
extern OSIoMesg gDmaIoMesg __attribute__((section(".data")));
extern OSMesg gMainReceivedMesg __attribute__((section(".data")));
extern OSMesgQueue gDmaMesgQueue __attribute__((section(".data")));
extern OSMesgQueue gSIEventMesgQueue __attribute__((section(".data")));
#if ENABLE_RUMBLE
extern OSMesg gRumblePakSchedulerMesgBuf[1] __attribute__((section(".data")));
extern OSMesg gRumbleThreadVIMesgBuf[1] __attribute__((section(".data")));

extern struct RumbleData gRumbleDataQueue[3] __attribute__((section(".data")));
extern struct RumbleSettings gCurrRumbleSettings __attribute__((section(".data")));
#endif

extern s8 gAudioEnabled __attribute__((section(".data")));
extern u32 gNumVblanks __attribute__((section(".data")));
extern s8 gResetTimer __attribute__((section(".data")));
extern s8 gNmiResetBarsTimer __attribute__((section(".data")));
extern s8 gDebugLevelSelect __attribute__((section(".data")));
#ifdef VANILLA_DEBUG
extern s8 gShowDebugText __attribute__((section(".data")));
#endif

// Special struct that keeps track of whether its timer has been set.
//  Without this check, there is a bug at high CPU loads in which
//  the RCP timer gets set twice and the game tries to
//  insert __osBaseTimer into a ring buffer that only contains itself,
//  causing a particularly messy crash.
typedef struct {
    u8 started;
    OSTimer timer;
} OSTimerEx;

void set_vblank_handler(s32 index, struct VblankHandler *handler, OSMesgQueue *queue, OSMesg *msg);
void dispatch_audio_sptask(struct SPTask *spTask);
void exec_display_list(struct SPTask *spTask);
void setgp();

#endif // MAIN_H
