#include "simple_shell.h"
/**
 * handle_interactive - This is entry point of simple shell program
 *
 * Fuctn handles interactive mode
 *
 * Return: EXIT_SUCCESS (Always)
 */

int is_space(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

void handle_interactive(void)
{
    char *input;
    char **args;
    int interactive = isatty(STDIN_FILENO);
    int i;

    while (interactive)
    {
        printf("shell$ ");
        fflush(stdout);
        input = read_input();

        if (input == NULL)
        {
            exit(EXIT_SUCCESS);
        }

        args = parse_input(input);

     
        for (i = 0; input[i] != '\0'; i++)
        {
            if (!is_space(input[i]))
            {
                break;
            }
        }

        if (input[i] != '\0')
        {
            if (args[0] != NULL)
            {
                if (execute_builtin(args) == 0)
                {
                    if (!execute_command_with_path(args))
                    {
                        fprintf(stderr, "Command not found: %s\n", args[0]);
                    }
                }
            }
            else
            {
                fprintf(stderr, "Command not found: %s\n", input);
            }
        }

    }
      free(input);
}


