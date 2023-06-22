#include "monty.h"

/**
 * swap - swaps two elements of a stack
 * @stack: double pointer to stack
 * @line_number: current error line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || ((*stack)->next == NULL))
	{
		printf("L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
