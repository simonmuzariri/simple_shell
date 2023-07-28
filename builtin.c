#include "shell.h"

/**
 * _myexit - shell exit
 * @info : function prototype
 * Return: exits
 */
int _myexit(info_t *info)
{
int exit;
if (info->argv[1]) /*if there is an exit argument */
{
exit = _erratoi(info->argv[1]);
if (exit == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}
/**
 * _mycd - change current directory
 * @info: structure for arguments
 * Return: Always 0
 */
int _mycd(info_t *info)
{
char *a, *dir, buffer[1024];
int chdir_ret;

a = getcwd(buffer, 1024);
if (!a)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chidir_ret = /* TODO: what should this be? */
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(a);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* TODO: what should this be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1], _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}
/**
 * _myhelp - change current directory
 * @info: structure containing arguments
 * Return: 0
 */
int _myhelp(info_t *info)
{
char **arg_a;

arg_a = info->argv;
_puts("help call works. Function not yet implemented\n")
if (0)
_puts(*arg_a); /* temp att_unused workaround */
return (0);
}
