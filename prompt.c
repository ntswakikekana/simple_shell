#include "shell.h"

/**
 * read_line - Reads a line from standard input
 *
 * Return: The line read
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(0);
		}
		else
		{
			perror("read_line");
			exit(1);
		}
	}
	return (line);
}
