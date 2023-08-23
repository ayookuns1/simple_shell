#include "simple_shell.h"

/**
 * print_environment - Fuctn prints all envirmnt variabls and their valus.
 *
 * Fuctn iterates through the envirmnt variabls, prints the variable
 */

void print_environment(void) {
    char **env = __environ;
    while (*env) {
        if (*env) {
            printf("%s\n", *env);
        }
        env++;
    }
}

