#include "shell.h"

/**
 * shell_exit - for exiting the shell.
 * @args: Arguments.
 *
 * Return: to return nothing.
 */
void shell_exit(char **args)
{
	int status_ = 0;

	if (args[1] != NULL)
	{
		status_ = _atoi(args[1]);
	}
	free_tokens(args);
	free_last_input();
	exit(status_);
}
