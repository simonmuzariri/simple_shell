#include "shell.h"

/**
 * _myhistory - displays the history lists
 * @i: Structure containing arguments
 *  Return: Always 0
 */
int _myhistory(info_t *i)
{
print_list(i->history);
return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @s: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *s)
{
char *a, c;
int r;

a = _strchr(s, '=');
if (!a)
return (1);
c = *a;
*a = 0;
r = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, s, -1)));
*a = c;
return (r);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @s: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *s)
{
char *a;
a = _strchr(s, '=');
if (!a)
return (1);
if (!*++a)
return (unset_alias(info, s));
unset_alias(info, s);
return (add_node_end(&(info->alias), s, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
char *k = NULL, *i = NULL;
if (node)
{
k = _strchr(node->str, '=');
for (i = node->str; i <= k; i++)
_putchar(*i);
_putchar('\'');
_puts(k + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing arguments
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
int a = 0;
char *k = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (a = 1; info->argv[a]; a++)
{
k = _strchr(info->argv[a], '=');
if (k)
set_alias(info, info->argv[a]);
else
print_alias(node_starts_with(info->alias, info->argv[a], '='));
}
return (0);
}
