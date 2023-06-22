#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* STRUCTS AND DEFINITIONS */
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
 * struct variable_s - opcode string and file pointer fd
 * @opcode: the opcode string
 * @fd: file pointer
 *
 * Description: struct to hold opcode and file pointer
 * as global variable to be able to free all variables
 */
typedef struct variable_s
{
	char *opcode;
	FILE *fd;
} variable_t;

/* FUNCTION PROTOTYPES AND GLOBAL VARIABLE*/
extern variable_t global;

/* function to check initial conditions and open the file */
FILE *opening_func(int argc, char *argv[]);
/* opcodes */
char *getopcode(char **str);
stack_t *addnode(char *opcode, stack_t **stack, unsigned int line_number);
stack_t *findinstruction(char *opcode, stack_t **stack,
			 unsigned int line_number);

/* commands */
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void sub_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);
void div_func(stack_t **stack, unsigned int line_number);
void mod_func(stack_t **stack, unsigned int line_number);

/* stack */
void pchar_func(stack_t **stack, unsigned int line_number);
void pstr_func(stack_t **stack, unsigned int line_number);
void rotl_func(stack_t **stack, unsigned int line_number);
void rotr_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

/* error messages */
void free_for_exit_push(unsigned int line_number, stack_t *stack);
void free_for_exit_malloc(stack_t *stack);
void free_for_exit_error(stack_t *stack);

/* function to check if char is digit */
int _isdigit(int c);

#endif
