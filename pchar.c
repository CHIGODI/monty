#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: current line of the stack
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (!top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}
