#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the parent node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node;

	if (!parent)
		return (NULL);

	right_node = binary_tree_node(parent, value);
	if (!right_node)
		return (NULL);

	right_node->right = parent->right;
	parent->right = right_node;

	if (right_node->right)
		right_node->right->parent = right_node;

	return (right_node);
}
