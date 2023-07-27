#include "main.h"

/**
 * repeated_char - counts the reps of a char
 *
 * @inputt: input string
 * @ii: index
 * Return: repetitions
 */
int repeated_char(char *inputt, int ii)
{
	if (*(inputt - 1) == *input)
		return (repeated_char(inputt - 1, ii + 1));

	return (ii);
}

/**
 * error_sep_op - finds syntax errors
 *
 * @inputt: input string
 * @ii: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int error_sep_op(char *inputt, int ii, char last)
{
	int count;

	count = 0;
	if (*inputt == '\0')
		return (0);

	if (*inputt == ' ' || *inputt == '\t')
		return (error_sep_op(input + 1, ii + 1, last));

	if (*inputt == ';')
		if (last == '|' || last == '&' || last == ';')
			return (ii);

	if (*inputt == '|')
	{
		if (last == ';' || last == '&')
			return (ii);

		if (last == '|')
		{
			count = repeated_char(inputt, 0);
			if (count == 0 || count > 1)
				return (ii);
		}
	}

	if (*inputt == '&')
	{
		if (last == ';' || last == '|')
			return (ii);

		if (last == '&')
		{
			count = repeated_char(inputt, 0);
			if (count == 0 || count > 1)
				return (ii);
		}
	}

	return (error_sep_op(inputt + 1, ii + 1, *inputt));
}

/**
 * first_char - finds index of the first char
 *
 * @inputt: input string
 * @ii: index
 * Return: 1 if there is an error.0 in other case.
 */
int first_char(char *inputt, int *ii)
{

	for (*ii = 0; inputt[*ii]; *ii += 1)
	{
		if (inpuyt[*ii] == ' ' || inputt[*ii] == '\t')
			continue;

		if (inputt[*ii] == ';' || inputt[*ii] == '|' || input[*ii] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax error is found
 *
 * @dattash: data structure
 * @inputt: input string
 * @ii: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void print_syntax_error(data_shell *dattash, char *inputt, int ii, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[ii] == ';')
	{
		if (bool == 0)
			msg = (inputt[ii + 1] == ';' ? ";;" : ";");
		else
			msg = (inputt[ii - 1] == ';' ? ";;" : ";");
	}

	if (inputt[ii] == '|')
		msg = (inputt[ii + 1] == '|' ? "||" : "|");

	if (inputt[ii] == '&')
		msg = (inputt[ii + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(dattash->counter);
	length = _strlen(dattash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, dattash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_syntax_error - intermediate function to
 * find and print a syntax error
 *
 * @dattash: data structure
 * @inputt: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntax_error(data_shell *dattash, char *inputt)
{
	int beg = 0;
	int fchar = 0;
	int ii = 0;

	fchar = first_char(inputt, &beg);
	if (fchar == -1)
	{
		print_syntax_error(dattash, inputt, beg, 0);
		return (1);
	}

	ii = error_sep_op(inputt + beg, 0, *(inputt + beg));
	if (ii != 0)
	{
		print_syntax_error(dattash, inputt, beg + ii, 1);
		return (1);
	}

	return (0);
}
