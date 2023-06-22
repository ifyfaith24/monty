#include "monty.h"

/**
 * pint - prints top nodes element
 * @stack: double pointer to stack
 * @line_number: current error line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (!top)
		printf("L%d: can't pint, stack empty\n", line_number);

	printf("%d\n", top->n);
}
