CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

all: hsh

hsh: main.o shell.o prompt.o execute.o builtins.o path.o
	$(CC) $(CFLAGS) -o hsh main.o shell.o prompt.o execute.o builtins.o path.o

clean:
	rm -f *.o hsh

re: clean all
