#include "macros.inc"
.set UCODE_SIZE, 0x800

.section .text

.balign 16
glabel gspF3DEX3_fifoTextStart
    .incbin "lib/PR/f3dex3/fifo/F3DEX3_BrZ_LVP_NOC.code"
glabel gspF3DEX3_fifoTextEnd

/* DATA SECTION START */

.section .data

.balign 16
glabel gspF3DEX3_fifoDataStart
    .incbin "lib/PR/f3dex3/fifo/F3DEX3_BrZ_LVP_NOC.data"
glabel gspF3DEX3_fifoDataEnd
