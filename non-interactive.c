#include "simple_shell.h"

void handle_non_interactive(void)
{
    char *input = NULL;
    char **args = NULL;

    size_t input_size = 0;
    ssize_t read;

    while ((read = getline(&input, &input_size, stdin)) != -1)
    {
        if (read > 0 && input[read - 1] == '\n')
        {
            input[read - 1] = '\0';
        }

        args = parse_input(input);

        if (args[0] != NULL)
        {
            if (strcmp(args[0], "exit") == 0)
            {
                free(input);
                free_args(args);
                exit(EXIT_SUCCESS);
            }
            else if (!execute_command_with_path(args))
            {
                fprintf(stderr, "%s: not found\n", args[0]);
            }
        }

        free_args(args);
    }

    free(input);
}
