#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first binary tree node
 * @second: pointer to the second binary tree node
 *
 * This function finds the lowest common ancestor of two nodes in a
 * binary tree. It traverses the tree upward from both nodes until it
 * reaches a common ancestor.
 *
 * Return: pointer to the lowest common ancestor node,
 * or NULL if no common ancestor found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (!first || !second)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	while (first_depth < second_depth)
	{
		second = second->parent;
		second_depth--;
	}

	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		second = second->parent;
		first = first->parent;
	}

	return (NULL);
}

/**
 * binary_tree_depth - Calculates the depth of a node in a binary tree
 * @tree: Pointer to the node for which depth is to be calculated
 *
 * Return: Depth of the node, or 0 if @tree is NULL
 *
 * This function calculates the depth of a node in a binary tree.
 * The depth of a node is defined as the number of edges from the node
 * to the root of the tree. If the input node is NULL, the function
 * returns 0. Otherwise, it traverses the parent pointers from the
 * input node to the root node, counting the number of edges along the way.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}
