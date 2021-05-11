#include "monty.h"

/**
 * monty_push - Adds a node to the stack with a specific int
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_push(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		/*	free_l_list(**stack); */
		error_handler(3);
	}

	if (is_digit_str(data.args[1]) > 0)
	{
		/*	free_l_list(*stack); */
		free(new);
		error_handler(5);
	}

	new->n = atoi(data.args[1]);

	add_node_LIFO(stack, new);
}

/**
 * monty_pall - Prints the stack
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_pall(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *current;
	int ite;

	current = *stack;
	for (ite = 0; current != NULL; ite++)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
