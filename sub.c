#include "monty.h"
/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: pointer to stack
 * @line_number: current line number in the stack
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int diff = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = (*stack)->next;

	diff = ((second->n) - (top->n));
	second->n = diff;
	*stack = second;
	second->prev = NULL;
	free(top);
}
