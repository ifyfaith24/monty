#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* commands */
void (*myCmd(char *cmd, unsigned int ln))(stack_t **, unsigned int);
void push(stack_t **stack, int num);
void Pall(stack_t **stack, unsigned int line_number);
void Pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void mySub(stack_t **stack, unsigned int ln);
void myDiv(stack_t **stack, unsigned int ln);
void myMul(stack_t **stack, unsigned int ln);
void myMod(stack_t **stack, unsigned int ln);

/* error printing functions */
void usage_err(int n);
void file_err(char *av, FILE *fp);
void malloc_err(char *buf);
void inst_err(unsigned int ln, char *cmd);
void swap(stack_t **stack, unsigned int line_number);

/* helper functions */
void _push(char *cmd, stack_t **stack, unsigned int ln);
void free_list(stack_t **stack);

#endif
