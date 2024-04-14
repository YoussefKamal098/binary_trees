#include "binary_trees.h"

static heap_t *get_heap_empty_slot(heap_t *root);
static heap_t *maxify_up(heap_t *tree);
static void swap_with_right_child(binary_tree_t *parent);
static void swap_with_left_child(binary_tree_t *parent);

/**
 * heap_insert - Inserts a value into a binary max heap
 * @root: Pointer to the root of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the newly inserted node
 *
 * This function inserts a new node with the given value into
 * a binary max heap. It first creates a new node and assigns
 * it the given value. If the heap is empty, the new node becomes
 * the root of the heap. Otherwise, it finds the empty slot in the
 * heap using the get_heap_empty_slot function and inserts the new
 * node at that position. After insertion, it restores the max heap
 * property by calling the maxify_up function on the newly inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *new_node_parent;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);

	if (!*root)
		return (*root = new_node);

	if (!new_node)
		return (NULL);

	new_node_parent = get_heap_empty_slot(*root);

	if (!new_node_parent->left)
		new_node_parent->left = new_node;
	else
		new_node_parent->right = new_node;

	new_node->parent = new_node_parent;

	*root = maxify_up(new_node);

	return (new_node);
}

/**
 * get_heap_empty_slot - Finds an empty slot in the heap for insertion
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the empty slot in the heap
 *
 * This function traverses the binary heap to find the insertion point
 * for a new node. It starts from the root of the heap and iterates
 * down to the last level to find the appropriate empty slot. The last
 * level of the heap is filled from left to right, so the function
 * searches for the first available empty slot from left to right.
 */
static heap_t *get_heap_empty_slot(heap_t *root)
{
	heap_t *tree;
	int i, tree_size, last_level_size, level_size, tree_height;

	if (!root)
		return (NULL);

	tree = root;
	tree_size = binary_tree_size(tree);

	/* Calculate the height of the tree and last level size */
	tree_height = 0, level_size = 1;
	for (; tree_size > level_size; level_size *= 2, tree_height++)
		tree_size -= level_size;

	last_level_size = tree_size;

	/* Traverse the tree to find the insertion point */
	for (i = 0; i < tree_height; i++)
	{
		if (level_size == last_level_size)
		{
			tree = tree->left;
			last_level_size /= 2;
		}
		else if (last_level_size >= (level_size / 2))
		{
			if (!tree->right)
				break;
			tree = tree->right;
			last_level_size -= (level_size / 2);
		}
		else
		{
			if (!tree->left)
				break;
			tree = tree->left;
		}
		level_size /= 2;
	}
	return (tree);
}

/**
 * binary_tree_size - Calculates the size of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Size of the binary tree, or 0 if @tree is NULL
 *
 * This function calculates the size of a binary tree, which is defined as the
 * total number of nodes in the tree. If the tree is empty or
 * the root node is NULL, the size is considered to be 0. Otherwise,
 * the size is calculated recursively by counting the nodes in the left
 * and right subtrees and adding 1 for the current node.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * maxify_up - Ensures that the max heap property is maintained after
 * inserting a node
 * @tree: Pointer to the node to maxify_up
 *
 * This function ensures that the max heap property is maintained
 * after inserting a node into a max heap binary tree. It recursively
 * swaps the given node with its parent if the parent's value is
 * less than the node's value, until the max heap property is satisfied.
 *
 * Return: Pointer to the root of the updated max heap binary tree
 */
static heap_t *maxify_up(heap_t *tree)
{
	if (!tree)
		return (NULL);

	if (!tree->parent)
		return (tree);

	if (tree->parent->n < tree->n)
	{
		if (tree->parent->left == tree)
			swap_with_left_child(tree->parent);
		else
			swap_with_right_child(tree->parent);

		return (maxify_up(tree));
	}

	return (maxify_up(tree->parent));
}

/**
 * swap_with_left_child - Swaps a node with its left child in the heap
 * @parent: Pointer to the parent node
 *
 * This function swaps the given parent node with its left child in the heap.
 * It updates the parent-child relationships accordingly and maintains
 * the heap structure after the swap.
 */
static void swap_with_left_child(binary_tree_t *parent)
{
	binary_tree_t *left_right_child, *left_child;

	if (!parent || !parent->left)
		return;

	left_child = parent->left;

	left_right_child = left_child->right;
	left_child->right = parent->right;

	if (left_child->right)
		left_child->right->parent = left_child;

	parent->right = left_right_child;

	if (parent->right)
		parent->right->parent = parent;

	parent->left = left_child->left;

	if (parent->left)
		parent->left->parent = parent;

	left_child->left = parent;

	left_child->parent = parent->parent;
	parent->parent = left_child;

	if (!left_child->parent)
		return;

	if (left_child->parent->left == parent)
		left_child->parent->left = left_child;
	else
		left_child->parent->right = left_child;
}

/**
 * swap_with_right_child - Swaps a node with its right child in the heap
 * @parent: Pointer to the parent node
 *
 * This function swaps the given parent node with its right child in the heap.
 * It updates the parent-child relationships accordingly and maintains
 * the heap structure after the swap.
 */
static void swap_with_right_child(binary_tree_t *parent)
{
	binary_tree_t *right_child, *right_left_child;

	if (!parent || !parent->right)
		return;

	right_child = parent->right;

	right_left_child = right_child->left;
	right_child->left = parent->left;

	if (right_child->left)
		right_child->left->parent = right_child;

	parent->left = right_left_child;

	if (parent->left)
		parent->left->parent = parent;

	parent->right = right_child->right;

	if (parent->right)
		parent->right->parent = parent;

	right_child->right = parent;

	right_child->parent = parent->parent;
	parent->parent = right_child;

	if (!right_child->parent)
		return;

	if (right_child->parent->left == parent)
		right_child->parent->left = right_child;
	else
		right_child->parent->right = right_child;
}
