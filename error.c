#include "shell.h"

/**
 * _puts - To print a string to the standard output stream
 * @str: This is the string to print
 *
 * Return: To return void
 */
void _puts(char *str)
{
	size_t leng;
	ssize_t num_writen;

	leng = _strlen(str);
	num_writen = write(STDOUT_FILENO, str, leng);
	if (num_writen == -1)
	{
		perror("write");
	}
}

/**
 * _puterror - used for printing an error message to the standard error stream
 * @err: This the error message to be printed
 *
 * Return: Return void
 */
void _puterror(char *err)
{
	size_t leng;
	ssize_t num_writen;

	leng = _strlen(err);
	num_writen = write(STDERR_FILENO, err, leng);
	if (num_writen == -1)
	{
		perror("write");
	}
}
