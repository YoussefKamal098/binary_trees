#include "binary_trees.h"

pair_t binary_tree_height_and_is_balance(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
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
	pair_t height_and_balance_pair;
	bool is_balanced;

	if (!tree)
		return (0);

	height_and_balance_pair = binary_tree_height_and_is_balance(tree);

	is_balanced = *(bool *)height_and_balance_pair.second;

	free(height_and_balance_pair.first);
	free(height_and_balance_pair.second);

	return (is_balanced && binary_tree_is_bst(tree));
}

/**
 * binary_tree_height_and_is_balance - Calculates the height and balance
 * factor of a binary tree recursively.
 *
 * This function calculates the height and balance factor of
 * each node in the binary tree recursively. It returns a pair containing
 * the height of the tree and a boolean indicating
 * whether the tree is balanced according to AVL tree properties.
 *
 * @tree: A pointer to the root node of the binary tree.
 * Return: A pair containing the height of the tree and
 * a boolean indicating its balance.
 */
pair_t binary_tree_height_and_is_balance(const binary_tree_t *tree)
{
	pair_t left, right;
	int *height = (int *)malloc(sizeof(int)), balance_factor;
	bool *is_balanced = (bool *)malloc(sizeof(bool));

	*height = 0;
	*is_balanced = true;

	if (!tree)
		return ((pair_t){height, is_balanced});

	left = binary_tree_height_and_is_balance(tree->left);
	right = binary_tree_height_and_is_balance(tree->right);

	balance_factor = *(int *)left.first - *(int *)right.first;
	*height = max(*(int *)left.first, *(int *)right.first) + 1;

	*is_balanced = abs(balance_factor) <= 1 &&
		       *(bool *)left.second && *(bool *)right.second;

	free(left.first);
	free(left.second);
	free(right.first);
	free(right.second);

	return ((pair_t){height, is_balanced});
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
