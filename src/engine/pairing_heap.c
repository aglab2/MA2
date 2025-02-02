/*-------------------------------------------------------------------------
 *
 * struct PairingHeapHead.c
 *	  A Pairing Heap implementation
 *
 * A pairing heap is a data structure that's useful for implementing
 * priority queues. It is simple to implement, and provides amortized O(1)
 * insert and find-min operations, and amortized O(log n) delete-min.
 *
 * The pairing heap was first described in this paper:
 *
 *	Michael L. Fredman, Robert Sedgewick, Daniel D. Sleator, and Robert E.
 *	 Tarjan. 1986.
 *	The pairing heap: a new form of self-adjusting heap.
 *	Algorithmica 1, 1 (January 1986), pages 111-129. DOI: 10.1007/BF01840439
 *
 * Portions Copyright (c) 2012-2025, PostgreSQL Global Development Group
 *
 * IDENTIFICATION
 *	  src/backend/lib/struct PairingHeapHead.c
 *
 *-------------------------------------------------------------------------
 */

#include "pairing_heap.h"

static struct PairingHeapNode *merge(struct PairingHeapHead *heap, struct PairingHeapNode *a, struct PairingHeapNode *b);
static struct PairingHeapNode *merge_children(struct PairingHeapHead *heap, struct PairingHeapNode *children);

/*
 * A helper function to merge two subheaps into one.
 *
 * The subheap with smaller value is put as a child of the other one (assuming
 * a max-heap).
 *
 * The next_sibling and prev_or_parent pointers of the input nodes are
 * ignored. On return, the returned node's next_sibling and prev_or_parent
 * pointers are garbage.
 */

static int compare(struct PairingHeapNode *a, struct PairingHeapNode *b)
{
    return a->priority > b->priority;
}

static struct PairingHeapNode* merge(struct PairingHeapHead *heap, struct PairingHeapNode *a, struct PairingHeapNode *b)
{
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;

	/* swap 'a' and 'b' so that 'a' is the one with larger value */
	if (0 == compare(a, b))
	{
		struct PairingHeapNode *tmp;

		tmp = a;
		a = b;
		b = tmp;
	}

	/* and put 'b' as a child of 'a' */
	if (a->first_child)
		a->first_child->prev_or_parent = b;
	b->prev_or_parent = a;
	b->next_sibling = a->first_child;
	a->first_child = b;

	return a;
}

/*
 * struct PairingHeapHead_add
 *
 * Adds the given node to the heap in O(1) time.
 */
void pairingheap_add(struct PairingHeapHead *heap, struct PairingHeapNode *node)
{
	node->first_child = NULL;

	/* Link the new node as a new tree */
	heap->root = merge(heap, heap->root, node);
	heap->root->prev_or_parent = NULL;
	heap->root->next_sibling = NULL;
}

/*
 * struct PairingHeapHead_remove_first
 *
 * Removes the first (root, topmost) node in the heap and returns a pointer to
 * it after rebalancing the heap. The caller must ensure that this routine is
 * not used on an empty heap. O(log n) amortized.
 */
struct PairingHeapNode* pairingheap_remove_first(struct PairingHeapHead *heap)
{
	struct PairingHeapNode *result;
	struct PairingHeapNode *children;

	/* Remove the root, and form a new heap of its children. */
	result = heap->root;
	children = result->first_child;

	heap->root = merge_children(heap, children);
	if (heap->root)
	{
		heap->root->prev_or_parent = NULL;
		heap->root->next_sibling = NULL;
	}

	return result;
}

/*
 * Merge a list of subheaps into a single heap.
 *
 * This implements the basic two-pass merging strategy, first forming pairs
 * from left to right, and then merging the pairs.
 */
static struct PairingHeapNode *
merge_children(struct PairingHeapHead *heap, struct PairingHeapNode *children)
{
	struct PairingHeapNode *curr,
			   *next;
	struct PairingHeapNode *pairs;
	struct PairingHeapNode *newroot;

	if (children == NULL || children->next_sibling == NULL)
		return children;

	/* Walk the subheaps from left to right, merging in pairs */
	next = children;
	pairs = NULL;
	for (;;)
	{
		curr = next;

		if (curr == NULL)
			break;

		if (curr->next_sibling == NULL)
		{
			/* last odd node at the end of list */
			curr->next_sibling = pairs;
			pairs = curr;
			break;
		}

		next = curr->next_sibling->next_sibling;

		/* merge this and the next subheap, and add to 'pairs' list. */

		curr = merge(heap, curr, curr->next_sibling);
		curr->next_sibling = pairs;
		pairs = curr;
	}

	/*
	 * Merge all the pairs together to form a single heap.
	 */
	newroot = pairs;
	next = pairs->next_sibling;
	while (next)
	{
		curr = next;
		next = curr->next_sibling;

		newroot = merge(heap, newroot, curr);
	}

	return newroot;
}

void pairingheap_decrease(struct PairingHeapHead *heap, struct PairingHeapNode *node)
{
    struct PairingHeapNode *parent = node->prev_or_parent;
    if (parent)
    {
        if (parent->first_child == node)
        {
            parent->first_child = node->next_sibling;
        }
        else
        {
            parent->next_sibling = node->next_sibling;
        }

        if (node->next_sibling)
        {
            node->next_sibling->prev_or_parent = parent;
        }

        node->next_sibling = NULL;
        node->prev_or_parent = NULL;
        heap->root = merge(heap, heap->root, node);
    }
}
