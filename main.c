#include "monty.h"

/**
 * main - interpretes monty bytecodes
 * @argc: number of arguments passed to main
 * @argv: arguments passed to main
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	FILE *fp; stack_t *stk; char *cmd, *buf;
	int line_number = 0; int i; size_t size;

	stk = NULL; buf = NULL;
	usage_err(argc);
	fp = fopen(argv[1], "r"), file_err(argv[1], fp);
	while (1)
	{
		getline(&buf, &size, fp);
		if (buf == NULL)
			break;
		for (i = 0; buf[i] != '\0'; ++i)
		{
			if (buf[i] != ' ' && buf[i] != '\t')
				break;
		}
		if (!feof(fp))
		{
			++line_number;
			if (buf[0] == '#' || buf[i] == '\0')
				continue;
			cmd = strtok(buf, " \t\n");
			if (cmd == NULL)
				continue;
			if (strcmp(cmd, "push") == 0)
			{
				cmd = strtok(NULL, " \t\n");
				_push(cmd, &stk, line_number);
			}
			else if (strcmp(cmd, "nop"))
				(*myCmd)(cmd, line_number)(&stk, line_number);
		}
		else
			break;
	}
	free(buf), free_list(&stk), fclose(fp);
	return (0);
}
