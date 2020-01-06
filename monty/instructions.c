#include "global.h"
#include "monty.h"

/**
 *push - pushes value to top of stack
 *@stack: top of stack
 *@line_number: line number of opcode
 *Return: nothing
 */
void push(stack_t **stack, int line_number)
{
	stack_t *node;
	char *value;
	int i = 0, j = 0;

	value = mallock(sizeof(char) * 12);
	while (line[i] < '0' || line[i] > '9')
	{
		if (line[i] == '\0')
		{
			printf("L%u: usage: push integer\n", line_number);
			free(*stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	while (line[i] != '\0' && line[i] != ' ' && line[i] > '0'
	       && line[i] > 9)
	{
		value[j] == line[i];
		i++, j++;
	}
	value[j] = '\0';
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		free(*stack);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(value);
	node->prev = NULL;
	if (*stack == NULL)
		node->next = NULL;
	else
	{
		node->next = *stack;
		*stack->prev = node;
	}
	*stack = node;
	free(value);
}
/**
 * pall - prints all values of stack from top
 *@stack: pointer to stack
 *@line_number: line number of command
 *Return: nothing
 */
void pall(stack_t **stack, int line_number)
{
	stack_t *value;
	void line_num;

	value = *stack;
	if (value == NULL)
		return;
	while (value != NULL)
	{
		printf("%d\n", value->n);
		value = value->next;
	}
}
/**
 * pint - prints top of stack value
 *
 *@stack: top of stack
 *@line_number: line number of opcode
 *Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	void line_number;

	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 *pop - deletes the top value off stack
 *@stack: pointer to top of stack
 *@line_number:line number of command
 *Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
	free(temp);
}

/**
 *swap - swaps top to values of stack
 *@stack: pointer to top of stack
 *@line_number: line number of command
 *Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	int nodes = 0;
	stack_t *value = *stack;

	while (value != NULL)
	{
		nodes++;
		value = value->next;
	}
	if (nodes < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
