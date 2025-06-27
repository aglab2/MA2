#ifndef MEMORY_H
#define MEMORY_H

#include <PR/ultratypes.h>

#include "memory_layout.h"
#include "types.h"

#define NUM_TLB_SEGMENTS 32

struct MemoryPool;

struct OffsetSizePair {
    u32 offset;
    u32 size;
};

struct DmaTable {
    u32 count;
    u8 *srcAddr;
    struct OffsetSizePair anim[1]; // dynamic size
};

struct DmaHandlerList {
    struct DmaTable *dmaTable;
    void *currentAddr;
    void *bufTarget;
};

#define EFFECTS_MEMORY_POOL 0x4000

extern struct MemoryPool *gEffectsMemoryPool;

uintptr_t set_segment_base_addr(s32 segment, void *addr);
void *get_segment_base_addr(s32 segment)  __attribute__ ((pure));
void *segmented_to_virtual(const void *addr) __attribute__ ((pure));
void *virtual_to_segmented(u32 segment, const void *addr);
void move_segment_table_to_dmem(void);

struct MainPoolRegion {
    u8* start;
    u8* end;
};

#define MAIN_POOL_REGIONS_COUNT 3

struct MainPoolContext {
    struct MainPoolRegion regions[MAIN_POOL_REGIONS_COUNT];
};

extern struct MainPoolContext sMainPool;
#define gMainPoolCurrentRegion (&sMainPool.regions[0])

#define MAIN_POOL_ALIGNMENT_DISABLE -1
#define MAIN_POOL_ALLOC_TRY TRUE
#define MAIN_POOL_ALLOC_FORCE FALSE

// takes the first 'size' bytes from 'region'
static ALWAYS_INLINE void* main_pool_region_alloc_from_start(struct MainPoolRegion* region, u32 size, s32 alignment, int try) {
    u8* ret = alignment < 0 ? region->start : (u8*) ALIGN(region->start, alignment);
    u8* newStart = ret + size;
    if (try) {
        if (newStart > region->end)
            return NULL;
    }

    region->start = newStart;
    if (!ret) __builtin_unreachable();
    return ret;
}

/*
 Main Pool is a trivial allocator that is managing multiple 'regions' of memory.
 'Region' is a contiguous block of memory available for main pool use.
 For example, whe MEMORY_FRAGMENTATION_LEVEL 10 is used, there are 2 'regions':
 from engine end to zbuffer start and after framebuffer end to RAM end.
 It behaves similarly to an array of AllocOnly pools from vanilla SM64 by
 "cutting" the start of the "region" when an allocation is made and returning the
 pointer to the start of the initial "region".
 */
void main_pool_init(void);

static ALWAYS_INLINE void *main_pool_alloc(u32 size) {
    void* buf = main_pool_region_alloc_from_start(gMainPoolCurrentRegion, ALIGN4(size), MAIN_POOL_ALIGNMENT_DISABLE, MAIN_POOL_ALLOC_FORCE);
    if (!buf) __builtin_unreachable();
    return buf;
}

void *main_pool_alloc_ex(int region, u32 size, s32 alignment);
static inline void *main_pool_alloc_aligned(int region, u32 size, s32 alignment)
{
    if (!alignment)
        alignment = 16;

    void* buf = main_pool_alloc_ex(region, ALIGN4(size), alignment);
    if (!buf) __builtin_unreachable();
    return buf;
}

static inline void* main_pool_alloc_lowprio(u32 size)
{
    return main_pool_alloc_ex(1, size, MAIN_POOL_ALIGNMENT_DISABLE);
}

/*
 Main pool also provides a way to free the latest allocated memory for temporary memory use.
 In vanilla SM64, 'right side' alloc is used for it. This implementation abstracts it to 'main_pool_alloc_freeable'
 that behaves very similarly. Notice that 'main_pool_alloc_freeable' has overhead so
 it is recommended to use it only when necessary. Common usecase is a
 temporary buffer that is allocated, used and freed in the same function.
*/

void *main_pool_alloc_freeable(int region, u32 size, u32 alignment);
void main_pool_free(void *addr);

/*
 Main pool provides an ability to push/pop the current state of the allocator.
 For example, it is used by SM64 to allocate data bank buffers.
 Common usecase in levelscript is
 1) Push the state using 'main_pool_push_state'
 2) Use 'main_pool_alloc' to allocate data bank buffers
 3) When unnecessary, free all the data bank buffers at once using 'main_pool_pop_state'
 */
void main_pool_push_state(void);
void main_pool_pop_state(void);

/*
 Main pool provides an ability to get the current available memory.
 This is useful for debugging purposes. Please do not attempt to use this
 to predict the memory layout as regions in main pool might not be contiguous.
 */
