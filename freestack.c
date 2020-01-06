#include "monty.h"

/**
 * freestack -frees entire stack
 *@stack: pointer to top of stack
 *Return: nothing
 */
void freestack(stack_t *stack)
{
	if (stack)
	{
		freestack(stack->next);
		free(stack);
	}
}
