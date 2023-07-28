#include "shell.h"

/**
 * handle_sigint - signal handler for sigint
 * @sig: signal number
 *
 * Return: Nothing
 */
void handle_sigint(int sig)
{
(void) sig;
_putchar('\n');
prompt();
}

/**
 * handle_sigquit - signal handler for sigquit
 * @sig: signal number
 *
 * Return: Nothing
 */
void handle_sigquit(int sig)
{
(void) sig;
_puterror("Quit (core dumped) \n");
exit(EXIT_SUCCESS);
}
/**
 * handle_sigstp - signal handler for sigstp
 * @sig: signal number
 *
 * Return: Nothing
 */
void handle_sigstp(int sig)
{
(void) sig;
_puts("/n");
prompt();
}
