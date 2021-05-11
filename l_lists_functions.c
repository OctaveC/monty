#include "monty.h"

/**
 * add_node_LIFO - adds node last in first out
 * @stack: the stack we're adding to
 * @new: the new node we're adding to the stack
 *
 * Return: Nothing
 */
void add_node_LIFO(stack_t **stack, stack_t *new)
{
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * add_node_FIFO - adds node first in first out
 * @stack: the stack we're adding to
 * @new: the new node we're adding to the stack
 *
 * Return: Nothing
 */
void add_node_FIFO(stack_t **stack, stack_t *new)
{
	stack_t *head = *stack;

	new->next = NULL;
	new->prev = NULL;

	if (head == NULL)
		*stack = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
		new->prev = head;
	}
}

/**
 * dlistint_len - Returns the number of elements in a doubly linked list
 * @stack: The list we're going to print
 *
 * Return: The number of nodes
 */
size_t dlistint_len(stack_t *stack)
{
	int count = 0;
	stack_t *head = stack;

	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

/**
 * delete_dnodeint_at_index - Deletes the node at index of a linked list.
 * @head: The head of the list
 * @index: Index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int count;
	stack_t *target, *node;

	target = *head;

	if (*head == NULL)
		return (-1);
	else if (index == 0)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(target);
		return (1);
	}

	for (count = 0; count < index; count++)
	{
		node = target;
		if (target->next == NULL)
			return (-1);
		target = target->next;
	}

	node->next = target->next;
	if (node->next != NULL)
		node->next->prev = node;
	free(target);

	return (1);
}
