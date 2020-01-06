#include "monty.h"
#include "global.h"
char *line;
/**
 * main - entry point for monty
 *@argc: number of arguments
 *@argv: list of args
 *
 * Return: 0
 */

Int main(int argc, int **argv)
{
	stack_t *stack = NULL;
	FILE *file;
	int i, j;
	int line_num = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAIlURE);
	}
	file = fopen(argv[1], r);
	if (file == NULL)
	{
		pirntf("ERROR: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	run_opcode(file, stack);
	fclose(file);
	free(line);
	free_stack(stack);
	return (0);
}
