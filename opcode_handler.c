#include "monty.h"
/**
 * opcode_mapper - maps opcode with its function
 * @command: command to be mapped to function
 *
 * Return: function to be executed
 *
 */
void (*opcode_mapper(const char *command))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t array[20] = {
		{"push", push},
		{"pall", pall},
		{"pint",pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"0", NULL}
	};
	for (; array[i].opcode != NULL; i++)
	{
		if (strcmp(array[i].opcode, command) == 0)
		{
			return (array[i].f);
		}
	}
	return (NULL);
}
