#include "shell.h"

/**
 * shell_loop - Runs the shell in a loop
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status = 1;

	while (status)
	{
		printf("$ ");
		line = read_line();
		args = tokenize_line(line);
		status = execute_command(args);

		free(line);
		free_tokens(args);
	}
}
