#include "simple_shell.h"

int main(void) {
    int interactive = isatty(STDIN_FILENO);

    if (!interactive) {
        handle_non_interactive();
        return (EXIT_SUCCESS);
    }

    handle_interactive();

    return (EXIT_SUCCESS);
}

