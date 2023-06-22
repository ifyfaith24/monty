#include "monty.h"

/**
 * add_node - add node at the top of LinkList
 * @stack: double pointer to stack
 * @n: data passed
 * Return: 0 upon success otherise 1
 */
int add_node(stack_t **stack, int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (1);

	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack == NULL)
		*stack = newnode;
	else
		(*stack)->prev = newnode;
	*stack = newnode;
	return(0);
}

/**
 * del_stack - delets complete stack
 * @stack: double pointer to stack
 */
void del_stack(stack_t **stack)
{
	stack_t *temp;

	while((*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free(*stack);
}

/**
 * del_top_node - deletes top node from stack
 * @stack: double pointer to stack
 * Return: 0 upon success, otherwise 1
 */
int del_top_node(stack_t **stack)
{
	stack_t *ret_node;

	if (*stack == NULL)
		return (1);

	ret_node = *stack;
	if (ret_node->next == NULL)
	{
		free(ret_node);
		*stack = NULL;
		return (0);
	}

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(ret_node);
	return (0);
}

/**
 * print_stack - prints all elements in stack
 * @stack: double pointer to stack
 * Return: 0 upon success otherwise 1
 */
int print_stack(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		return (1);
	}
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (0);
}
