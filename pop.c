#include "monty.h"
/**
 * pop - function that removes top element of stack
 * @stack: pointer to top element
 * @line_number: line of stack
 *
 * Return: void
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		free(global.command);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
