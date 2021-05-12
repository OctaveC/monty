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
	if (first->n == 0)
		error_handler(14);
	second = (*stack)->next;

	mod = second->n % first->n;
	(*stack)->n = mod;
	delete_dnodeint_at_index(stack, 1);
}

/**
 * monty_pchar - Prints the char at the top of the stack,
 * followed by a new line.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_pchar(stack_t **stack,
	       unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	if (!head)
		error_handler(16);
	else if (head->n < 65 || head->n > 122)
		error_handler(15);
	else
		printf("%c\n", head->n);
}

/**
 * monty_pstr - Prints the string using each ascii value starting from the top
 * of the stack, followed by a new line.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_pstr(stack_t **stack,
	       unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		if (current->n >= 1 && current->n <= 127)
		{
			if (current->n >= 32 && current->n <= 127)
				putchar(current->n);

			current = current->next;
		}
		else
			break;
	}
	putchar('\n');
}

/**
 * monty_rotl - The top element of the stack becomes the last one, and
 * the second top element of the stack becomes the first one.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_rotl(stack_t **stack,
	       unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;
	int placeholder;

	if (head != NULL && head->next != NULL)
	{
		placeholder = head->n;
		while (head->next != NULL)
		{
			head->n = head->next->n;
			head = head->next;
		}
		head->n = placeholder;
	}
}

/**
 * monty_rotr - The last element of the stack becomes the top element
 * of the stack.
 * @stack: A doubly linked list
 * @line_number: unused attribute
 *
 * Return: Nothing
 */
void monty_rotr(stack_t **stack,
	       unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;
	int current, following;

	if (head != NULL && head->next != NULL)
	{
		following = head->n;
		while (head->next != NULL)
		{
			current = following;
			following = head->next->n;
			head->next->n = current;
			head = head->next;
		}
		(*stack)->n = following;
	}
}
