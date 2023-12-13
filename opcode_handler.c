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
	int i;
	instruction_t array[] = {
		{"push", push},
		{"pall", pall},
		{"0", NULL}
	};
	for (i = 0; array[i].opcode != NULL; i++)
	{
		if (strcmp(array[i].opcode, command) == 0)
		{
			return (array[i].f);
		}
	}
	return NULL;
}
