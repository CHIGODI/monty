#include "monty.h"
/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: pointer to stack
 * @line_number: current line number in the stack
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
        stack_t *top, *second;
        int modulo = 0;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n",
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

        modulo = ((second->n) % (top->n));
        second->n = modulo;
        *stack = second;
        second->prev = NULL;
        free(top);
}
