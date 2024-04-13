#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);

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
	int *array = NULL, i;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);
	array = (int *)malloc(sizeof(int) * (*size));

	if (!array)
		return (NULL);

	while (heap)
	{
		array[i] = heap_extract(&heap);
		i++;
	}

	return (array);
}

/**
 * binary_tree_size - Calculates the size of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Size of the binary tree, or 0 if @tree is NULL
 *
 * This function calculates the size of a binary tree, which is defined as the
 * total number of nodes in the tree. If the tree is empty or
 * the root node is NULL, the size is considered to be 0. Otherwise,
 * the size is calculated recursively by counting the nodes in the left
 * and right subtrees and adding 1 for the current node.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
