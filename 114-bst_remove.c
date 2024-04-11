#include "binary_trees.h"

bst_t *bst_min(bst_t *root);

/**
 * bst_remove - Removes a node with the specified value from a
 * binary search tree (BST).
 *
 * Removes the node with the given value from the BST rooted at 'root'.
 * If the value does not exist in the BST, no changes are made.
 *
 * @root: A pointer to the root node of the BST.
 * @value: The value to be removed from the BST.
 * Return: A pointer to the root node of the modified BST.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (!root)
		return (NULL);
	if (root->n > value)
	{
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (root->n < value)
	{
		root->right = bst_remove(root->right, value);
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
		root->right = bst_remove(root->right, tmp->n);
		if (root->right)
			root->right->parent = root;
	}
	return (root);
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
bst_t *bst_min(bst_t *root)
{
	if (!root->left)
		return (root);

	return (bst_min(root->left));
}
