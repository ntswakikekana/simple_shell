Simple Shell

Description

This project is a custom Unix shell implementation written in C. It provides a command-line interface that allows users to execute commands similar to the standard Unix shell. The shell can execute built-in and external commands, handle paths, and support interactive and non-interactive modes.

Features

Displays a prompt and waits for user input.

Executes commands using the execve() system call.

Handles absolute and relative paths.

Supports built-in commands like exit and env.

Implements a basic command-line parser.

Handles user input with getline().

Supports both interactive and non-interactive modes.

Compilation

Compile the shell using:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Usage

Run the shell using:

./hsh

Then, type commands and press Enter to execute.

Example

$ ls -l
$ pwd
$ echo "Hello, World!"
$ exit

Authors

Ntswaki Kekana

License

This project is part of the ALX Software Engineering program and is for educational purposes only.


