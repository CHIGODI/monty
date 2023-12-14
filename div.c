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
        int div = 0;

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
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
        second = (*stack)->next;

        div = ((second->n) / (top->n));
        second->n = div;
        *stack = second;
        second->prev = NULL;
        free(top);
}
