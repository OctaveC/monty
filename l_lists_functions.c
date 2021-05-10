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
