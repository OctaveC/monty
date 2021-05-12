#include "monty.h"

/**
 * is_digit_str - checks if a string is made only of ints
 * @str: String we want to check
 *
 * Return: 0 if all ints, 1 otherwise
 */
int is_digit_str(char *str)
{
	int ite;

	if (str == NULL)
		return (1);
	for (ite = 0; str[ite]; ite++)
	{
		if (ite == 0 && str[0] == '-')
			ite++;
		if (isdigit(str[ite]) == 0)
			return (1);
	}
	return (0);
}
