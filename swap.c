#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to top element of stack
 * @line_number: linee number of stack
 *
 * Return: void
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n"
		       , line_number);
		free(global.command);
		free_stack(stack);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = (*stack)->next;

	top->next = second->next;
	if (second->next != NULL)
		second->next->prev = top;

	second->prev = NULL;
	second->next = top;
	top->prev = second;
	*stack = second;
}
