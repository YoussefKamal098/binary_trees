#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the parent node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;

	if (!parent)
		return (NULL);

	left_node = binary_tree_node(parent, value);
	if (!left_node)
		return (NULL);

	left_node->left = parent->left;
	parent->left = left_node;

	if (left_node->left)
		left_node->left->parent = left_node;

	return (left_node);
}
