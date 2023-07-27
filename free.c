#include "shell.h"

/**
 * free_error - free allocated system error pointer
 * @argv: array of pointer
 * @arg: array of character
 *
 * Return: Void
 */
void free_error(char **argv, char *arg)
{
int a;

for (a = 0; argv[a]; a++)
free(argv[a]);
free(argv);
free(arg);
exit(EXIT_FAILURE);
}
/**
 * free_tokens - free memory allocated by token
 * @ptr: memory allocater
 *
 * Return: void
 */
void free_tokens(char **ptr)
{
int a;
for (a = 0; ptr[a]; a++)
free((ptr[a]));
free(ptr);
}

/**
 * free_path - free variable containing path
 *
 * Return: Nothin
 */
void free_path(void)
{
if (environ != NULL)
{
size_t a = 0;
while (environ[a] != NULL)
{
if (_strncmp(environ[a], "PATH=", 5) == 0)
{
free(environ[a]);
environ[a] = NULL;
break;
}
a++;
}
}
}
