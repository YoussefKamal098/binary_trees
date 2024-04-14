#include "binary_trees.h"

static int height_and_balance(const binary_tree_t *tree, bool *is_balanced);
static int _binary_tree_is_bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree.
 *
 * Determines whether the binary tree satisfies the properties of an AVL tree,
 * where for each node, the heights of its left and right
 * subtrees do not differ by more than 1, and the tree is
 * a binary search tree (BST).
 *
 * @tree: A pointer to the root node of the binary tree to be checked.
 * Return: 1 if the binary tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	bool is_balanced;

	if (!tree)
		return (0);

	is_balanced = true;
	height_and_balance(tree, &is_balanced);

	return (is_balanced && binary_tree_is_bst(tree));
}

/**
 * height_and_balance - Helper function to calculate the height and
 * balance factor of a binary tree.
 *
 * Recursively calculates the height and balance factor of each node in
 * the binary tree. Updates the boolean variable 'is_balanced'
 * to indicate whether the tree is balanced.
 *
 * @tree: A pointer to the root node of the binary tree.
 * @is_balanced: A pointer to a boolean variable
 * indicating whether the tree is balanced.
 * Return: The height of the binary tree.
 */
static int height_and_balance(const binary_tree_t *tree, bool *is_balanced)
{
	int left_height, right_height;

	if (!tree)
		return (-1);

	left_height = height_and_balance(tree->left, is_balanced);
	right_height = height_and_balance(tree->right, is_balanced);

	if (abs(left_height - right_height) > 1)
		*is_balanced = false;

	return (max(left_height, right_height) + 1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree (BST).
 *
 * Determines whether the binary tree satisfies the properties
 * of a binary search tree,
 * where for each node, all elements in its left subtree are
 * less than the node's value,
 * and all elements in its right subtree are greater than the node's value.
 *
 * @tree: A pointer to the root node of the binary tree to be checked.
 * Return: 1 if the binary tree is a BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	return (_binary_tree_is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * _binary_tree_is_bst -  Helper function to recursively
 * check if a binary tree is a BST.
 *
 * Recursively checks if the binary tree satisfies the BST
 * property within the specified range.
 *
 * @tree: A pointer to the root node of the binary tree to be checked.
 * @min: The minimum value allowed in the subtree.
 * @max: The maximum value allowed in the subtree.
 * Return: 1 if the binary tree is a BST within the
 * specified range, 0 otherwise.
 */
static int _binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (_binary_tree_is_bst(tree->left, min, tree->n - 1) &&
		_binary_tree_is_bst(tree->right, tree->n + 1, max));
}
