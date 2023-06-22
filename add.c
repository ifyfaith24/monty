#include "monty.h"

/**
 * add_func - adds stack data
 * @stack: double pointer to stack
 * @line_number: current error line
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		fclose(global.fd);
		free(global.opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	holder = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->n += (*stack)->prev->n;
	(*stack)->prev = NULL;
	free(holder);
}
