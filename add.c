#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the given node
 * @line_number: line number
 * Return: returns nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	pop(stack, line_number);
}
