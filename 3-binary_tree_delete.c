#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * This function deletes an entire binary tree starting from the
 * given root node. It recursively deletes all nodes in the tree
 * and then frees the memory allocated for each node.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;

	free(tree);
}
