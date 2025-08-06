#include "macros.inc"
.set UCODE_SIZE, 0x800

.section .text

.balign 16
glabel gspF3DEX3_TEXCACHE_fifoTextStart
    .incbin "lib/PR/f3dex3/fifo/F3DEX3_BrZ_LVP_NOC_TEXCACHE.code"
glabel gspF3DEX3_TEXCACHE_fifoTextEnd

/* DATA SECTION START */

.section .data

.balign 16
glabel gspF3DEX3_TEXCACHE_fifoDataStart
    .incbin "lib/PR/f3dex3/fifo/F3DEX3_BrZ_LVP_NOC_TEXCACHE.data"
glabel gspF3DEX3_TEXCACHE_fifoDataEnd
