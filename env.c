#include "shell.h"

/**
 * shell_env - all environment variables to be printed
 *
 * Return: void.
 */
int shell_env(void)
{
int a ;
for (a = 0; environ[a]; a++)
{
_puts(environ[a]);
_putchar('\n');
}
return (0);
}
