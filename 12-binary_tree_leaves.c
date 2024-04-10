#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaf nodes in a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Number of leaf nodes in the binary tree, or 0 if @tree is NULL
 *
 * This function counts the number of leaf nodes in a binary tree,
 * which are nodes that have no children (neither left nor right child).
 * If the tree is empty or the root node is NULL, the number of leaves is
 * considered to be 0. Otherwise, the function recursively counts the number of
 * leaves in the left and right subtrees and sums them up.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
