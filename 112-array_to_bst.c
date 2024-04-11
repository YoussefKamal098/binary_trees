#include "binary_trees.h"

/**
 * array_to_bst - Converts an array of integers into a
 * binary search tree (BST).
 *
 * Creates a BST from the given array of integers. Each element in the array
 * is inserted into the BST using the bst_insert function.
 *
 * @array: A pointer to the array of integers.
 * @size: The number of elements in the array.
 * Return: A pointer to the root node of the resulting BST.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
