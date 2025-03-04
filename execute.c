#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: Argument list
 *
 * Return: 1 if the shell should continue, 0 if it should exit
 */
int execute_command(char **args)
{
	if (args[0] == NULL)
		return (1);

	if (handle_builtin(args))
		return (1);

	return (run_command(args));
}

/**
 * run_command - Runs an external command
 * @args: Command and arguments
 *
 * Return: 1 to continue, 0 to exit
 */
int run_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path = get_location(args[0]);

	if (cmd_path == NULL)
	{
		print_error("Command not found");
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, args, NULL) == -1)
			perror("execve error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("fork error");
	else
		waitpid(pid, &status, 0);

	free(cmd_path);
	return (1);
}
