#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root node
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a root, 0 otherwise
 *
 * This function checks if a given node is a root node in a binary tree.
 * A root node is a node that has no parent.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && !node->parent);
}
