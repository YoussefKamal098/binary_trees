#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf node
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a leaf, 0 otherwise
 *
 * This function checks if a given node is a leaf node in a binary tree.
 * A leaf node is a node that has no children (neither left nor right child).
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node && !node->left && !node->right);
}
