#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 *
 * Rotates the specified binary tree to the left.
 * This operation assumes that the tree is right-heavy,
 * i.e., the right child of the root is present.
 *
 * @tree: A pointer to the root node of the binary tree to be rotated.
 * Return: A pointer to the new root node of the rotated binary tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right, *right_left;

	if (!tree || !tree->right)
		return (NULL);

	right = tree->right;
	right_left = right->left;

	tree->right = right_left;
	right->left = tree;

	if (right_left)
		right_left->parent = tree;

	right->parent = tree->parent;
	right->left->parent = right;

	return (right);
}
