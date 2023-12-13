#include "monty.h"
/**
 * push - function that inserts items in a stack
 * @stack: stack to be used
 * @line_number: line number
 *
 * Return: Void
 *
 */
void push(stack_t **stack, unsigned int line_numberz)
{
	stack_t *new_item, *temp;

	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		perror(malloc);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	new_item->n = arg;
	new_item->next = NULL;
	new_item->prev = NULL;
	*stack = temp;
}
