#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack head
 * @line_number: line number in the stack
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = *stack;
	while (top)
	{
		if (top->n > 127 || top->n <= 0)
		{
			break;
		}
		fprintf("%c", top->n);
		top = top->next;
	}
	fprintf("\n");
}
