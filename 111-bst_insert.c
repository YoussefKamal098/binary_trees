#include "binary_trees.h"

bst_t *_bst_insert(bst_t *tree, const bst_t *new_node);
bst_t *_bst_search(bst_t *tree, int value);

/**
 * bst_insert - Inserts a new node with the given value into a binary
 * search tree (BST).
 *
 * Inserts a new node with the specified value into the
 * BST pointed to by 'tree'.
 * If the value already exists in the BST, the insertion
 * fails and NULL is returned.
 *
 * @tree: A pointer to a pointer to the root node of the BST.
 * @value: The value to be inserted into the BST.
 * Return: A pointer to the newly inserted node if successful, NULL otherwise.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = binary_tree_node(NULL, value);

	if (!tree || !new_node)
		return (NULL);

	if (_bst_search(*tree, value))
	{
		free(new_node);
		return (NULL);
	}

	*tree = _bst_insert(*tree, (const bst_t *)new_node);

	return (new_node);
}

/**
 * _bst_insert - Helper function to recursively insert a new node into a BST.
 *
 * Inserts the new node into the specified BST recursively based on its value.
 *
 * @tree: A pointer to the root node of the BST.
 * @new_node: A pointer to the new node to be inserted into the BST.
 * Return: A pointer to the root node of the modified BST.
 */
bst_t *_bst_insert(bst_t *tree, const bst_t *new_node)
{
	if (!tree)
		return ((bst_t *)new_node);

	if (tree->n > new_node->n)
	{
		tree->left = _bst_insert(tree->left, new_node);
		tree->left->parent = tree;
	}

	if (tree->n < new_node->n)
	{
		tree->right = _bst_insert(tree->right, new_node);
		tree->right->parent = tree;
	}

	return (tree);
}

/**
 * _bst_search - Helper function to search for a value in a BST.
 *
 * Searches for the specified value in the BST recursively.
 *
 * @tree: A pointer to the root node of the BST.
 * @value: The value to search for in the BST.
 * Return: A pointer to the node containing the value if found,
 * NULL otherwise.
 */
bst_t *_bst_search(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (tree->n > value)
		return (_bst_search(tree->left, value));
	if (tree->n < value)
		return (_bst_search(tree->right, value));

	return (tree);
}
