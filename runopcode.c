#include "global.h"
#include "monty.h"
/**
 *runopcode - runs op code for monty
 *@file: the file to be run
 *@stack: pointer to top of stack
 *Return: pointer to stack
 */
void runopcode(FILE *file, stack_t *stack)
{
	int num_of_chars = 0;
	int i, j;
	unsigned int line_number;
	size_t size;
	stack_t *stack;

	while (num_of_chars != -1)
	{
		line = NULL;
		size = 0, i = 0, j = 0;
		num_of_chars = getline(&line, &size, file);
		line_num++;
		while (line[j] == ' ')
		{
			j++;
		}
		if (line[j] == '\n')
		{
			continue;
		}
		while (line[i] != '\n' && line[i] != '\0')
		{
			i++;
		}
		line[i] = '\0';
		if (line[0] == '\0')
			break;
		opcode = condense();
		getopcode(&stack, line_number, opcode);
		free(opcode);
		free(line);
	}
	return (stack);
}
