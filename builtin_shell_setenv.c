#include "shell.h"
/**
 * shell_setenv - this sets the value of an environment variable
 * @args: An arguments, the name and the value of the environment variable
 *
 * Return: Nothing to be returned
 */
int shell_setenv(char **args)
{
	char *namee, *valuee;

	if (args[1] == NULL || args[2] == NULL)
	{
		_puterror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	namee = args[1];
	valuee = args[2];

	if (setenv(namee, valuee, 1) != 0)
	{
		_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * shell_unsetenv - Used to unset an environment variable
 * @args: The Arguments (that is the name of the environment variable)
 *
 * Return: Nothing to be returned
 */
int shell_unsetenv(char **args)
{
	char *namee;

	if (args[1] == NULL)
	{
		_puterror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	namee = args[1];

	if (unsetenv(namee) != 0)
	{
		_puterror("unsetenv");
	}
	return (0);
}