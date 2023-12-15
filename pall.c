#include "monty.h"
/**
 * pall - prints all elememts of a stack
 * @stack: pointer to top of stack
 * @line_number: line of current element of stack
 *
 * Return: void
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void) line_number;

	if (*stack == NULL)
		return;

	top = *stack;
	while (top != NULL)
	{
		fprintf(stdout, "%d\n", top->n);
		top = top->next;
	}
}
