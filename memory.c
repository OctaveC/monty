#include "monty.h"

/**
 * free_data - frees the data in our strcut
 *
 * Return: Nothing
 */
void free_data(void)
{
	free(data.line);
	free(data.args);
	free_l_list(data.stack);
	fclose(data.opening);
}

/**
 * free_l_list - frees the data in our doubly linked list
 * @stack: The doubly linked list we're freeing
 *
 * Return: Nothing
 */
void free_l_list(stack_t **stack)
{
	stack_t *h;
	stack_t *placeholder;

	h = *stack;
	while (h != NULL)
	{
		placeholder = h->next;
		free(h);
		h = placeholder;
	}
}
