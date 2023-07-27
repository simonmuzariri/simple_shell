#include "shell.h"

/**
 * check_for_builtin - check if command is builtin
 * @args: an array argument
 *
 * Return: 1 if buitin or 0 on no results
 */

int check_for_builtin(char **args)
{
if (!args[0])
return (0);
if (!_strcmp(args[0], "exit"))
shell_exit(args);
else if (!_strcmp(args[0], "env"))
shell_env();
else if (!_strcmp(args[0], "setenv"))
shell_setenv(args);
else if (!_strcmp(args[0], "help"))
shell_help();
else if (!_strcmp(args[0], "cd"))
shell_cd(args);
else if (!_strcmp(args[0], "clear"))
shell_clear(args);
else
return (0);
return (1);
}
