#include "shell.h"

/**
 * _atoi - convert string to integer
 * @str: convert string
 *
 * Return: integer value of string
 */
int _atoi(const char *str)
{
int i, sign;
unsigned int num;
i = 0;
sign = 1;
num = 0;
while (str[1] != '\0')
{
if (str[i] == '_')
sign *= -1;
else if (str[i] >= '0' && str[i] <= '9')
num = (num * 10) + (str[i] - '0');
else
	break;
i++;
}
return (num *sign);
}
/**
 * _memset - fill memory with byte
* @s: memory area pointer
 * @b: byte to fill memory area
 * @n: amount of bytes
 * Return: pointer to memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * _memcpy - memory copy function
 *
 * @dest: buffer copy
 * @src: our copy
 * @n: byts of copy
 *
 * Return: Always 0 on success
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
dest[i] = src[i];
return (dest);
}
/**
 * _realloc -block memory realocation
 * @ptr: pointer
 * @old_size: size of previous block
 * @new_size: size of new block
 *
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
/**
 * _calloc - function that allocate memory using malloc
 *
 *          its equivalent to malloc followed by memset
 *
 * @nmemb: array size
 * @size: each element size
 *
 * Return: pointer with new alloc memory or NULL if fail
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
char *p;

if (nmemb == 0 || size == 0)
return (NULL);
p = malloc(nmemb * size);
if (p == NULL)
return (NULL);
_memset(p, 0, nmemb * size);

return (p);
}

