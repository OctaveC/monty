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
		error_handler(3);

	if (is_digit_str(data.args[1]) > 0)
	{
		free(new);
		error_handler(5);
	}

	new->n = atoi(data.args[1]);

	if (data.format == LIFO)
		add_node_LIFO(stack, new);
	else if (data.format == FIFO)
		add_node_FIFO(stack, new);
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

/**
 * monty_pint - Prints the value at the top of the stack
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_pint(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	if (*stack == NULL)
		error_handler(6);
	printf("%d\n", (*stack)->n);
}

/**
 * monty_pop - Removes the top element of the stack.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_pop(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	if (*stack == NULL)
		error_handler(7);

	head = head->next;
	free(*stack);
	*stack = head;
	if (head != NULL)
		head->prev = NULL;
}

/**
 * monty_swap - Swaps the two top element of the stack.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_swap(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *first, *second;

	if (dlistint_len(*stack) < 2)
	error_handler(8);

	first = (*stack);
	second = (*stack)->next;

	/* assign the top element's new next and prev */
	first->next = second->next;
	first->prev = second;

	/* assign the second from the top element's new next and prev */
	/* and connect it to the rest of the list */
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	(*stack) = second;
}
