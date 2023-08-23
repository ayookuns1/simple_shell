#include "simple_shell.h"

extern char **environ;

void print_environment(void) {
    int i;
    for (i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}

