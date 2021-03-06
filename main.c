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

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "ERROR: Can't open file %s\n", argv[1]);
		free(line);
		exit(EXIT_FAILURE);
	}
	stack = runopcode((file), stack);
	fclose(file);
	free(line);
	freestack(stack);
	return (0);
}
