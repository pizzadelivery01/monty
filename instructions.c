#include "global.h"
#include "monty.h"

/**
 *push - pushes value to top of stack
 *@stack: top of stack
 *@line_number: line number of opcode
 *Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *value;
	int i = 0, j = 0;

	value = malloc(sizeof(char) * 12);
	while (line[i] < '0' || line[i] > '9')
	{
		if (line[i] == '\0')
		{
			fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			freestack(*stack);
			free(line);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	while (line[i] != '\0' && line[i] != ' ' && line[i] >= '0'
	       && line[i] >= '9')
	{
		value[j] = line[i];
		i++, j++;
	}
	value[j] = '\0';
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freestack(*stack);
		free(line);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(value);
	node->prev = NULL;
	if (*stack == NULL)
		node->next = NULL;
	else
	{
		node->next = *stack;
		(*stack)->prev = node;
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
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *value;

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
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freestack(*stack);
		free(line);
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
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freestack(*stack);
		free(line);
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
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		freestack(*stack);
		free(line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
