#include "monty.h"

/**
 * nop - a function that does nothing
 * @stack: double pointer to stack
 * @line_number: current error line
 */
void nop(stack_t **stack, unsigned int line_number)
{
	stack--;
	line_number--;
}
