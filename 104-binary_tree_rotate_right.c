#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 *
 * Rotates the specified binary tree to the right.
 * This operation assumes that the tree is left-heavy,
 * i.e., the left child of the root is present.
 *
 * @tree: A pointer to the root node of the binary tree to be rotated.
 * Return: A pointer to the new root node of the rotated binary tree.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left, *left_right;

	if (!tree || !tree->left)
		return (NULL);

	left = tree->left;
	left_right = left->right;

	tree->left = left_right;
	left->right = tree;

	if (left_right)
		left_right->parent = tree;

	left->right->parent = left;

	if (tree->parent)
		left->parent = tree->parent;

	return (left);
}
