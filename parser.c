#include "shell.h"

/**
 * tokenize - this is used for parsing user input into arguments
 *            by splits an array string into tokens using a delimiter.
 * @str: This is the string to be tokenized.
 * @delim: This is the delimiter used to split the string.
 *
 * Return: To return an array of pointers to the tokens,
 *         or NULL if an error occurs.
 */
char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **ret = NULL;
	int j = 0;

	token = strtok(str, delim);
	while (token)
	{
		ret = realloc(ret, sizeof(char *) * (j + 1));
		if (ret == NULL)
			return (NULL);

		ret[j] = malloc(_strlen(token) + 1);
		if (!(ret[j]))
			return (NULL);

		_strcpy(ret[j], token);
		token = strtok(NULL, delim);
		j++;
	}
	/*increase the size of the array*/
	ret = realloc(ret, (j + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	ret[j] = NULL;
	return (ret);
}

/**
 * tokenize_input - split a user input string into tokens with tokenize().
 * @input: this is the user input string to be tokenized
 *
 * Return: array of pointers to the tokens, or NULL if an error occurs
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *tmp = NULL;

	tmp = _strdup(input);
	if (tmp == NULL)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(tmp, " \t\r\n\a");
	free(tmp);

	return (tokens);
}
