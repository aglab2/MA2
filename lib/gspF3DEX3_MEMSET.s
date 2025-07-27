#include "macros.inc"
.set UCODE_SIZE, 0x800

.section .text

.balign 16
glabel gspF3DEX3_MEMSET_fifoTextStart
    .incbin "lib/PR/f3dex3/fifo/F3DEX3_BrZ_LVP_NOC_MEMSET.code"
glabel gspF3DEX3_MEMSET_fifoTextEnd

/* DATA SECTION START */

.section .data

.balign 16
glabel gspF3DEX3_MEMSET_fifoDataStart
    .incbin "lib/PR/f3dex3/fifo/F3DEX3_BrZ_LVP_NOC_MEMSET.data"
glabel gspF3DEX3_MEMSET_fifoDataEnd
