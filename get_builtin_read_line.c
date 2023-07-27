#include "main.h"

/**
 * get_builtin - builtin the command in the arg
 * @cmd: command
 * Return: func pointer of the builtin command
 */
int (*get_builtin(char *cmdd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int ii;

	for (ii = 0; builtin[ii].name; ii++)
	{
		if (_strcmp(builtin[ii].name, cmdd) == 0)
			break;
	}

	return (builtin[ii].f);
}

/**
 * read_line - reads the input string.
 *
 * @i_eof: return value of getline func
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
