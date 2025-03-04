#include "shell.h"

/**
 * get_location - Gets full path of command
 * @command: Command name
 *
 * Return: Full path or NULL
 */
char *get_location(char *command)
{
	char *path = getenv("PATH");
	char *token, *cmd_path;
	struct stat st;

	if (stat(command, &st) == 0)
		return (strdup(command));

	token = strtok(path, ":");
	while (token)
	{
		cmd_path = malloc(strlen(token) + strlen(command) + 2);
		sprintf(cmd_path, "%s/%s", token, command);

		if (stat(cmd_path, &st) == 0)
			return (cmd_path);

		free(cmd_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
