#include "monty.h"

/**
 * Pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the given node
 * @line_num: line count currently reading instructions from
 * Return: nothing
 */
void Pall(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr;
	(void) line_num;

	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
