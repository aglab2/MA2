/*
 * pairingheap.h
 *
 * A Pairing Heap implementation
 *
 * Portions Copyright (c) 2012-2025, PostgreSQL Global Development Group
 *
 * src/include/lib/pairingheap.h
 */

// Patched by aglab2 to remove all useless stuff like comparators etc

#ifndef PAIRINGHEAP_H
#define PAIRINGHEAP_H

#include "graph_node.h"

/*
 * struct PairingHeapHead_allocate
 *
 * Returns a pointer to a newly-allocated heap, with the heap property defined
 * by the given comparator function, which will be invoked with the additional
 * argument specified by 'arg'.
 */
static inline void pairingheap_init(struct PairingHeapHead* heap)
{
    heap->root = NULL;
}

void pairingheap_add(struct PairingHeapHead *heap, struct PairingHeapNode *node);
static inline struct PairingHeapNode* pairingheap_first(struct PairingHeapHead *heap)
{
    return heap->root;
}

struct PairingHeapNode* pairingheap_remove_first(struct PairingHeapHead *heap);

// Custom function that I need for management purposes
void pairingheap_decrease(struct PairingHeapHead *heap, struct PairingHeapNode *node);

/* Is the heap empty? */
#define pairingheap_is_empty(h)			((h)->root == NULL)

/* Is there exactly one node in the heap? */
#define pairingheap_is_singular(h) \
	((h)->ph_root && (h)->root->first_child == NULL)

#endif							/* PAIRINGHEAP_H */
