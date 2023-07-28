#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @i: Structure containing arguments.
 * Return: Always 0
 */
char **get_environ(info_t *i)
{
if (!i->environ || i->env_changed)
{
i->environ = list_to_strings(i->env);
i->env_changed = 0;
}
return (i->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @i: Structure containing arguments
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *i, char *var)
{
list_t *node = i->env;
size_t a = 0;
char *p;
if (!node || !var)
return (0);
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
i->env_changed = delete_node_at_index(&(i->env), a);
a = 0;
node = i->env;
continue;
}
node = node->next;
a++;
}
return (i->env_changed);
}

/**
 * _setenv - Initialize a new environment
 * @i: Structure containing  arguments
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *i, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *a;
if (!var || !value)
return (0);
buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = i->env;
while (node)
{
a = starts_with(node->str, var);
if (a && *a == '=')
{
free(node->str);
node->str = buf;
i->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(i->env), buf, 0);
free(buf);
i->env_changed = 1;
return (0);
}
