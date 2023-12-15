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
		printf("L%d: can't add, stack too short"
		       , line_number);
		free(global.command);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = (*stack)->next;

	top->next = second->next;
	top->prev = second;
	if (second->next != NULL)
		second->next->prev = top;

	second->prev = NULL;
	*stack = second;
}
