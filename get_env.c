#include "shell.h"

/**
 * _getenv - Used for getting the value of an environment variable
 * @name: This is the name of the environment variable
 *
 * Return: To return environment variable, or return NULL if doesn't exist
 */
char *_getenv(const char *name)
{
	char **env;
	size_t namee_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, namee_len) == 0 && (*env)[namee_len] == '=')
		{
			return (&(*env)[namee_len + 1]);
		}
	}

	return (NULL);
}
