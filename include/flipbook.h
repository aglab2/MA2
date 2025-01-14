#pragma once

struct FlipbookData
{
    // id of the batch that used for flipbook
    u16 batchId;
    // amount of flips in the flipbook
    u8 count;
    // amount of frames in each flip
    u8 frames;
    // the flipbook data, 2048 bytes per flip
    u8* ci4s;
    // the flipbook palette, 32 bytes per flip
    u8* pals;
};

#define FLIPBOOK_LAYER_DECL(name) { sizeof(name) / sizeof(*name), name } 