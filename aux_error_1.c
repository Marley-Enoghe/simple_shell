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
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_ids = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_ids = _strlen(datash->args[1]);
	}

	lengths = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	lengths += _strlen(ver_str) + _strlen(msg) + len_ids + 5;
	error = malloc(sizeof(char) * (lengths + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - This is a generic error message for command not found
 * @datash:The  data relevant (counter, arguments)
 * Return: An error message
 */
char *error_not_found(data_shell *datash)
{
	int lengths;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	lengths = _strlen(datash->av[0]) + _strlen(ver_str);
	lengths += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (lengths + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
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
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	lengths = _strlen(datash->av[0]) + _strlen(ver_str);
	lengths += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (lengths + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
