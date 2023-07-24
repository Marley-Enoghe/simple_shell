#include "shell.h"
/**
 * get_path - this is the value of the PATH enviroment variable.
 *
 * Return: returns a pointer to the value of $PATH.
 */
char *get_path(void)
{
	return (_getenv("PATH"));
}