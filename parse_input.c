#include "simple_shell.h"

char **parse_input(char *input) {
    const char *delimiters = " \t\r\n\a";
    char *token;
    int bufsize = TOKEN_BUFSIZE;
    int position = 0;

    char **tokens = malloc(bufsize * sizeof(char *));
    if (tokens == NULL) {
        perror("allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, delimiters);

    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += TOKEN_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (tokens == NULL) {
                perror("allocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, delimiters);
    }
    tokens[position] = NULL;
    return tokens;
}

