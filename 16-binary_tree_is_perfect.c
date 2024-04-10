#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if the left and right subtrees of a
 * binary tree node have the same height.
 * @tree: A pointer to the constant binary tree node for which
 * to check subtree height equality.
 *
 * Return: An integer value indicating whether the left and right subtrees
 * have the same height (1) or not (0).
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height, left, right;

	if (!tree)
		return (0);

	left = binary_tree_is_perfect(tree->left);
	right = binary_tree_is_perfect(tree->right);

	left_height = tree->left ? (int)binary_tree_height(tree->left) : -1;
	right_height = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (left && right && left_height == right_height);
}

/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Height of the binary tree, or 0 if @tree
 * is NULL or the tree is empty
 *
 * This function calculates the height of a binary tree,
 * which is defined as the number of edges on the longest path
 * from the root node to a leaf node. If the tree is empty or the
 * root node is NULL, the height is considered to be 0. Otherwise,
 * the height is calculated recursively by finding the maximum height
 * between the left and right subtrees and adding 1 for the current node.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	return (left_h >= right_h ? left_h + 1 : right_h + 1);
}
