#include "shell.h"

static char *last_input;
/**
 * get_input - for reading the line of input from user end.
 *
 * Return: To return a pointer to a buffer containing the user's input.
*/
char *get_input(void)
{
	char *input = NULL;
	size_t input_sizee = 0;
	ssize_t nread;

	do {
		/* print the shell prompt */
		prompt();

		/* get line of input from user*/
		nread = getline(&input, &input_sizee, stdin);

		/* checking for EOF or error */
		if (nread == -1)
		{
			free(input);
			_puts("\n");
			return (NULL);
		}

		/* remove newline character */
		input[nread - 1] = '\0';

	} while (input[0] == '\0' || isspace(input[0]));

	/* update last_input to point to new input */
	last_input = input;
	return (input);
}

/**
 * free_last_input - For freeing the most recent input entered by the user.
 *
 * for freeing the memory allocated for the most recent input string
 * which should be called after the input string is no longer
 * needed.
 */
void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}
