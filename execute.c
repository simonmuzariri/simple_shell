#include "shell.h"

/**
 * execute - execute a command
 * @argv : array with commands and arguments
 *
 * Return: Exit status
 */
int execute(char **argv)
{
pid_t id;
int s = 0;
char *path, *envp[2];

if (argv == NULL || *argv == NULL)
return (s);
if (check_for_builtin(argv))
return (s);

id = fork();
if (id < 0)
{
_puterror("fork");
return (1);
}
if (id == -1)
perror(argv[0]), free_tokens(argv), free_last_input();
if (id == 0)
{
envp[0] = get_path();
envp[1] = NULL;
path = NULL;
if (argv[0][0] != '/')
path = find_in_path(argv[0]);
if (path == NULL)
path = argv[0];
if (execve(path, argv, envp) == -1)
{
perror(argv[0]), free_tokens(argv), free_last_input();
exit(EXIT_FAILURE);
}
}
else
{
do {
waitpid(id, &s, WUNTRACED);
} while (!WIFEXITED(s) && !WIFSIGNALED(s));
}
return (s);
}
