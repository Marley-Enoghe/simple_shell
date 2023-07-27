#include "main.h"

/**
 * _which - locates a command
 *
 * @cmdd: command name
 * @_environ: environment variable
 * Return: location of command.
 */
char *_which(char *cmdd, char **_environ)
{
	char *patth, *pttr_path, *ttoken_path, *diir;
	int len_diir, len_cmdd, ii;
	struct stat stt;

	patth = _getenv("PATH", _environ);
	if (patth)
	{
		pttr_path = _strdup(patth);
		len_cmdd = _strlen(cmdd);
		ttoken_path = _strtok(pttr_path, ":");
		ii = 0;
		while (ttoken_path != NULL)
		{
			if (is_cdir(patth, &ii))
				if (stat(cmdd, &stt) == 0)
					return (cmdd);
			len_diir = _strlen(ttoken_path);
			diir = malloc(len_diir + len_cmdd + 2);
			_strcpy(diir, ttoken_path);
			_strcat(diir, "/");
			_strcat(diir, cmdd);
			_strcat(diir, "\0");
			if (stat(diir, &stt) == 0)
			{
				free(pttr_path);
				return (diir);
			}
			free(diir);
			ttoken_path = _strtok(NULL, ":");
		}
		free(pttr_path);
		if (stat(cmdd, &stt) == 0)
			return (cmdd);
		return (NULL);
	}
	if (cmdd[0] == '/')
		if (stat(cmdd, &stt) == 0)
			return (cmdd);
	return (NULL);
}

/**
 * is_executable - determines if is an executable
 *
 * @dattash: data structure
 * Return: 0 if not executable, other no if it does
 */
int is_executable(data_shell *dattash)
{
	struct stat stt;
	int ii;
	char *inputt;

	inputt = dattash->args[0];
	for (ii = 0; inputt[ii]; ii++)
	{
		if (inputt[ii] == '.')
		{
			if (inputt[ii + 1] == '.')
				return (0);
			if (inputt[ii + 1] == '/')
				continue;
			else
				break;
		}
		else if (inputt[ii] == '/' && ii != 0)
		{
			if (inputt[ii + 1] == '.')
				continue;
			ii++;
			break;
		}
		else
			break;
	}
	if (ii == 0)
		return (0);

	if (stat(inputt + ii, &stt) == 0)
	{
		return (ii);
	}
	get_error(dattash, 127);
	return (-1);
}

/**
 * check_error_cmd - verifies if user has permissions
 *
 * @diir: destination directory
 * @dattash: data structure
 * Return: 1 if an error, 0 if not
 */
int check_error_cmd(char *diir, data_shell *dattash)
{
	if (diir == NULL)
	{
		get_error(dattash, 127);
		return (1);
	}

	if (_strcmp(dattash->args[0], diir) != 0)
	{
		if (access(diir, X_OK) == -1)
		{
			get_error(dattash, 126);
			free(diir);
			return (1);
		}
		free(diir);
	}
	else
	{
		if (access(dattash->args[0], X_OK) == -1)
		{
			get_error(dattash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - executes command lines
 *
 * @dattash: data relevant(args and input)
 * Return: 1 on success.
 */
int cmd_exec(data_shell *dattash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *diir;
	(void) wpd;

	exec = is_executable(dattash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		diir = _which(dattash->args[0], dattash->_environ);
		if (check_error_cmd(diir, dattash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			diir = _which(dattash->args[0], dattash->_environ);
		else
			diir = dattash->args[0];
		execve(diir + exec, dattash->args, dattash->_environ);
	}
	else if (pd < 0)
	{
		perror(dattash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	dattash->status = state / 256;
	return (1);
}

/**
 * is_cdir - checks ":" if in current directory.
 * @patth: type char pointer char.
 * @ii: type int pointer of index.
 * Return: 1 if the is exist in cd, 0 otherwise.
 */
int is_cdir(char *patth, int *ii)
{
	if (patth[*ii] == ':')
		return (1);

	while (patth[*ii] != ':' && patth[*ii])
	{
		*ii += 1;
	}

	if (patth[*ii])
		*ii += 1;

	return (0);
}
