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
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(global.command);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}
