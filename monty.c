#include "monty.h"
#include <ctype.h>

/**
 * rm_space - removes spaces in a line
 * @str: pointer to a string
 * Return: nothing
 */
void rm_space(char *str)
{
	size_t len;

	for (len = 0; str[len] !+ '\0'; len++)
		;
	str[len - 1] = '\0';
}


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
	FILE *fp = NULL;
	char *command = NULL;
	char *cmd = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	void (*function)(stack_t **, unsigned int) = NULL;

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
	command = malloc(sizeof(char) * MAX_COMMAND_LENGTH);
	if (command == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	while (fgets(command, sizeof(command), fp) != NULL)
	{
		line_number++;
		cmd = strtok(command, " \t\r\n");
		if (cmd == NULL)
			continue;
		arg = strtok(NULL, " \t\r\n");
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
	return (0);
}
