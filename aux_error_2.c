#include "main.h"

/**
 * error_env - The error message for env in get_env.
 * @datash: The data relevant (counter, arguments)
 * Return: The error message.
 */
char *error_env(data_shell *datash)
{
	int lengths;
	char *errors;
	char *ver_strr;
	char *msgs;

	ver_strr = aux_itoa(datash->counter);
	msgs = ": Unable to add/remove from environment\n";
	lengths = _strlen(datash->av[0]) + _strlen(ver_strr);
	lengths += _strlen(datash->args[0]) + _strlen(msgs) + 4;
	errors = malloc(sizeof(char) * (lengths + 1));
	if (errors == 0)
	{
		free(errors);
		free(ver_strr);
		return (NULL);
	}

	_strcpy(errors, datash->av[0]);
	_strcat(errors, ": ");
	_strcat(errors, ver_strr);
	_strcat(errors, ": ");
	_strcat(errors, datash->args[0]);
	_strcat(errors, msgs);
	_strcat(errors, "\0");
	free(ver_strr);

	return (errors);
}
/**
 * error_path_126 - The error message for path and failure denied permission.
 * @datash: The data relevant (counter, arguments).
 *
 * Return: An error string.
 */
char *error_path_126(data_shell *datash)
{
	int lengths;
	char *ver_strr;
	char *errors;

	ver_strr = aux_itoa(datash->counter);
	lengths = _strlen(datash->av[0]) + _strlen(ver_strr);
	lengths += _strlen(datash->args[0]) + 24;
	errors = malloc(sizeof(char) * (lengths + 1));
	if (errors == 0)
	{
		free(errors);
		free(ver_strr);
		return (NULL);
	}
	_strcpy(errors, datash->av[0]);
	_strcat(errors, ": ");
	_strcat(errors, ver_strr);
	_strcat(errors, ": ");
	_strcat(errors, datash->args[0]);
	_strcat(errors, ": Permission denied\n");
	_strcat(errors, "\0");
	free(ver_strr);
	return (errors);
}
