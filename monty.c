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
char *arg;
int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *command = NULL;
	char *cmd = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	void (*function)(stack_t **, unsigned int) = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	command = malloc(sizeof(char) * MAX_COMMAND_LENGTH);
	if (command == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	while (fgets(command, MAX_COMMAND_LENGTH, fp) != NULL)
	{
		line_number++;
		cmd = strtok(command, " \t\n");
		if (cmd == NULL)
			continue;
		arg = strtok(NULL, " \t\n");
		function = opcode_mapper(cmd);
		if (function == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, cmd);
			free(command);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		function(&stack, line_number);
	}
	free(command);
	fclose(fp);
	free_stack(&stack);
	return (0);
}
