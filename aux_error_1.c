#include "main.h"

/**
 * strcat_cd -This is a function that concatenates the message for cd error
 *
 * @datash: the relevant data (directory)
 * @msg: The message to printed
 * @error: An output message
 * @ver_str: The counter lines
 * Return: The error message
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *ilegal_flags;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		ilegal_flags = malloc(3);
		ilegal_flags[0] = '-';
		ilegal_flags[1] = datash->args[1][1];
		ilegal_flags[2] = '\0';
		_strcat(error, ilegal_flags);
		free(ilegal_flags);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - An error message for cd command in get_cd
 * @datash: The data relevant (directory)
 * Return: The error message
 */
char *error_get_cd(data_shell *datash)
{
	int lengths, len_ids;
	char *errors, *ver_strr, *msgs;

	ver_strr = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msgs = ": Illegal option ";
		len_ids = 2;
	}
	else
	{
		msgs = ": can't cd to ";
		len_ids = _strlen(datash->args[1]);
	}

	lengths = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	lengths += _strlen(ver_strr) + _strlen(msgs) + len_ids + 5;
	errors = malloc(sizeof(char) * (lengths + 1));

	if (errors == 0)
	{
		free(ver_strr);
		return (NULL);
	}

	errors = strcat_cd(datash, msgs, errors, ver_strr);

	free(ver_strr);

	return (errors);
}

/**
 * error_not_found - This is a generic error message for command not found
 * @datash:The  data relevant (counter, arguments)
 * Return: An error message
 */
char *error_not_found(data_shell *datash)
{
	int lengths;
	char *errors;
	char *ver_strr;

	ver_strr = aux_itoa(datash->counter);
	lengths = _strlen(datash->av[0]) + _strlen(ver_strr);
	lengths += _strlen(datash->args[0]) + 16;
	errors = malloc(sizeof(char) * (lengths + 1));
	if (errors == 0)
	{
		free(errors);
		free(ver_strr);
		return (NULL);
	}
	_strcpy(errors, datash->av[0]);
	_strcat(errors, ": ");
	_strcat(errors, ver_str);
	_strcat(errors, ": ");
	_strcat(errors, datash->args[0]);
	_strcat(errors, ": not found\n");
	_strcat(errors, "\0");
	free(ver_strr);
	return (errors);
}

/**
 * error_exit_shell - The generic error message for exit in get_exit
 * @datash:This is the  data relevant (counter, arguments)
 *
 * Return:An error message
 */
char *error_exit_shell(data_shell *datash)
{
	int lengths;
	char *errors;
	char *ver_strr;

	ver_strr = aux_itoa(datash->counter);
	lengths = _strlen(datash->av[0]) + _strlen(ver_strr);
	lengths += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	errors = malloc(sizeof(char) * (lengths + 1));
	if (errors == 0)
	{
		free(ver_strr);
		return (NULL);
	}
	_strcpy(errors, datash->av[0]);
	_strcat(errors, ": ");
	_strcat(errors, ver_str);
	_strcat(errors, ": ");
	_strcat(errors, datash->args[0]);
	_strcat(errors, ": Illegal number: ");
	_strcat(errors, datash->args[1]);
	_strcat(errors, "\n\0");
	free(ver_strr);

	return (errors);
}
