#include "monty.h"
#include <ctype.h>

int vld_num(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * push - function that inserts items in a stack
 * @stack: stack to be used
 * @line_number: line number
 *
 * Return: Void
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_item;
	int data;
	int check = vld_num(global.arg);

	if (global.arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(global.command);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	if (check == 1)
		data = atoi(global.arg);
	else
		data = 0;
	if (data == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(global.command);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_item->n = data;
	new_item->next = *stack;
	new_item->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new_item;
	}
	*stack = new_item;
}
