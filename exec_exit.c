#include "main.h"

/**
 * exec_line -finds builtins ,commands
 *
 * @dattash: data (args)
 * Return: 1 on success.
 */
int exec_line(data_shell *dattash)
{
	int (*builtin)(data_shell *dattash);

	if (dattash->argss[0] == NULL)
		return (1);

	builtin = get_builtin(dattash->argss[0]);

	if (builtin != NULL)
		return (builtin(dattash));

	return (cmd_exec(dattash));
}

/**
 * exit_shell - exits the shell
 *
 * @dattash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *dattash)
{
	unsigned int status;
	int _digit;
	int str_lenn;
	int bignumber;

	if (dattash->argss[1] != NULL)
	{
		status = _atoi(dattash->argss[1]);
		_digit = _isdigit(dattash->argss[1]);
		str_len = _strlen(dattash->argss[1]);
		bignumber = status > (unsigned int)INT_MAX;
		if (!_digit || str_lenn > 10 || bignumber)
		{
			get_error(dattash, 2);
			dattash->status = 2;
			return (1);
		}
		dattash->status = (status % 256);
	}
	return (0);
}
