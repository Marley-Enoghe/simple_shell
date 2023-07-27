#include "shell.h"

/**
 * free_error - used for freeing alloc'd pointers following the system error
 * @argv:This is a pointer to a pointer to an array of pointers
 * @arg: This is a pointer to a pointer to an array of characters
 *
 * Return: void to be returned.
 */
void free_error(char **argv, char *arg)
{
	int j;

	for (j = 0; argv[j]; j++)
		free(argv[j]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * free_tokens -to free the memory allocated dynamically by tokenize()
 * @ptr: This is a pointer to allocated memory
 *
 * Return: void to be returned.
 */
void free_tokens(char **ptr)
{
	int j;

	for (j = 0; ptr[j]; j++)
		free((ptr[j]));
	free(ptr);
}


/**
 * free_path -freeing the global variable containing the PATH environment
 *             variable value
 *
 * Return: Nothing to be reduced
 */
void free_path(void)
{
	if (environ != NULL)
	{
		size_t j = 0;

		while (environ[j] != NULL)
		{
			if (_strncmp(environ[j], "PATH=", 5) == 0)
			{
				free(environ[j]);
				environ[j] = NULL;
				break;
			}
			j++;
		}
	}
}
