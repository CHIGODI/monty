#include "monty.h"
/**
 * _push - function that inserts items in a stack
 * @stack: stack to be used
 * @data: data to be pushed
 *
 * Return: Void
 *
 */
void _push(stack_t **stack, int data)
{
	stack_t *new_item;

	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		printf("\n");
		exit(EXIT_FAILURE);
	}
	new_item->n = data;
	new_item->next = *stack;
	new_item->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new_item;
	}
	*stack = new_item;
}

/**
 * _pop - function that removes top element of stack
 * @stack: pointer to top element
 *
 * Return: void
 *
 */

void _pop(stack_t **stack)
{
	stack_t *top;

	top = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to top of the stack
 * @line_number: line number of stack
 *
 * Return: void
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int sum  = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n"
		       , line_number);
		free(global.command);
		fclose(global.fp);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = (*stack)->next;

	sum = ((top->n) + (second->n));
	_pop(stack);
	_pop(stack);
	_push(stack, sum);
}
