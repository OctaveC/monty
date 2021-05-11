#include "monty.h"

/**
 * error_handler - Chooses the correct error to print depending on code.
 * @num: the code associated with the error
 *
 * Return: Nothing
 */
void error_handler(int num)
{
	error_t error[] = {
		{1, usage_fail},
		{2, opening_fail},
		{3, instruction_fail},
		{4, malloc_fail},
		{5, push_fail},
		{6, pint_fail},
		{7, pop_fail},
		{8, swap_fail},
		{0, NULL}
	};
	int ite = 0;

	while ((error + ite)->err_code)
	{
		if (num == (error + ite)->err_code)
		{
			(error + ite)->err_f();
		}
		ite++;
	}
}
