#include "monty.h"

/**
 * pint_fail - error for the case where there's
 * an empty stack when you try to pint.
 */
void pint_fail(void)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}

/**
 * pop_fail - error for the case where there's
 * an empty stack when you try to pop.
 */
void pop_fail(void)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}

/**
 * swap_fail - error for the case where there's
 * not enough elements when you try to swap.
 */
void swap_fail(void)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}

/**
 * add_fail - error for the case where there's
 * not enough elements when you try to add.
 */
void add_fail(void)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}

/**
 * sub_fail - error for the case where there's
 * not enough elements when you try to sub.
 */
void sub_fail(void)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}
