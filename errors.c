#include "monty.h"

/**
 * usage_fail - error for the case where there's
 * too many or not enough arguments
 */
void usage_fail(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * opening_fail - error for the case where you can't open the monty file
 */
void opening_fail(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", data.filename);
	exit(EXIT_FAILURE);
}

/**
 * instruction_fail - error for the case where the opcode is unknown
 */
void instruction_fail(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", data.line_num, data.args[0]);
	free_data();
	exit(EXIT_FAILURE);
}

/**
 * malloc_fail - error for the case where malloc fails
 */
void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_data();
	exit(EXIT_FAILURE);
}

/**
 * push_fail - error for the case where what's passed to push is not an int
 */
void push_fail(void)
{
	fprintf(stderr, "L%d: usage: push integer\n", data.line_num);
	free_data();
	exit(EXIT_FAILURE);
}
