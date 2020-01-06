#include "monty.h"
#include "global.h"

/**
 *condense - removes all spaces from opcode line
 *Return: pointer to condesened opcode
 */

char *condense(void)
{
	int i = 0, j = 0;
	char *buffer;

	buffer = malloc(sizeof(char) * 8);
	if (buffer == NULL)
		return (NULL);
	while (line[j] == ' ')
		j++;
	while (line[j] != ' ' && line[j] != '\0')
	{
		buffer[i] = line[j];
		j++;
		i++;
	}
	buffer[j] = '\0';
	return (buffer);
}