u32 main_pool_available(void);

void main_pool_cut_graphics_pool();

#ifndef NO_SEGMENTED_MEMORY
void *load_segment(s32 segment, u8 *srcStart, u8 *srcEnd, u8 *bssStart, u8 *bssEnd);
void *load_to_fixed_pool_addr(u8 *destAddr, u8 *srcStart, u8 *srcEnd);
void *load_segment_decompress(s32 segment, u8 *srcStart, u8 *srcEnd);
#else
#define load_segment(...)
#define load_to_fixed_pool_addr(...)
#define load_segment_decompress(...)
#define load_engine_code_segment(...)
#endif

struct MemoryPool *mem_pool_init(u32 size);
void *mem_pool_alloc(struct MemoryPool *pool, u32 size);
void mem_pool_free(struct MemoryPool *pool, void *addr);

extern u8 *gGfxPoolEnd;
#if 0
static inline void *alloc_display_list(u32 size) {
    size = ALIGN8(size);
    gGfxPoolEnd -= size;
    void* ptr = gGfxPoolEnd;
    if (!ptr) __builtin_unreachable();
    return ptr;
}
#define main_pool_alloc_aligned_cde main_pool_alloc
#else
#define main_pool_alloc_aligned_cde(_size) ({ \
    struct MainPoolRegion* region = gMainPoolCurrentRegion; \
    u32 size = ALIGN16(_size); \
    u8* ptr = region->start; \
    if (__builtin_constant_p(_size)) { \
        switch (size) { \
            case 0x0: \
                break; \
            case 0x10: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                break; \
            case 0x20: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                break; \
            case 0x30: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                break; \
            case 0x40: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                break; \
            case 0x50: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                __builtin_mips_cache(0xd, ptr + 0x40); \
                break; \
            case 0x60: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                __builtin_mips_cache(0xd, ptr + 0x40); \
                __builtin_mips_cache(0xd, ptr + 0x50); \
                break; \
            case 0x70: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                __builtin_mips_cache(0xd, ptr + 0x40); \
                __builtin_mips_cache(0xd, ptr + 0x50); \
                __builtin_mips_cache(0xd, ptr + 0x60); \
                break; \
            case 0x80: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                __builtin_mips_cache(0xd, ptr + 0x40); \
                __builtin_mips_cache(0xd, ptr + 0x50); \
                __builtin_mips_cache(0xd, ptr + 0x60); \
                __builtin_mips_cache(0xd, ptr + 0x70); \
                break; \
            default: \
                break; \
        } \
    } \
    u8* newStart = ptr + size; \
    region->start = newStart; \
    if (!ptr) __builtin_unreachable(); \
    (void*) ptr; \
})

#define alloc_display_list(_size) ({\
    u32 size = ALIGN16(_size); \
    void* ptr = gGfxPoolEnd - size; \
    if (__builtin_constant_p(_size)) { \
        switch (size) { \
            case 0x0: \
                break; \
            case 0x10: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                break; \
            case 0x20: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                break; \
            case 0x30: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                break; \
            case 0x40: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                break; \
            case 0x50: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                __builtin_mips_cache(0xd, ptr + 0x40); \
                break; \
            case 0x60: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                __builtin_mips_cache(0xd, ptr + 0x40); \
                __builtin_mips_cache(0xd, ptr + 0x50); \
                break; \
            case 0x70: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                __builtin_mips_cache(0xd, ptr + 0x40); \
                __builtin_mips_cache(0xd, ptr + 0x50); \
                __builtin_mips_cache(0xd, ptr + 0x60); \
                break; \
            case 0x80: \
                __builtin_mips_cache(0xd, ptr + 0x0); \
                __builtin_mips_cache(0xd, ptr + 0x10); \
                __builtin_mips_cache(0xd, ptr + 0x20); \
                __builtin_mips_cache(0xd, ptr + 0x30); \
                __builtin_mips_cache(0xd, ptr + 0x40); \
                __builtin_mips_cache(0xd, ptr + 0x50); \
                __builtin_mips_cache(0xd, ptr + 0x60); \
                __builtin_mips_cache(0xd, ptr + 0x70); \
                break; \
            default: \
                break; \
        } \
    } \
    gGfxPoolEnd = ptr; \
    if (!ptr) __builtin_unreachable(); \
    if (0 != (((uintptr_t) ptr) & 0xf)) __builtin_unreachable(); \
    (void*) ptr; \
})
#endif

void setup_dma_table_list(struct DmaHandlerList *list, void *srcAddr, void *buffer);
s32 load_patchable_table(struct DmaHandlerList *list, s32 index);


extern uintptr_t sSegmentROMTable[32];

extern uintptr_t sSegmentROMTable[32];
#endif // MEMORY_H
