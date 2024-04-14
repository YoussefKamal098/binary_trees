#include "binary_trees.h"

static queue_t *create_queue();
static void enqueue(queue_t *queue, void *data);
static void *dequeue(queue_t *queue);
static bool is_empty(queue_t *queue);

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

	queue = create_queue();
	enqueue(queue, (void *)tree);

	while (!is_empty(queue))
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
 * create_queue - Creates a new queue.
 *
 * Allocates memory for a new queue structure and initializes
 * it with empty values.
 *
 * Return: A pointer to the newly created queue,
 * or NULL if memory allocation fails.
 */
static queue_t *create_queue()
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

	if (queue == NULL)
	{
		fprintf(stderr, "Memory allocation failed. Unable to create queue.\n");
		return (NULL);
	}

	queue->head = NULL;
	queue->tail = NULL;

	return (queue);
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

/**
 * is_empty -  Checks if the queue is empty.
 *
 * Checks if the queue is empty by verifying if the head pointer is NULL.
 *
 * @queue: A pointer to the queue to be checked.
 * Return: true if the queue is empty, false otherwise.
 */

static bool is_empty(queue_t *queue)
{
	return (!queue->head);
}
