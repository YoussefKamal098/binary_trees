#include "binary_trees.h"

bst_t *_bst_insert(bst_t *tree, const bst_t *new_node);
bst_t *_bst_search(bst_t *tree, int value);
avl_t *fix_avl_insert(avl_t *tree, int value);

/**
 * avl_insert - Inserts a value into an AVL tree and maintains AVL properties.
 * @tree: Pointer to the root pointer of the AVL tree.
 * @value: Value to insert into the AVL tree.
 *
 * This function inserts a new node with the specified value into the AVL tree.
 * It also ensures that the AVL properties are maintained by balancing the tree
 * as necessary after the insertion.
 *
 * Return: Pointer to the newly inserted node if insertion is successful,
 *         otherwise NULL.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = bst_insert(tree, value);

	if (!new_node)
		return (NULL);

	*tree = fix_avl_insert(*tree, value);

	return (new_node);
}

/**
 * fix_avl_insert - Fixes AVL tree balance after insertion of a node.
 * @tree: Pointer to the root of the AVL tree.
 * @value: Value of the newly inserted node.
 *
 * This function recursively fixes the balance of the AVL tree
 * after the insertion of a new node with the specified value.
 * It performs rotations as necessary to ensure that the AVL properties
 * are maintained.
 *
 * Return: Pointer to the root of the AVL tree after fixing balance.
 */
avl_t *fix_avl_insert(avl_t *tree, int value)
{
	int balance_factor = 0;

	if (tree->n > value)
	{
		tree->left = fix_avl_insert(tree->left, value);
	}
	else if (tree->n < value)
	{
		tree->right = fix_avl_insert(tree->right, value);
	}

	balance_factor = binary_tree_balance(tree);

	if (balance_factor > 1 && binary_tree_balance(tree->left) > 0)
		return (binary_tree_rotate_right(tree));

	if (balance_factor > 1 && binary_tree_balance(tree->left) < 0)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}

	if (balance_factor < -1 && binary_tree_balance(tree->right) < 0)
		return (binary_tree_rotate_left(tree));

	if (balance_factor < -1 && binary_tree_balance(tree->right) > 0)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}

	return (tree);
}

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
