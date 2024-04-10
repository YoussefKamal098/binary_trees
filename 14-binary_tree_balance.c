#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

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
