#include "binary_trees.h"

static int _binary_tree_is_bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree (BST).
 *
 * Determines whether the binary tree satisfies the properties
 * of a binary search tree,
 * where for each node, all elements in its left subtree are
 * less than the node's value,
 * and all elements in its right subtree are greater than the node's value.
 *
 * @tree: A pointer to the root node of the binary tree to be checked.
 * Return: 1 if the binary tree is a BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	return (_binary_tree_is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * _binary_tree_is_bst -  Helper function to recursively
 * check if a binary tree is a BST.
 *
 * Recursively checks if the binary tree satisfies the BST
 * property within the specified range.
 *
 * @tree: A pointer to the root node of the binary tree to be checked.
 * @min: The minimum value allowed in the subtree.
 * @max: The maximum value allowed in the subtree.
 * Return: 1 if the binary tree is a BST within the
 * specified range, 0 otherwise.
 */
static int _binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (_binary_tree_is_bst(tree->left, min, tree->n - 1) &&
		_binary_tree_is_bst(tree->right, tree->n + 1, max));
}
