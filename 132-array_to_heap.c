#include "binary_trees.h"

/**
 * array_to_heap - Builds a max heap binary tree from an array of integers
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * This function takes an array of integers and builds a max heap binary tree
 * from it. It iterates through the array and inserts each element into the
 * max heap binary tree using the heap_insert function.
 *
 * Return: Pointer to the root node of the max heap binary tree
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
