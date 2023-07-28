#include "shell.h"

/**
 * get_path - return value of the path environment variable.
 * Return: pointer to the value of $path
 */
char *get_path(void)
{
	return (_getenv("PATH"));
}
