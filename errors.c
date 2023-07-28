#include "shell.h"

/**
 *_eputs - prints an input string
 * @s: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *s)
{
int a = 0;
if (!s)
return;
while (s[a] != '\0')
{
_eputchar(s[a]);
a++;
}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1 or On error -1
 */
int _eputchar(char c)
{
static int a;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(2, buf, a);
a = 0;
}
if (c != BUF_FLUSH)
buf[a++] = c;
return (1);
}

/**
 * put_fd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor
 *
 * Return: 1 on success or On error, -1 is returned
 */
int put_fd(char c, int fd)
{
static int a;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(fd, buf, a);
a = 0;
}
if (c != BUF_FLUSH)
buf[a++] = c;
return (1);
}

/**
 *_putsfd - prints an input string
 * @s: the string to be printed
 * @fd: the file descriptor
 *
 * Return: the number of chars
 */
int _putsfd(char *s, int fd)
{
int a = 0;

if (!s)
return (0);
while (*s)
{
a += put_fd(*s++, fd);
}
return (a);
}
