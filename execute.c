#include "monty.h"
/**
 * execute_commands - executes
 * @fp: file pointer
 * @stack: pointer to top of stack
 *
 * Return: nothing!
 *
 */
void execute_commands(FILE *fp, stack_t **stack)
{
	void (*function)(stack_t **, unsigned int) = NULL;
	char *cmd = NULL;
	unsigned int line_number = 0;
	char *command;

	command = malloc(sizeof(char) * MAX_COMMAND_LENGTH);
	if (command == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	while (fgets(command, MAX_COMMAND_LENGTH, fp) != NULL)
	{
		if (command[0] != '#')
		{
			cmd = strtok(command, " \t\n");
			if (cmd != NULL)
			{
				global.arg = strtok(NULL, " \t\n");
				function = opcode_mapper(cmd);
				if (function == NULL)
				{
					fprintf(stderr, "L%u: unknown instruction %s\n"
						, line_number, cmd);
					free(command);
					fclose(fp);
					free_stack(stack);
					exit(EXIT_FAILURE);
				}
				function(stack, line_number);
			}
			line_number++;
		}
		else
			line_number++;
	}
	free(command);
	free_stack(stack);
}
