#include "shell.h"

/**
 * shell_env - for Printing all the environment variables.
 *
 * Return: return void.
 */
int shell_env(void)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		_puts(environ[j]);
		_putchar('\n');
	}

	return (0);
}
