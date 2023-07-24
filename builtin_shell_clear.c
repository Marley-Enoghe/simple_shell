#include "shell.h"

/**
 * shell_clear - for clearing the terminal screen.
 * @args: this is an array of arguments
 *
 * Return: return 1 to continue executing,
 *         or return 0 to exit.
*/
int shell_clear(char **args)
{
	(void)args; /* avoid "unsued parameter" warning */
	_puts("\033[2J\033[H");
	return (1);
}