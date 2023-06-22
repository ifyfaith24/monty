#include "monty.h"

/**
 * _add - adds stack data
 * @stack: double pointer to stack
 * @line_number: current error line
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *node_A, *node_B;

	if  (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	node_A = (*stack);
	node_B = node_A->next;
	node_A->n = node_A->next->n + node_A->n;
	node_A->next = node_B->next;
	if (node_B->next == NULL)
		node_A->next = NULL;
	else
		node_B->next->prev = node_A;
	free(node_B);
}
