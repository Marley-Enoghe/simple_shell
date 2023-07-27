#include "main.h"

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @dattash: data (env name, env value)
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *dattash)
{

	if (dattash->argss[1] == NULL || dattash->argss[2] == NULL)
	{
		get_error(dattash, -1);
		return (1);
	}

	set_env(dattash->argss[1], dattash->argss[2], dattash);

	return (1);
}

/**
 * _unsetenv -deletes a environment variable
 *
 * @dattash: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *dattash)
{
	char **realloc_environ;
	char *var_envv, *name_envv;
	int ii, j, k;

	if (dattash->argss[1] == NULL)
	{
		get_error(dattash, -1);
		return (1);
	}
	k = -1;
	for (ii = 0; dattash->_environ[ii]; ii++)
	{
		var_envv = _strdup(dattash->_environ[ii]);
		name_envv = _strtok(var_envv, "=");
		if (_strcmp(name_envv, dattash->argss[1]) == 0)
		{
			k = ii;
		}
		free(var_envv);
	}
	if (k == -1)
	{
		get_error(dattash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (ii));
	for (ii = j = 0; datash->_environ[ii]; ii++)
	{
		if (ii != k)
		{
			realloc_environ[j] = dattash->_environ[ii];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(dattash->_environ[k]);
	free(dattash->_environ);
	dattash->_environ = realloc_environ;
	return (1);
}
