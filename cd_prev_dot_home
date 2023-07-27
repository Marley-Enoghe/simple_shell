#include "main.h"

/**
 * cd_dot - changes to the parent directory
 *
 * @dattash: data relevant (environ)
 *
 * Return: no return
 */
void cd_dot(data_shell *dattash)
{
	char pwd[PATH_MAX];
	char *diir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, dattash);
	diir = dattash->argss[1];
	if (_strcmp(".", diir) == 0)
	{
		set_env("PWD", cp_pwd, dattash);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, dattash);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", dattash);
	}
	dattash->status = 0;
	free(cp_pwd);
}

/**
 * cd_previous - changes to the previous directory
 *
 * @dattash: data relevant (environ)
 * Return: no return
 */
void cd_previous(data_shell *dattash)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = _getenv("OLDPWD", dattash->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_env("OLDPWD", cp_pwd, dattash);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, dattash);
	else
		set_env("PWD", cp_oldpwd, dattash);

	p_pwd = _getenv("PWD", dattash->_environ);

	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	dattash->status = 0;

	chdir(p_pwd);
}

/**
 * cd_to_home - changes to home directory
 *
 * @dattash: data relevant (environ)
 * Return: no return
 */
void cd_to_home(data_shell *dattash)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = _getenv("HOME", dattash->_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, dattash);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(dattash, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, dattash);
	set_env("PWD", home, dattash);
	free(p_pwd);
	dattash->status = 0;
}
