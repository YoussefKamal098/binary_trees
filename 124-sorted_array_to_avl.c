#include "binary_trees.h"

static avl_t *helper(int *array, size_t left, size_t right);

/**
 * sorted_array_to_avl - Constructs an AVL tree from a
 * sorted array of integers.
 * @array: Pointer to the sorted array of integers.
 * @size: Size of the array.
 *
 * This function takes a sorted array of integers and constructs an AVL tree
 * from it. It divides the array into halves and recursively constructs the
 * tree by creating nodes from the middle elements of each half.
 *
 * Return: Pointer to the root of the constructed AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (helper(array, 0, size - 1));
}

/**
 * helper - Helper function to recursively build AVL tree from a sorted array.
 * @array: Pointer to the sorted array of integers.
 * @left: Index of the left boundary of the current subarray.
 * @right: Index of the right boundary of the current subarray.
 *
 * This function recursively constructs the AVL tree from a sorted array of
 * integers. It divides the array into halves and creates nodes from the middle
 * elements of each half, ensuring that the tree remains balanced.
 *
 * Return: Pointer to the root of the AVL tree constructed
 * from the current subarray.
 */
static avl_t *helper(int *array, size_t left, size_t right)
{
	size_t mid;
	avl_t *tree;

	if ((int)left > (int)right)
		return (NULL);

	if (left == right)
		return (binary_tree_node(NULL, array[left]));

	mid = (right - left) / 2 + left;

	tree = binary_tree_node(NULL, array[mid]);
	tree->left = helper(array, left, mid - 1);
	tree->right = helper(array, mid + 1, right);

	if (tree->left)
		tree->left->parent = tree;
	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}
