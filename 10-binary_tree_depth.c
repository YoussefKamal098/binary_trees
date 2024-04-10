#include "binary_trees.h"

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
