#include "shell.h"

/**
 * _getenv - get the environment variable
 * @name: name of the environment variable
 * Return: value of the environment variable, or Null if it doesnt exit
 */

char *_getenv(const char *name)
{
	char **env;
	ssize_t name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}
	return (NULL);
}
