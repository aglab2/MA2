#include "macros.inc"
.set UCODE_SIZE, 0x800

.section .text


/* Audio Bins */

/*
 * "What the heck is this?"
 * Shindou is the only version to actually edit the audio microcode, so I had to do this sorry lol
 */

.balign 16
glabel SHaspMainTextStart
    .incbin "lib/PR/audio/audio.code"
glabel SHaspMainTextEnd

/* DATA SECTION START */

.section .data

/* Audio Data */

.balign 16
glabel SHaspMainDataStart
    .incbin "lib/PR/audio/audio.data"
glabel SHaspMainDataEnd
