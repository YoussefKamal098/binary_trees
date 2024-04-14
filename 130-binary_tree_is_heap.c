#include "binary_trees.h"

static bool binary_tree_is_max_heap(const binary_tree_t *tree);
static void enqueue(queue_t *queue, void *data);
static void *dequeue(queue_t *queue);

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap
 * @tree: Pointer to the root node of the binary tree
 *
 * This function checks if the given binary tree is a max heap,
 * i.e., it is both a complete binary tree and satisfies the max heap
 * property. A binary tree is a max heap if, for every node in the tree,
 * its value is greater than or equal to the values of its children,
 * and it is a complete binary tree.
 *
 * Return: 1 if the binary tree is a max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (false);

	return (binary_tree_is_complete(tree) && binary_tree_is_max_heap(tree));
}

/**
 * binary_tree_is_max_heap - Checks if a binary tree
 * satisfies the max heap property
 * @tree: Pointer to the root node of the binary tree
 *
 * This function checks if the given binary tree satisfies
 * the max heap property. It recursively checks if each node in the
 * tree has a value greater than or equal
 * to the values of its children.
 *
 * Return: true if the binary tree satisfies the max heap property,
 * false otherwise
 */
static bool binary_tree_is_max_heap(const binary_tree_t *tree)
{
	int left = true, right = true;

	if (!tree)
		return (false);

	if (tree->left)
		left = binary_tree_is_heap(tree->left);

	if (tree->right)
		right = binary_tree_is_heap(tree->right);

	if (tree->left && tree->n < tree->left->n)
		return (false);

	if (tree->right && tree->n < tree->right->n)
		return (false);

	return (left && right);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * Determines whether the binary tree is complete,
 * meaning that all levels except possibly
 * the last are completely filled, and all nodes are as far left as possible.
 *
 * @tree: A pointer to the root node of the binary tree to be checked.
 * Return: 1 if the binary tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue;
	bool is_end = false, is_complete = true;

	if (!tree)
		return (false);

	queue = (queue_t *)malloc(sizeof(queue_t));
	if (queue == NULL)
	{
		fprintf(stderr, "Memory allocation failed. Unable to create queue.\n");
		return (false);
	}

	queue->head = queue->tail = NULL;

	enqueue(queue, (void *)tree);

	while (queue->head)
	{
		binary_tree_t *front = dequeue(queue);

		if (is_end && (front->left || front->right))
			is_complete = false;

		if (front->left && !is_end)
			enqueue(queue, (void *)front->left);
		if (front->right && !is_end)
			enqueue(queue, (void *)front->right);

		if (!front->left && front->right)
			is_complete = false;
		if (!front->left || !front->right)
			is_end = true;
	}

	queue->head = queue->tail = NULL;
	free(queue);

	return (is_complete);
}

/**
 * enqueue - Adds an element to the rear of the queue.
 *
 * Allocates memory for a new node, stores the provided data in it,
 * and adds it to the rear of the queue.
 *
 * @queue: A pointer to the queue to which the element will be added.
 * @data: A pointer to the data to be stored in the new node.
 */
static void enqueue(queue_t *queue, void *data)
{
	linked_list_node_t *newNode;

	newNode = (linked_list_node_t *)malloc(sizeof(linked_list_node_t));
	if (!newNode)
	{
		fprintf(stderr, "Memory allocation failed. Unable to enqueue!\n");
		return;
	}

	newNode->data = data;
	newNode->next = NULL;

	if (!queue->tail)
	{
		queue->head = newNode;
		queue->tail = newNode;
	}
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}
}

/**
 * dequeue -  Removes and returns the element at the front of the queue.
 *
 * Removes the element at the front of the queue,
 * frees the memory allocated for its node, and returns the data
 * stored in the removed node.
 *
 * @queue: A pointer to the queue from which the element will be removed.
 * Return: A pointer to the data of the removed element,
 * or NULL if the queue is empty.
 */
static void *dequeue(queue_t *queue)
{
	linked_list_node_t *temp;
	void *data;

	if (!queue->head)
	{
		printf("Queue is empty. Cannot dequeue!\n");
		return (NULL);
	}

	temp = queue->head;
	data = temp->data;
	queue->head = queue->head->next;

	if (!queue->head)
		queue->tail = NULL;

	free(temp);

	return (data);
}
