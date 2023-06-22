#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: pointer to the given node
 * @num: value of the element to insert to the node
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (add_node(stack, data) == 1)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
