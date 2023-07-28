#include "shell.h"

/**
 * _puts - standard output stream print
 * @str: print string
 *
 * Return: Void
 */
void _puts(char *str)
{
size_t l;
ssize_t num;

l = _strlen(str);
num = write(STDOUT_FILENO, str, l);
if (num == -1)
{
perror("write");
}
}

/**
 * _puterror - standard error stream print error message
 * @err: print error message
 *
 * Return: Void
 */
void _puterror(char *err)
{
size_t l;
ssize_t num;

l = _strlen(err);
num = write(STDERR_FILENO, err, l);
if (num == -1)
{
perror("write");
}
}
