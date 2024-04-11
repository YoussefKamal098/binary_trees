#include "binary_trees.h"

queue_t *create_queue();
void enqueue(queue_t *queue, void *data);
void *dequeue(queue_t *queue);
int is_empty(queue_t *queue);

/**
 * binary_tree_levelorder -  Performs level order traversal of a binary tree.
 *
 * Traverses the binary tree in level order and applies the
 * specified function to each node's data.
 *
 * @tree: A pointer to the root node of the binary tree.
 * @func: A pointer to the function to be applied to each node's data.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = create_queue();

	if (!tree)
		return;

	enqueue(queue, (void *)tree);

	while (!is_empty(queue))
	{

		binary_tree_t *front = dequeue(queue);

		func(front->n);

		if (front->left)
			enqueue(queue, (void *)front->left);
		if (front->right)
			enqueue(queue, (void *)front->right);
	}

	queue->head = queue->tail = NULL;
	free(queue);
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
queue_t *create_queue()
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
void enqueue(queue_t *queue, void *data)
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
void *dequeue(queue_t *queue)
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
 * Return: 1 if the queue is empty, 0 otherwise.
 */

int is_empty(queue_t *queue)
{
	return (!queue->head);
}
