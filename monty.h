#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - structure containing useful variables
 * @filename: Name of the file to execute
 * @line: the current full line of the monty file
 * @line_num: the number of the line we're on
 * @cmd: The opcode we're going to execute
 * @args: an array of arguments, containing both the opcode and the number
 */
typedef struct data_s
{
	char *filename;
	char *line;
	int line_num;
	char *cmd;
	char **args;
} data_t;

extern data_t data;

/**
 * struct error_s - structure for errors
 * @err_code: Error Code
 * @err_f: Function used to handle error
 */
typedef struct error_s
{
	int err_code;
	void (*err_f)(void);
} error_t;

/* the main important functions */
int monty_handler(void);
int cut(void);
void (*check_monty(void))(stack_t **stack, unsigned int line_number);

/* the monty functions that get called when the correct opcode is selected */
void monty_push(stack_t **stack, unsigned int line_number __attribute__((unused)));
void monty_pall(stack_t **stack, unsigned int line_number __attribute__((unused)));

/* various helper functions */
int is_digit_str(char *str);
void add_node_LIFO(stack_t **stack, stack_t *new);

/* error handling */
void error_handler(int num);
void usage_fail(void);
void opening_fail(void);
void instruction_fail(void);
void malloc_fail(void);
void push_fail(void);
#endif
