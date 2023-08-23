#include "simple_shell.h"
#define BUFFER_SIZE 1024
/**
 * read_input - This fuctn reads input frm standrd input and return a line
 *
 * It reads input frm the standrd input char by char
 * Return: Dynamically allocated str containing the input line,
 * or Null
 */

char *read_input(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1) {
        free(line);
        return NULL;
    }

    
    if (line[read - 1] == '\n') {
        line[read - 1] = '\0';
    }

    return line;
}
