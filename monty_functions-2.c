#include "monty.h"

/**
 * monty_add - Adds together the top two elements of the stack.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_add(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *first, *second;
	int add;

	if (dlistint_len(*stack) < 2)
		error_handler(9);

	first = (*stack);
	second = (*stack)->next;

	add = first->n + second->n;
	(*stack)->n = add;
	delete_dnodeint_at_index(stack, 1);
}

/**
 * monty_nop - Does NOTHING.
 * @stack: unused attribute
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_nop(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
}

/**
 * monty_sub - Subtracts the top element of the stack from the second top
 * element of the stack.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_sub(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *first, *second;
	int sub;

	if (dlistint_len(*stack) < 2)
		error_handler(10);

	first = (*stack);
	second = (*stack)->next;

	sub = second->n - first->n;
	(*stack)->n = sub;
	delete_dnodeint_at_index(stack, 1);
}

/**
 * monty_div - Divides the second top element of the stack by the top element
 * of the stack.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_div(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *first, *second;
	int div;

	if (dlistint_len(*stack) < 2)
		error_handler(11);

	first = (*stack);
	if (first->n == 0)
		error_handler(14);
	second = (*stack)->next;

	div = second->n / first->n;
	(*stack)->n = div;
	delete_dnodeint_at_index(stack, 1);
}

/**
 * monty_mul - Multiplies the top two elements of the stack.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_mul(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *first, *second;
	int mul;

	if (dlistint_len(*stack) < 2)
		error_handler(12);

	first = (*stack);
	second = (*stack)->next;

	mul = second->n * first->n;
	(*stack)->n = mul;
	delete_dnodeint_at_index(stack, 1);
}
