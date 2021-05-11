#include "monty.h"

/**
 * monty_stack - Sets the format of the data to a stack (LIFO).
 * @stack: unused attribute
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_stack(stack_t **stack __attribute__((unused)),
	       unsigned int line_number __attribute__((unused)))
{
	data.format = LIFO;
}

/**
 * monty_queue - Sets the format of the data to a queue (FIFO).
 * @stack: unused attribute
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_queue(stack_t **stack __attribute__((unused)),
	       unsigned int line_number __attribute__((unused)))
{
	data.format = FIFO;
}
