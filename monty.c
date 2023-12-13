#include "monty.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 *
 * Return: 0 always succesfull
 *
 */
char *arg = NULL;
int main(int argc, char *argv[])
{
	FILE *fp;
	char *command = NULL;
	size_t len = 0;
	ssize_t read;
	char *cmd;
	void (*function)(stack_t **, unsigned int);
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		write(2, "Error: Can't open file\n", 23);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&command, &len, fp)) != -1)
	{
		line_number++;
		cmd = strtok(command, " \t\r\n");
		if (cmd == NULL)
		{
			continue;
		}
		arg = strtok(NULL, " \t\r\n");
		function = opcode_mapper(cmd);
		if (function == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, cmd);
			free(command);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		function(&stack, line_number);
	}

	free(command);
	fclose(fp);
	return 0;
}
