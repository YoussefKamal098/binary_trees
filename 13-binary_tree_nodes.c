#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of non-leaf nodes in a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Number of non-leaf nodes in the binary tree, or 0 if @tree is NULL
 *
 * This function counts the number of non-leaf nodes in a binary tree,
 * which are nodes that have at least one child (either left or right child).
 * If the tree is empty or the root node is NULL, the number of non-leaf
 * nodes is considered to be 0. Otherwise, the function recursively counts
 * the number of non-leaf nodes in the left and right subtrees and sums them
 * up, adding 1 for the current node if it is not a leaf node.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
