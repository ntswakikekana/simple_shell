#include "shell.h"

/**
 * shell_exit - Exits the shell
 * @args: Arguments
 *
 * Return: 0 to exit
 */
int shell_exit(char **args)
{
	(void)args;
	return (0);
}

/**
 * shell_cd - Changes directory
 * @args: Arguments
 *
 * Return: 1 to continue
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
		print_error("cd: expected argument");
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
	return (1);
}

/**
 * shell_help - Displays help message
 * @args: Arguments
 *
 * Return: 1 to continue
 */
int shell_help(char **args)
{
	(void)args;
	printf("Simple Shell\n");
	printf("Type commands and press enter.\n");
	return (1);
}
/**
 * handle_builtin - Handles built-in shell commands
 * @args: Argument list
 *
 * Return: 1 if it's a built-in command, 0 otherwise
 */
int handle_builtin(char **args)
{
    if (args[0] == NULL)
        return (0);

    if (strcmp(args[0], "exit") == 0)
        return (shell_exit(args));  // Call the shell_exit function

    if (strcmp(args[0], "cd") == 0)
        return (shell_cd(args));  // Call the shell_cd function

    if (strcmp(args[0], "help") == 0)
        return (shell_help(args));  // Call the shell_help function

    return (0);  // Return 0 if not a built-in command
}
