#include "monty.h"
/**
 * rot1 -  rotates the stack to the top.
 * @stack: pointer to top of stack
 * @line_number: line NUMber of opcode
 *
 * Return: nothing!
 *
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top;

	(void) line_number;
	if (*stack == NULL)
		return;

	temp = *stack;
	top = (*stack)->next;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *stack;
	(*stack)->prev = temp;
	top->prev = NULL;
	(*stack)->next = NULL;
	*stack = top;
}
