#include "monty.h"

/**
 * div_fail - error for the case where there's
 * not enough elements when you try to div.
 */
void div_fail(void)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}

/**
 * mul_fail - error for the case where there's
 * not enough elements when you try to mul.
 */
void mul_fail(void)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}

/**
 * mod_fail - error for the case where there's
 * not enough elements when you try to mod.
 */
void mod_fail(void)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}
