#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs a post-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * This function traverses the binary tree in post-order fashion, visiting
 * the left subtree, then the right subtree, and finally the current node.
 * For each visited node, the specified function is called, passing the
 * value of the node as an argument.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);

	if (func)
		func(tree->n);
}
