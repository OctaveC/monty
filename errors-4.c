#include "monty.h"

/**
 * pchar_range_fail - error for the case where
 * the value is not in the ascii table.
 */
void pchar_range_fail(void)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}

/**
 * pchar_empty_fail - error for the case where
 * the stack is empty.
 */
void pchar_empty_fail(void)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}
