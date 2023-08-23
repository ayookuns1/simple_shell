#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>


#define TOKEN_BUFSIZE 64

char *read_input(void);
char **parse_input(char *input);
int execute_builtin(char **args);
int execute_command_with_path(char **args);
void execute_command(char **args);
char *find_command_in_path(const char *command);
void free_args(char **args);
void print_environment(void);
void handle_interactive(void);
void handle_non_interactive(void);


#endif /* SIMPLE_SHELL_H */

