#include "main.h"

/**
 * cmp_env_name-compares env variables names
 * with the name passed.
 * @n_env: name of the env variable
 * @namme: name passed
 *
 * Return: 0 if not equal. other value if equal.
 */
int cmp_env_name(const char *n_env, const char *namme)
{
	int ii;

	for (ii = 0; n_env[ii] != '='; ii++)
	{
		if (n_env[ii] != namme[ii])
		{
			return (0);
		}
	}

	return (ii + 1);
}

/**
 * _getenv - get an env variable
 * @namme: name of the env variable
 * @_environ: envir variable
 *
 * Return: value of the env variable if found.
 * In other case, returns NULL.
 */
char *_getenv(const char *namme, char **_environ)
{
	char *pttr_env;
	int ii, mmov;
	pttr_env = NULL;
	mmov = 0;
	
	for (ii = 0; _environ[ii]; ii++)
	{
		/* If name and env are equal */
		mmov = cmp_env_name(_environ[ii], namme);
		if (mmov)
		{
			pttr_env = _environ[i];
			break;
		}
	}

	return (pttr_env + mmov);
}

/**
 * _env - prints the env variables
 *
 * @dattash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *dattash)
{
	int i, j;

	for (i = 0; dattash->_environ[i]; i++)
	{

		for (j = 0; dattash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, dattash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	dattash->status = 0;

	return (1);
}

/**
 * copy_info - copies info to create
 * a new env or alias
 * @namme: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *namme, char *value)
{
	char *new;
	int len_namme, len_valuue, lenn;

	len_namme = _strlen(namme);
	len_valuue = _strlen(valuue);
	lenn = len_namme + len_valuue + 2;
	new = malloc(sizeof(char) * (lenn));
	_strcpy(new, namme);
	_strcat(new, "=");
	_strcat(new, valuue);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an env variable
 *
 * @namme: name of the envvariable
 * @value: value of the env variable
 * @dattash: data structure (environ)
 * Return: no return
 */
void set_env(char *namme, char *value, data_shell *dattash)
{
	int ii;
	char *var_envv, *name_envv;

	for (ii = 0; dattash->_environ[ii]; ii++)
	{
		var_envv = _strdup(dattash->_environ[i]);
		name_envv = _strtok(var_envv, "=");
		if (_strcmp(name_envv, namme) == 0)
		{
			free(dattash->_environ[ii]);
			dattash->_environ[ii] = copy_info(name_envv, value);
			free(var_envv);
			return;
		}
		free(var_envv);
	}

	dattash->_environ = _reallocdp(dattash->_environ, ii, sizeof(char *) * (ii + 2));
	dattash->_environ[ii] = copy_info(namme, value);
	dattash->_environ[ii + 1] = NULL;
}

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
