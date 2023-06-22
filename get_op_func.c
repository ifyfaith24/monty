#include "monty.h"

/**
 * get_op_func - gets correlating function
 * @s: value passed to match
 * @stack: double pointer to stack
 * @line_number: current error line
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"add", _add},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};

	int i;

	i = 0;
	while(i <= 6)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			return(ops[i].f);
		}
		i++;
	}
	return (NULL);
}
