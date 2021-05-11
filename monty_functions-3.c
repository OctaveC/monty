#include "monty.h"

/**
 * monty_mod - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * of the stack.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_mod(stack_t **stack,
	       unsigned int line_number __attribute__((unused)))
{
	stack_t *first, *second;
	int mod;

	if (dlistint_len(*stack) < 2)
		error_handler(13);

	first = (*stack);
	second = (*stack)->next;

	mod = second->n % first->n;
	(*stack)->n = mod;
	delete_dnodeint_at_index(stack, 1);
}
