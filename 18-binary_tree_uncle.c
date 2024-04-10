#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: A pointer to the node for which to find the uncle.
 *
 * Return: A pointer to the uncle node of the provided node,
 * or NULL if the node is the root, has no parent,
 * or the parent has no sibling.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: A pointer to the node for which to find the sibling.
 *
 * Return: A pointer to the sibling node of the provided node, or NULL if
 * the node is the root or has no parent.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
