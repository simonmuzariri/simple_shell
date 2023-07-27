#include "shell.h"

/**
 * tokenize - parsing user input into arguments
 * @str: string to be tokenizesd
 * @delim: the delimister used to split the string
 * Return: an arrray of pointer to tokenselse now
 */
char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **ret = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		ret = realloc(ret, sizeof(char *) * (i + 1));
		if (ret == NULL)
			return (NULL);
		ret[i] = malloc(_strlen(token) + 1);
		if (!(ret[i]))
			return (NULL);

		_strcpy(ret[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	/*increase the size od array*/
	ret = realloc(ret, (i + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	ret[i] = NULL;
	return (ret);
}
/**
 * tokenize_input - splits a user input string into toknens with tokenize().
 * @input:user input
 * Return: an array of pointers to the tokens, or NULL if an error occurs
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *tmp = NULL;

	tmp = _strdup(input);
	if (tmp == NULL)
	{
		_puts("Memor allocation error\n");
		exit(EXIT_FAILURE);
	}
	tokens = tokenize(tmp, " \t\r\n\a");
	free(tmp);

	return (tokens);
}
