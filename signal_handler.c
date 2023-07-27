#include "shell.h"
/**
 * handle_sigint -This is the Signal handler for SIGINT
 * @sig: The Signal number
 *
 * Return: returns nothing
 */
void handle_sigint(int sig)
{
	(void) sig;
	_putchar('\n');
	prompt();
}

/**
 * handle_sigquit -This is the signal handler for SIGQUIT
 * @sig: The Signal number
 *
 * Return: Returns nothing
 */
void handle_sigquit(int sig)
{
	(void) sig;
	_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp -This is a Signal handler for SIGTSTP
 * @sig: The Signal number
 *
 * Return: Returns nothing
 */
void handle_sigstp(int sig)
{
	(void) sig;
	_puts("\n");
	prompt();
}
