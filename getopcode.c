#include "monty.h"
#include "global.h"

/**
 *getopcode - finds opcode in struct and runs paired function
 *@stack: top of stack
 *@line_number: line number of command
 *@opcode: opcode
 *Return: nothing
 */
void getopcode(stack_t **stack, unsigned int line_number, char *opcode)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(2,"L%u: unknown instruction %s\n", line_number, opcode);
	freestack(stack);
	exit(EXIT_FAILURE);
}
