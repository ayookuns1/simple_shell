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
int interactive = isatty(STDIN_FILENO);

if (!interactive)
{
size_t input_size = 0;

ssize_t read = getline(&input, &input_size, stdin);
if (read > 0 && input[read - 1] == '\n')
input[read - 1] = '\0';

args = parse_input(input);

if (args[0] != NULL)
{
if (execute_builtin(args) == 0)
{
if (!execute_command_with_path(args))
{
fprintf(stderr, "Command not found: %s\n", args[0]);
exit(EXIT_FAILURE);
}
}
}


return (EXIT_SUCCESS);
}


while (interactive)
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






