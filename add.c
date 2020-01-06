#include "monty.h"
/**
 *add - adds the top two values of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command
 *
 *Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;
	int nodes = 0;
	stack_t *iterator = *stack;

	while (iterator != NULL)
	{
		nodes++;
		iterator = iterator->next;
	}
	if (nodes < 2)
	{
		fprintf(2, "L%u: can't add, stack too short\n", line_number);
		freestack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 *nop - does nothing
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command
 *
 *Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
