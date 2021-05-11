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
