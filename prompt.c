#include "shell.h"

/**
 * prompt - print shell prompt
 *
 * Return: void
 */
void prompt(void)
{
_puts(PROMPT);
fflush(stdout);
}
