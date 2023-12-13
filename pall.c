#include "monty.h"


void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
		exit(EXIT_FAILURE);
	top = *stack;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
