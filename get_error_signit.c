#include "main.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @dattash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *dattash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(dattash);
		break;
	case 126:
		error = error_path_126(dattash);
		break;
	case 127:
		error = error_not_found(dattash);
		break;
	case 2:
		if (_strcmp("exit", dattash->args[0]) == 0)
			error = error_exit_shell(dattash);
		else if (_strcmp("cd", dattash->args[0]) == 0)
			error = error_get_cd(dattash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	dattash->status = eval;
	return (eval);
}

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
