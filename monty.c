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
int main(int argc, char *argv[])
{
	stact_t *stack;
	FILE *fp;
	int read = 1;
	char *command, len;
	char *cmd;
	instruction_t (*function);

	if (argc == 0 || argc > 2)
	{
		write(2, "USAGE: monty file", 17);
		exit(EXIT_FAILURE);
	}
	fp = open(argv[1] , O_RDONLY);
	if (fp == NULL)
	{
		write(2, "Error: Can't open file <file>", 29);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		read = getline(&command, &len, fp);
		line_number++;
		cmd = strtok(command, " \t\r");
		arg = strtok(NULL, " \t\r");
		function = opcode_handler(cmd);
		if (function == NULL)
		{
			write(2, "L"line_number:unknown instruction cmd,20);
			exit(EXIT_FAILURE);
		}
		function(stack, line_number);
	}
	close(fp);
	return (0);
}
