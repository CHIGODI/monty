#include "monty.h"
/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack.
 * @stack: pointer to stack
 * @line_number: current line number in the stack
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
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
                fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(stack);
                exit(EXIT_FAILURE);
        }
        sec = top->n * top->next->n;
        top->next->n = sec;
        *stack = top->next;
        free(top);
}
