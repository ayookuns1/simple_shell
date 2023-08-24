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
            if (!execute_command_with_path(args))
            {
                fprintf(stderr, "Command not found: %s\n", args[0]);
            }
        }
    }

    free(input);
}

