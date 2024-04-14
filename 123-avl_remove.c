#include "binary_trees.h"

static avl_t *apply_rotation(avl_t *tree);
static bst_t *bst_min(bst_t *root);

/**
 * avl_remove - Removes a node with a specific value from an AVL tree.
 * @root: Pointer to the root of the AVL tree.
 * @value: Value of the node to be removed.
 *
 * This function removes the node with the specified value from the AVL tree.
 * It then rebalances the tree if necessary to maintain AVL properties.
 *
 * Return: Pointer to the root of the AVL tree after removal and rebalancing.
 */
bst_t *avl_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (!root)
		return (NULL);
	if (root->n > value)
	{
		root->left = avl_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (root->n < value)
	{
		root->right = avl_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			root->left = NULL;
			root->right = NULL;
			root->parent = NULL;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			root->left = NULL;
			root->right = NULL;
			root->parent = NULL;
			free(root);
			return (tmp);
		}

		tmp = bst_min(root->right);
		root->n = tmp->n;
		root->right = avl_remove(root->right, tmp->n);
		if (root->right)
			root->right->parent = root;
	}

	return (apply_rotation(root));
}

/**
 * apply_rotation - Applies rotations to maintain AVL properties after removal.
 * @tree: Pointer to the root of the AVL tree.
 *
 * This function checks the balance factor of the AVL tree and
 * applies rotations
 * if necessary to maintain AVL properties after a node removal operation.
 *
 * Return: Pointer to the root of the AVL tree after applying rotations.
 */
static avl_t *apply_rotation(avl_t *tree)
{
	int balance_factor = binary_tree_balance(tree);

	if (balance_factor > 1 && binary_tree_balance(tree->left) >= 0)
		return (binary_tree_rotate_right(tree));

	if (balance_factor > 1 && binary_tree_balance(tree->left) < 0)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}

	if (balance_factor < -1 && binary_tree_balance(tree->right) <= 0)
		return (binary_tree_rotate_left(tree));

	if (balance_factor < -1 && binary_tree_balance(tree->right) > 0)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}

	return (tree);
}

/**
 * bst_min - Finds the node with the minimum value
 * in a binary search tree (BST).
 *
 * Finds and returns a pointer to the node with the minimum
 * value in the BST rooted at 'root'.
 *
 * @root: A pointer to the root node of the BST.
 * Return: A pointer to the node with the minimum value in the BST.
 */
static bst_t *bst_min(bst_t *root)
{
	if (!root->left)
		return (root);

	return (bst_min(root->left));
}
