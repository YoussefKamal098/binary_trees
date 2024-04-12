#include "binary_trees.h"

/**
 * array_to_avl - Creates an AVL tree from an array of integers.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 * This function takes an array of integers and constructs an AVL tree by
 * inserting each element from the array into the AVL tree using the avl_insert
 * function.
 *
 * Return: Pointer to the root of the constructed AVL tree.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
