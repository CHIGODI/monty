#include "monty.h"
/**
 * div - divides the second top element of the stack by
 * the top element of the stack.
 * @stack: pointer to stack
 * @line_number: current line number in the stack
 * Return: nothing
 */
void div_(stack_t **stack, unsigned int line_number)
{
        stack_t *top, *second;
        int diff = 0;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
                free_stack(stack);
                exit(EXIT_FAILURE);
        }
        top = *stack;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero",
			line_number);
		exit(EXIT_FAILURE);
		free_stack(stack);
	}
        second = (*stack)->next;

        diff = ((second->n) / (top->n));
        second->n = diff;
        *stack = second;
        second->prev = NULL;
        free(top);
}
