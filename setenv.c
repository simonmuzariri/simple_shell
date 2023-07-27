#include "shell.h"

/**
 * shell_setenv - set envrionment value
 * @args: arguments array
 *
 * Return: Nothing
 */
int shell_setenv(char **args)
{
char *n, *v;
if (args[1] == NULL || args[2] == NULL)
{
_puterror("Usage: setenv VARIABLE VALUE\n");
return (-1);
}
n = args[1];
v = args[2];

if (setenv(n, v, 1) != 0)
{
_puterror("setenv");
return (-1);
}
return (0);
}

/**
 * shell_unsetenv - environment variable set
 * @args: array of arguments
 *
 * Return: Nothing
 */
int shell_unsetenv(char **args)
{
char *n;

if (args[1] == NULL)
{
_puterror("Usage: unsetenv VARIABLE\n");
return (-1);
}
n = args[1];
if (unsetenv(n) != 0)
{
_puterror("unsetenv");
}
return (0);
}

