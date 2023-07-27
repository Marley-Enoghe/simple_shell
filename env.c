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
			pttr_env = _environ[ii];
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
 * @valuue: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *namme, char *valuue)
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
 * @daash: data structure (environ)
 * Return: no return
 */
void set_env(char *namme, char *value, data_shell *daash)
{
	int ii;
	char *var_envv, *name_envv;

	for (ii = 0; daash->_environ[ii]; ii++)
	{
		var_envv = _strdup(daash->_environ[ii]);
		name_envv = _strtok(var_envv, "=");
		if (_strcmp(name_envv, namme) == 0)
		{
			free(daash->_environ[ii]);
			daash->_environ[ii] = copy_info(name_envv, value);
			free(var_envv);
			return;
		}
		free(var_envv);
	}

	daash->_environ = _reallocdp(daash->_environ, ii, sizeof(char *) * (ii + 2));
	daash->_environ[ii] = copy_info(namme, value);
	daash->_environ[ii + 1] = NULL;
}
