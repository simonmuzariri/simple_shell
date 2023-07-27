#include "shell.h"

static char *last_input;

/**
 * get_input - read the line of input from user
 * Return: pointer to containing the users input
 */
char *get_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t nread;

	do {
		/*print shell pronth*/
		prompt();

		/*get a line of input from user*/
		nread = getline(&input, &input_size, stdin);

		/*check for EOF or error */
		if (nread == -1)
		{
			free(input);
			_puts("\n");
			return (NULL);
		}

		/*remove trailing newline character*/
		input[nread - 1] = '\0';

	} while (input[0] == '\0' || isspace(input[0]));

	/*update last_input to point to the new input*/
	last_input = input;
	return (input);
}
/**
 * free_last_input - frees the recent input entered by user.
 */
void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}
