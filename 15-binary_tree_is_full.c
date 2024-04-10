#include "binary_trees.h"

/**
 *  binary_tree_is_full - Checks if a binary tree is a full binary tree.
 * @tree: A pointer to the constant binary tree node for which to
 * check fullness.
 *
 * Return: An integer value indicating whether the tree is full (1) or not (0).
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
