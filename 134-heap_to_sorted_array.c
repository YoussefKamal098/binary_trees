#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a max heap binary tree into a sorted array
 * @heap: Pointer to the root node of the max heap binary tree
 * @size: Pointer to a variable to store the size of the resulting array
 *
 * This function converts a max heap binary tree into a sorted array by
 * extracting the root value of the heap iteratively until the heap is empty.
 * It allocates memory for the resulting array, fills it with the extracted
 * values,and updates the size variable with the size of the array.
 *
 * Return: Pointer to the sorted array, or NULL if @heap
 * is NULL or @size is NULL,
 * or if memory allocation fails
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *array = NULL;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);

	array = malloc(sizeof(int) * (*size));
	if (!array)
		return (NULL);

	for (i = 0; heap; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
