#include "monty.h"

int data = 0;

void (*get_op_func(char *opcode))(stack_t **, unsigned int);
void del_stack(stack_t **stack);

/**
 * main - entry point for stack program
 * @argc: number of arguements passed
 * @argv: arguement vectors
 * Return: 0 upon success
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *cmd, *sep_cmd, *file;
	size_t length;
	int gl;
	void (*op)(stack_t **stack, unsigned int line_number);
	unsigned int line_number;
	stack_t *stack;

	stack = NULL;
	cmd = NULL;
	file = argv[1];
	fp = fopen(file, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	if (argc != 2)
	{
		printf("usage: monty file");
		exit(EXIT_FAILURE);
	}

	line_number = 1;
	gl = getline(&cmd, &length, fp);
	while (gl >= 0)
	{
		sep_cmd = strtok(cmd, " \t\n");

		if (sep_cmd)
		{
			op = get_op_func(sep_cmd);
			sep_cmd = strtok(NULL, " \t\n");
		}
		if (sep_cmd)
		{
			data = atoi(sep_cmd);
		}
		op(&stack, line_number);
		line_number++;
		gl = getline(&cmd, &length, fp);
	}
	fclose(fp);
	free(cmd);

	return(0);
}
