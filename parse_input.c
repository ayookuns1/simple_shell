#include "simple_shell.h"
/**
 * parse_input - Fuctn splits str into arr of tokens
 * @input: Input str to be parsed
 *
 * Fuctn tokenizes input str based on a set of delimiters
 *
 * Return: An arr of pointrs to the tokens parsed from the input str
 *
 */
char **parse_input(char *input)
{
    const char *delimiters = " \t\r\n\a";
    char *token;
    int bufsize = TOKEN_BUFSIZE;
    int position = 0;
    int in_single_quote = 0; 

    char **tokens = malloc(TOKEN_BUFSIZE * sizeof(char *));
    if (tokens == NULL)
    {
        perror("allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, delimiters);

    while (token != NULL)
    {
        
        if (token[0] == '\'' && token[strlen(token) - 1] == '\'')
        {
            token[strlen(token) - 1] = '\0'; 
            token++; 
        }
        else if (token[0] == '\'')
        {
            
            in_single_quote = 1;
            token++; 
        }
        else if (token[strlen(token) - 1] == '\'')
        {
            
            token[strlen(token) - 1] = '\0'; 
            in_single_quote = 0;
        }

        
        if (!in_single_quote)
        {
            tokens[position] = token;
            position++;

            if (position >= bufsize)
            {
                bufsize += TOKEN_BUFSIZE;
                tokens = realloc(tokens, bufsize *sizeof(char *));
                if (tokens == NULL)
                {
                    perror("allocation error");
                    exit(EXIT_FAILURE);
                }
            }
        }

        token = strtok(NULL, delimiters);
    }

    tokens[position] = NULL;
    return tokens;
}


