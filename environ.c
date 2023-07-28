#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing arguments
 * @name: environ name
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *a;
while (node)
{
a = starts_with(node->str, name);
if (a && *a)
return (a);
node = node->next;
}
return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 * @info: Structure containing arguments
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}
/**
 * _myunsetenv - Remove an environment variable
 *  @info: Structure containing arguments
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
int a;
if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (a = 1; a <= info->argc; a++)
_unsetenv(info, info->argv[a]);
return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing arguments
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
list_t *n = NULL;
size_t a;

for (a = 0; environ[a]; a++)
add_node_end(&n, environ[a], 0);
info->env = n;
return (0);
}
