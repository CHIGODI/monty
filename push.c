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

	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		perror(malloc);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	if (data == 0 || arg == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number)
	}
	new_item->n = arg;
	new_item->next = *stack;
	new_item->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new_item;
	}
	*stack = new_item;
}
