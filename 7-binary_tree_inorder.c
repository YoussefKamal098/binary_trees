#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * This function traverses the binary tree in in-order fashion, visiting
 * the left subtree, then the current node, and finally the right subtree.
 * For each visited node, the specified function is called, passing the
 * value of the node as an argument.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	binary_tree_inorder(tree->left, func);
	if (func)
		func(tree->n);
	binary_tree_inorder(tree->right, func);
}
