#include "shell.h"

/**
 * _erratoi - convert a string to integer
 * @st: the string to be converted
 * Return: 0 if no string or -1 on error
 */
int _erratoi(char *st)
{
int a = 0;
unsigned long int total = 0;

if (*st == '+')
st++;  /* TODO: why does this make main return 255? */
for (a = 0;  st[a] != '\0'; a++)
{
if (st[a] >= '0' && st[a] <= '9')
{
total *= 10;
total += (s[i] - '0');
if (total > INT_MAX)
return (-1);
}
else
return (-1);
}
return (total);
}

/**
 * print_error - prints an error message
 * @i: info struct
 * @e: string containing specified error type
 * Return: 0 if no numbers or -1 on error
 */
void print_error(info_t *i, char *e)
{
_eputs(i->fname);
_eputs(": ");
print_d(i->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(i->argv[0]);
_eputs(": ");
_eputs(e);
}
/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: file descriptor
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int a, c = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
c++;
}
else
_abs_ = input;
current = _abs_;
for (a = 1000000000; a > 1; a /= 10)
{
if (_abs_ / a)
{
__putchar('0' + current / a);
c++;
}
current %= a;
}
__putchar('0' + current);
c++;
return (c);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do	{
*--ptr = array[n % base];
n /= base;
} while (n != 0);
if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
