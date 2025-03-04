#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define DELIM " \t\r\n\a"

/* Function Prototypes */
void shell_loop(void);
char *read_line(void);
char **tokenize_line(char *line);
int execute_command(char **args);
int run_command(char **args);
int handle_builtin(char **args);
char *get_location(char *command);
void signal_handler(int sig);
void free_tokens(char **tokens);
void print_error(const char *message);

/* Built-in command functions */
int shell_exit(char **args);
int shell_cd(char **args);
int shell_help(char **args);

#endif /* SHELL_H */
