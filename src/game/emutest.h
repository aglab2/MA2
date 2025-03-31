#ifndef EMUTEST_H
#define EMUTEST_H

#include "types.h"

enum Emulator {
    EMU_CONSOLE              = (1 << 0), // Also detects emulators accurate enough to emulate DPC registers
    EMU_WIIVC                = (1 << 1),
    EMU_PROJECT64_1_OR_2     = (1 << 2), // PJ64 1.6 to 2.3
    EMU_PROJECT64_3          = (1 << 3), // PJ64 2.4 to 3.0
        EMU_PROJECT64        = (EMU_PROJECT64_1_OR_2 | EMU_PROJECT64_3),
    EMU_MUPEN                = (1 << 4), // Also includes pre-2.12 ParallelN64
    EMU_PARALLEL_LAUNCHER    = (1 << 5), // Parallel Launcher (ParallelN64 core only)
    EMU_OTHER                = (1 << 6), // Any other emulator
};

extern u32 detect_emulator();

extern u8 gHasEmulator;
extern u8 gHasInstantInput;
extern u8 gHasPerformance;
extern u8 gIsVC;
#if 0
extern u8 gHasEX3;
#else
#define gHasEX3 1
#endif

#define gIsConsole !gHasEmulator

#endif
