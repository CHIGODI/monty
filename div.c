#include "monty.h"
/**
 * div - divides the top element of the stack from
 * the second top element of the stack.
 * @stack: pointer to stack
 * @line_number: current line number in the stack
 * Return: nothing
 */
void div(stack_t **stack, unsigned int line_number)
{
        stack_t *top;
        int len = 0, sec;

        top = *stack;
        while (top)
        {
                top = top->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(stack);
                exit(EXIT_FAILURE);
        }
	top = *stack;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
        sec = top->next->n / top->n;
        top->next->n = sec;
        *stack = top->next;
        free(top);
}