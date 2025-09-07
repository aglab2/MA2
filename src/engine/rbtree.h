/*-------------------------------------------------------------------------
 *
 * rbtree.h
 *	  interface for PostgreSQL generic Red-Black binary tree package
 *
 * Copyright (c) 2009-2025, PostgreSQL Global Development Group
 *
 * IDENTIFICATION
 *		src/include/lib/rbtree.h
 *
 *-------------------------------------------------------------------------
 */

// Reworked by aglab2 to be used in inline functions and without memory allocation
// It also allows to have duplicated nodes by walking to the right in case of equality

#ifndef RBTREE_H
#define RBTREE_H

#include <types.h>

/*
 * RBTNode is intended to be used as the first field of a larger struct,
 * whose additional fields carry whatever payload data the caller needs
 * for a tree entry.  (The total size of that larger struct is passed to
 * rbt_create.)	RBTNode is declared here to support this usage, but
 * callers must treat it as an opaque struct.
 */

 // 0x8 in size
typedef union
{
    struct
    {
        s16 lowerY;
        s16 upperY;
        u8 lowerCellX;
        u8 lowerCellZ;
        u8 upperCellX;
        u8 upperCellZ;
    };
    u64 asU64;
} Bvh;

// Given value 0xff produces 0x88888888
static inline uint32_t morton_spread8(u32 v)
{
    uint32_t result = 0;
    int shift = 32 - 8;
    while (v & 0xff)
    {
        result |= (v & 0x80) << shift;
        shift -= 3;
        v <<= 1;
    }

    return result;
}

// Given value 0xffff produces 0xcccccccc
static inline uint32_t morton_spread16(u32 v)
{
    uint32_t result = 0;
    int shift = 32 - 8;
    while (v & 0xffff)
    {
        result |= (v & 0xc0) << shift;
        shift -= 3;
        v <<= 2;
    }

    return result;
}

static inline uint32_t morton(Bvh bvh) {
    // Get the center of the box
    u32 x = (bvh.lowerCellX + bvh.upperCellX) >> 1;
    u32 y = 0x8000 + ((bvh.lowerY + bvh.upperY) >> 1);
    u32 z = (bvh.lowerCellZ + bvh.upperCellZ) >> 1;

    // Spread the bits of each coordinate...
    u32 xs = morton_spread8 (x);
    u32 ys = morton_spread16(y);
    u32 zs = morton_spread8 (z);

    // ...and interleave them to produce the final Morton code
    return ys | (zs >> 2) | (xs >> 3);
}

struct Surface; // forward declare
typedef struct SurfaceNode
{
    // First 0x10 bytes is BVH + rbtree left/right
    Bvh nodeBvh;
	struct SurfaceNode *left;		/* left child, or RBTNIL if none */
	struct SurfaceNode *right;		/* right child, or RBTNIL if none */

    // Second 0x10 bytes is rest of rb mosh and surface info
    Bvh triBvh;
    u8 flags;
    TerrainData type;
    struct Surface *surf;

    // Third 0x10 bytes is rbtree building fields. TODO: mirror this to cold RAM
    uint32_t weight; // weight is a morton of middle of bvh
	struct SurfaceNode* parent;		/* parent, or NULL (not RBTNIL!) if none */
    char color;
} RBTNode;

/*
 * RBTreeIterator holds state while traversing a tree.  This is declared
 * here so that callers can stack-allocate this, but must otherwise be
 * treated as an opaque struct.
 */
typedef struct RBTreeIterator RBTreeIterator;

typedef struct RBTree
{
	RBTNode    *root;			/* root node, or RBTNIL if tree is empty */
} RBTree;

static inline void rbt_init(RBTree *rbt)
{
    rbt->root = NULL;
}

extern void rbt_insert(RBTree *rbt, RBTNode*);

extern RBTNode* rbt_left_right_iterator(RBTree *rbt, RBTreeIterator *iter);
struct RBTreeIterator
{
	RBTNode    *last_visited;
	int        is_over;
};

/*
 * rbt_begin_iterate: prepare to traverse the tree in any of several orders
 *
 * After calling rbt_begin_iterate, call rbt_iterate repeatedly until it
 * returns NULL or the traversal stops being of interest.
 *
 * If the tree is changed during traversal, results of further calls to
 * rbt_iterate are unspecified.  Multiple concurrent iterators on the same
 * tree are allowed.
 *
 * The iterator state is stored in the 'iter' struct.  The caller should
 * treat it as an opaque struct.
 */
static inline RBTreeIterator rbt_begin_iterate(RBTree *rbt)
{
	RBTreeIterator iter;
    iter.last_visited = NULL;
	iter.is_over = (rbt->root == NULL);
    return iter;
}

/*
 * rbt_iterate: return the next node in traversal order, or NULL if no more
 */
static inline RBTNode* rbt_iterate(RBTree *rbt, RBTreeIterator *iter)
{
	if (iter->is_over)
		return NULL;

	return rbt_left_right_iterator(rbt, iter);
}

#endif							/* RBTREE_H */