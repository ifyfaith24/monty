#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the given stack
 * @line_number: line number
 * Return: returns nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
