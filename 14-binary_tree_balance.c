#include "binary_trees.h"

/**
 * binary_tree_balance - Calculates the balance factor of a binary tree node.
 * @tree: A pointer to the constant binary tree node for which to calculate
 * the balance factor.
 *
 * Return: The balance factor of the tree node. A positive value indicates
 * the left subtree is taller, a negative value indicates the right
 * subtree is taller, and 0 indicates equal height.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = tree->left ? (int)binary_tree_height(tree->left) : -1;
	right_height = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (left_height - right_height);
}
