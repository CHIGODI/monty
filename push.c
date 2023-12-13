#include "monty.h"
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
	int data = atoi(arg);

	if (data == 0 || arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
	}
	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		printf("\n");
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
