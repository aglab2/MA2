#pragma once

struct FlipbookData
{
    // id of the batch that used for flipbook
    u16 batchId;

    // amount of flips in the flipbook
    // if amount is 0, ci4s+pals is interpreted as prim color shading
    u8 count;
    // amount of frames in each flip
    u8 frames;
    // speed of tile scrolling on X
    s8 tileScrollX;
    // speed of tile scrolling on Y
    s8 tileScrollY;

    u16 shading;

    // the flipbook data, 2048 bytes per flip
    u8* ci4s;
    // the flipbook palette, 32 bytes per flip
    u8* pals;
};

#define FLIPBOOK_LAYER_DECL(name) { sizeof(name) / sizeof(*name), name } 
