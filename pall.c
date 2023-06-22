#include "monty.h"

/**
 * pall - prints all elemts in stack
 * @stack: double pointer to stack
 * @line_number: current error line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	line_number--;

	print_stack(stack);
}
