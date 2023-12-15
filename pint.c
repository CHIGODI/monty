#include "monty.h"
/**
 * pint - prints top elemnt of stack
 * @stack: pointe rto top element of stack
 * @line_number: line number of stack
 *
 * Return: void
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L<%d>: can't pint, stack empty", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
