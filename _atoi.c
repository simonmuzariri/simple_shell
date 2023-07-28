#include "shell.h"

/**
 * interactive - true if shell is interactive
 * @info: address
 *
 * Return: 1 if nteractive , 0 otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check if its delimeter
 * @c: character to check
 * @delim: string delimeter
 * Return: 1 if true or 0 if false
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 * _isalpha - alphabetic character check
 * @c: input character
 * Return: 1 if alphabetic or 0 otherwise
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
/**
 * _atoi - convertion of string to integer
 * @s:  string to be converted
 * Return: convert number or return 0 if no number string
 */
int _atoi(char *s)
{
int a, sign = 1, flag = 0, output;
unsigned int result = 0;

for (a = 0; s[a] != '\0' && flag != 2; a++)
{
if (s[a] == '-')
sign *= -1;
if (s[a] >= '0' && s[a] <= '9')
{
flag = 1;
result *= 10;
result += (s[a] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}
