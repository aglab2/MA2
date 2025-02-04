#include "macros.inc"
.section .text

.balign 16
glabel rspbootTextStart
    .incbin "rsp/rspboot.bin"
.balign 16
glabel rspbootTextEnd
