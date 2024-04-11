#include "binary_trees.h"

/**
 * bst_search - Helper function to search for a value in a BST.
 *
 * Searches for the specified value in the BST recursively.
 *
 * @tree: A pointer to the root node of the BST.
 * @value: The value to search for in the BST.
 * Return: A pointer to the node containing the value if found,
 * NULL otherwise.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (tree->n > value)
		return (bst_search(tree->left, value));
	if (tree->n < value)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}
