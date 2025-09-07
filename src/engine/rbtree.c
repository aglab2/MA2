#include "rbtree.h"

/*
 * all leafs are sentinels, use customized NIL name to prevent
 * collision with system-wide constant NIL which is actually NULL
 */
#define RBTNIL (&sentinel)

#define RBTBLACK	(0)
#define RBTRED		(1)

RBTNode sentinel =
{
	.color = RBTBLACK,.left = RBTNIL,.right = RBTNIL,.parent = NULL
};

/**********************************************************************
 *							  Insertion								  *
 **********************************************************************/

/*
 * Rotate node x to left.
 *
 * x's right child takes its place in the tree, and x becomes the left
 * child of that node.
 */
static void
rbt_rotate_left(RBTree *rbt, RBTNode *x)
{
	RBTNode    *y = x->right;

	/* establish x->right link */
	x->right = y->left;
	if (y->left != RBTNIL)
		y->left->parent = x;

	/* establish y->parent link */
	if (y != RBTNIL)
		y->parent = x->parent;
	if (x->parent)
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else
	{
		rbt->root = y;
	}

	/* link x and y */
	y->left = x;
	if (x != RBTNIL)
		x->parent = y;
}

/*
 * Rotate node x to right.
 *
 * x's left right child takes its place in the tree, and x becomes the right
 * child of that node.
 */
static void
rbt_rotate_right(RBTree *rbt, RBTNode *x)
{
	RBTNode    *y = x->left;

	/* establish x->left link */
	x->left = y->right;
	if (y->right != RBTNIL)
		y->right->parent = x;

	/* establish y->parent link */
	if (y != RBTNIL)
		y->parent = x->parent;
	if (x->parent)
	{
		if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
	}
	else
	{
		rbt->root = y;
	}

	/* link x and y */
	y->right = x;
	if (x != RBTNIL)
		x->parent = y;
}

static void rbt_insert_fixup(RBTree *rbt, RBTNode *x)
{
	/*
	 * x is always a red node.  Initially, it is the newly inserted node. Each
	 * iteration of this loop moves it higher up in the tree.
	 */
	while (x != rbt->root && x->parent->color == RBTRED)
	{
		/*
		 * x and x->parent are both red.  Fix depends on whether x->parent is
		 * a left or right child.  In either case, we define y to be the
		 * "uncle" of x, that is, the other child of x's grandparent.
		 *
		 * If the uncle is red, we flip the grandparent to red and its two
		 * children to black.  Then we loop around again to check whether the
		 * grandparent still has a problem.
		 *
		 * If the uncle is black, we will perform one or two "rotations" to
		 * balance the tree.  Either x or x->parent will take the
		 * grandparent's position in the tree and recolored black, and the
		 * original grandparent will be recolored red and become a child of
		 * that node. This always leaves us with a valid red-black tree, so
		 * the loop will terminate.
		 */
		if (x->parent == x->parent->parent->left)
		{
			RBTNode    *y = x->parent->parent->right;

			if (y->color == RBTRED)
			{
				/* uncle is RBTRED */
				x->parent->color = RBTBLACK;
				y->color = RBTBLACK;
				x->parent->parent->color = RBTRED;

				x = x->parent->parent;
			}
			else
			{
				/* uncle is RBTBLACK */
				if (x == x->parent->right)
				{
					/* make x a left child */
					x = x->parent;
					rbt_rotate_left(rbt, x);
				}

				/* recolor and rotate */
				x->parent->color = RBTBLACK;
				x->parent->parent->color = RBTRED;

				rbt_rotate_right(rbt, x->parent->parent);
			}
		}
		else
		{
			/* mirror image of above code */
			RBTNode    *y = x->parent->parent->left;

			if (y->color == RBTRED)
			{
				/* uncle is RBTRED */
				x->parent->color = RBTBLACK;
				y->color = RBTBLACK;
				x->parent->parent->color = RBTRED;

				x = x->parent->parent;
			}
			else
			{
				/* uncle is RBTBLACK */
				if (x == x->parent->left)
				{
					x = x->parent;
					rbt_rotate_right(rbt, x);
				}
				x->parent->color = RBTBLACK;
				x->parent->parent->color = RBTRED;

				rbt_rotate_left(rbt, x->parent->parent);
			}
		}
	}

	/*
	 * The root may already have been black; if not, the black-height of every
	 * node in the tree increases by one.
	 */
	rbt->root->color = RBTBLACK;
}

void rbt_insert(RBTree *rbt, RBTNode *node)
{
	RBTNode    *current,
			   *parent,
			   *x;
    int cmp = 0;

	/* find where node belongs */
	current = rbt->root ?: RBTNIL;
	parent = NULL;

	while (current != RBTNIL)
	{
        cmp = node->weight < current->weight;
		parent = current;
		current = cmp ? current->left : current->right;
	}

	x = node;
	x->color = RBTRED;

	x->left = RBTNIL;
	x->right = RBTNIL;
	x->parent = parent;

	/* insert node in tree */
	if (parent)
	{
		if (cmp)
			parent->left = x;
		else
			parent->right = x;
	}
	else
	{
		rbt->root = x;
	}

	return (void) rbt_insert_fixup(rbt, x);
}

RBTNode* rbt_left_right_iterator_init(RBTree *rbt)
{
	RBTNode *last_visited;
	if (rbt->root == NULL) {
		return NULL;
	}

	last_visited = rbt->root;
	while (last_visited->left != RBTNIL)
		last_visited = last_visited->left;

	return last_visited;
}

RBTNode* rbt_left_right_iterator_next(RBTNode *last_visited)
{
	if (last_visited->right != RBTNIL)
	{
		last_visited = last_visited->right;
		while (last_visited->left != RBTNIL)
			last_visited = last_visited->left;

		return last_visited;
	}

	for (;;)
	{
		RBTNode    *came_from = last_visited;

		last_visited = last_visited->parent;
		if (last_visited == NULL)
		{
			break;
		}

		if (last_visited->left == came_from)
			break;				/* came from left sub-tree, return current
								 * node */

		/* else - came from right sub-tree, continue to move up */
	}

	return last_visited;
}
