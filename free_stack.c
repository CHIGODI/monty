#include "monty.h"
/**
 * free_stack - frees stack
 * @stack: pointer to top of stack
 *
 * Return: nothing!
 *
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
