#include "simple_shell.h"
/**
 * free_args - This fuctn frees memory allocated for an arr of strs
 * @args: Arr of strs to be freed
 *
 * Fuctn iterates through arr of strs pointd to by 'args'
 *
 */

void free_args(char **args)
{
int index;
for (index = 0; args[index] != NULL; index++)
{
free(args[index]);
}
free(args);
}
