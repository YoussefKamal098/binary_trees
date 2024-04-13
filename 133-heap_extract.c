#include "binary_trees.h"

static heap_t *get_last_level_node(heap_t *root);
static heap_t *maxify(heap_t *tree);
void swap_with_left_child(binary_tree_t *parent);
void swap_with_right_child(binary_tree_t *parent);

/**
 * heap_extract - Extracts the root value of a max heap binary tree
 * @root: Double pointer to the root node of the max heap binary tree
 *
 * This function extracts the root value of a max heap binary tree and
 * maintains the max heap property. It replaces the root with the last
 * node of the last level, updates the pointers accordingly, and then
 * performs the maxify operation to ensure the max heap property is preserved.
 *
 * Return: The value of the root node that was extracted,
 * or 0 if the tree is empty
 */
int heap_extract(heap_t **root)
{
	heap_t *new_root;
	int root_value;

	if (!root || !*root)
		return (0);

	new_root = get_last_level_node(*root);

	if (!new_root->parent)
	{
		root_value = (*root)->n;

		free(*root);
		*root = NULL;

		return (root_value);
	}

	if (new_root->parent->left == new_root)
		new_root->parent->left = NULL;
	else
		new_root->parent->right = NULL;

	new_root->parent = NULL;
	new_root->left = (*root)->left;
	new_root->right = (*root)->right;

	root_value = (*root)->n;
	(*root)->left = (*root)->right = NULL;

	free(*root);
	*root = maxify(new_root);

	return (root_value);
}

/**
 * get_last_level_node - Finds the last node in the last level of
 * a max heap binary tree
 * @root: Pointer to the root node of the max heap binary tree
 *
 * Return: Pointer to the last node in the last level of the
 * max heap binary tree
 */
static heap_t *get_last_level_node(heap_t *root)
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
			tree = tree->right;
			last_level_size /= 2;
		}
		else if (last_level_size > (level_size / 2))
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
 * maxify - Restores the max heap property in a max heap binary tree
 * @tree: Pointer to the root node of the max heap binary tree
 *
 * This function restores the max heap property in a max heap binary tree
 * starting from the given root node. It compares the value of the root node
 * with its left and right children, and swaps the root with the largest child
 * if necessary. It then recursively applies the maxify operation to the
 * subtree rooted at the swapped node until the max heap property is restored.
 *
 * Return: Pointer to the node with the largest value in the subtree
 */
static heap_t *maxify(heap_t *tree)
{
	heap_t *largest;

	if (!tree)
		return (NULL);

	largest = tree;

	if (tree->left && tree->left->n >= largest->n)
		largest = tree->left;
	if (tree->right && tree->right->n >= largest->n)
		largest = tree->right;

	if (largest == tree)
		return (tree);

	if (largest == tree->left)
		swap_with_left_child(tree);
	else
		swap_with_right_child(tree);

	maxify(tree);
	return (largest);
}

/**
 * swap_with_left_child - Swaps a node with its left child in the heap
 * @parent: Pointer to the parent node
 *
 * This function swaps the given parent node with its left child in the heap.
 * It updates the parent-child relationships accordingly and maintains
 * the heap structure after the swap.
 */
void swap_with_left_child(binary_tree_t *parent)
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
void swap_with_right_child(binary_tree_t *parent)
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
