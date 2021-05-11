#include "monty.h"
data_t data;

/**
 * main - Takes opcode instructions from a monty file.
 * @argc: The number of arguments that have been passed to our program
 * @argv: An array of all the arguments that have been passed to our program
 *
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		error_handler(1);

	data.filename = argv[1];
	monty_handler();
	return (0);
}

/**
 * monty_handler - Coordinates the analysis of each line of the monty file
 *
 * Return: 0
 */
int monty_handler(void)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	int check = 1;
	stack_t *stack = NULL;
	size_t len = 0;

	data.stack = &stack;
	data.line_num = 0;
	data.opening = fopen(data.filename, "r");
	if (data.opening == NULL)
		error_handler(2);

	while ((check = getline(&data.line, &len, data.opening)) > 0)
	{
		data.line_num++;
		free(data.args);
		cut();
		data.cmd = data.args[0];
		if (data.cmd != NULL)
		{
			f = check_monty();
			if (f != NULL)
				f(&stack, 1);
		}
	}
	free_data();
	return (0);
}

/**
 * cut - Uses strtok to cut the line we're analysing into tokens
 *
 * Return: Nothing
 */
int cut(void)
{
	char *saveptr, *token;
	char *str = data.line;
	int ite = 0;

	data.args = malloc(sizeof(char) * 30);
	if (data.args == NULL)
		error_handler(4);

	for (ite = 0;; ite++, str = NULL)
	{
		token = strtok_r(str, "\t\a\n ", &saveptr);
		if (token == NULL)
		{
			break;
		}
		/* add a realloc here if there's memory issues */
		data.args[ite] = token;
	}
	data.args[ite] = NULL;
	return (0);
}

/**
 * check_monty - checks if one of the opcodes has been called.
 *
 * Return: Nothing
 */
void (*check_monty(void))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{NULL, NULL}
	};
	int ite = 0;

	while ((instruction + ite)->opcode)
	{
		if (strcmp(data.cmd, (instruction + ite)->opcode) == 0)
		{
			return ((instruction + ite)->f);
		}
		ite++;
	}
	error_handler(3);
	return (NULL);
}
