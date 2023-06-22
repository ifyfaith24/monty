#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the given node
 * @line_number: line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int x, num;
	stack_t *temp;

	temp = *stack;
	x = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		++x;
	}
	if (x < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
