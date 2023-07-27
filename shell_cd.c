#include "shell.h"

/**
 * shell_cd - working directory change to shell
 * @args: arguments array
 */
void shell_cd(char **args)
{
char *dir = args[1];
int ret;

if (dir == NULL)
{
dir = _getenv("HOME");
if (dir == NULL)
{
_puts("cd: No HOME directory found\n");
return;
}
}
ret = chdir(dir);
if (ret == -1)
{
perror("cd");
}
}
