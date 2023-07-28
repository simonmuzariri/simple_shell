#include "shell.h"

/**
 * shell_clear - clear the screen of the terminal
 * @args: argument of array
 *
 * Return: 1 executing or 0 to exit
 */
int shell_clear(char **args)
{
(void)args;
_puts("\033[2J\033[H");
return (1);
}
