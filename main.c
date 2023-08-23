#include "simple_shell.h"
/**
 * main - This is entry point of simple shell program
 *
 * Fuctn implemnts the main loop of the shell
 *
 * Return: EXIT_SUCCESS (Always)
 */
int main(void)
{
char *input;
char **args;

while (1)
{
printf("shell$ ");
fflush(stdout);
input = read_input();
args = parse_input(input);

if (args[0] != NULL)
{
if (execute_builtin(args) == 0)
{
if (!execute_command_with_path(args))
{
printf("Command not found: %s\n", args[0]);
}
}
}
}
return (EXIT_SUCCESS);
}

