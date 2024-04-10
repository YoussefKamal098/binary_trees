#include "binary_trees.h"

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
