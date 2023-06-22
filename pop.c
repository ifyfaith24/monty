#include "monty.h"

/**
 * pop - checks fail case for deleting top node from stack
 * @stack: double pointer to stack
 * @line_number: current error line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (del_top_node(stack) == 1)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
