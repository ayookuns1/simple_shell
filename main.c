#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void handle_non_interactive(void)
{
    char *input = NULL;
    char **args = NULL;

    size_t input_size = 0;
    ssize_t read = getline(&input, &input_size, stdin);

    if (read == -1)
    {
       
        exit(EXIT_SUCCESS);
    }

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

 
}


void handle_interactive(void)
{
    char *input;
    char **args;
    int interactive = isatty(STDIN_FILENO);

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
}

int main(void)
{
    int interactive = isatty(STDIN_FILENO);

    if (!interactive)
    {
        handle_non_interactive();
        return EXIT_SUCCESS;
    }

    handle_interactive();

    return EXIT_SUCCESS;
}

