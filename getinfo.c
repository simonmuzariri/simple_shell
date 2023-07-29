#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @i: struct address
 */
void clear_info(info_t *i)
{
i->arg = NULL;
i->argv = NULL;
i->path = NULL;
i->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @i: struct address
 * @av: argument vector
 */
void set_info(info_t *i, char **av)
{
int a = 0;

i->fname = av[0];
if (i->arg)
{
i->argv = strtow(i->arg, " \t");
if (!i->argv)
{
i->argv = malloc(sizeof(char *) * 2);
if (i->argv)
{
i->argv[0] = _strdup(i->arg);
i->argv[1] = NULL;
}
}
for (a = 0; i->argv && i->argv[a]; a++)
;
i->argc = a;
replace_alias(i);
replace_vars(i);
}
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @a: true if freeing all fields
 */
void free_info(info_t *info, int a)
{
ffree(info->argv);
info->argv = NULL;
info->path = NULL;
if (a)
{
if (!info->cmd_buf)
free(info->arg);
if (info->env)
free_list(&(info->env));
if (info->history)
free_list(&(info->history));
if (info->alias)
free_list(&(info->alias));
ffree(info->environ);
info->environ = NULL;
b_free((void **)info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
_putchar(BUF_FLUSH);
}
}
