#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: pointer to the given node
 * @num: value of the element to insert to the node
 * Return: nothing
 */
void push(stack_t **stack, int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	if (*stack == NULL)
		new->next = NULL;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
