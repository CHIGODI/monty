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
        stack_t *top, *second;
        int prdct = 0;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n",
                        line_number);
                free_stack(stack);
                exit(EXIT_FAILURE);
        }
        top = *stack;
        second = (*stack)->next;

        prdct = ((second->n) * (top->n));
        second->n = prdct;
        *stack = second;
        second->prev = NULL;
        free(top);
}
