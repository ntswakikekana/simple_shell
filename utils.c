#include "shell.h"

/* Prints an error message */
void print_error(const char *message)
{
    perror(message);
}

/* Splits a line into tokens */
char **tokenize_line(char *line)
{
    char **tokens = malloc(64 * sizeof(char *));
    char *token;
    int i = 0;

    if (!tokens)
    {
        print_error("Allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n");
    while (token)
    {
        tokens[i++] = token;
        token = strtok(NULL, " \t\r\n");
    }
    tokens[i] = NULL;

    return tokens;
}

/* Frees allocated tokens */
void free_tokens(char **tokens)
{
    free(tokens);
}

/* Handles Ctrl+C (SIGINT) */
void signal_handler(int signum)
{
    (void)signum;
    write(STDOUT_FILENO, "\n$ ", 3);
}
