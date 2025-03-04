#include "shell.h"

/**
 * main - Entry point for the shell
 *
 * Return: Always 0
 */
int main(void)
{
	signal(SIGINT, signal_handler);
	shell_loop();

	return (0);
}
