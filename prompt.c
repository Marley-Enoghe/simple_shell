#include "shell.h"
/**
 * prompt - Used for printing shell prompt to stdin stream.
 *
 * Return: void to be returned.
 */
void prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);
}
