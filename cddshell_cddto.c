#include "main.h"

/**
 * cd_shell - changes current directory
 *
 * @dattash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *dattash)
{
	char *diir;
	int ishome, ishome2, isddash;

	diir = dattash->argss[1];

	if (diir != NULL)
	{
		ishome = _strcmp("$HOME", diir);
		ishome2 = _strcmp("~", diir);
		isddash = _strcmp("--", diir);
	}

	if (diir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(dattash);
		return (1);
	}

	if (_strcmp("-", diir) == 0)
	{
		cd_previous(dattash);
		return (1);
	}

	if (_strcmp(".", diir) == 0 || _strcmp("..", diir) == 0)
	{
		cd_dot(dattash);
		return (1);
	}

	cd_to(dattash);

	return (1);
}

/**
 * cd_to - changes to a directory given
 * by the user
 *
 * @dattash: data relevant (directory)
 * Return: no return
 */
void cd_to(data_shell *dattash)
{
	char pwd[PATH_MAX];
	char *diir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	diir = dattash->argss[1];
	if (chdir(diir) == -1)
	{
		get_error(dattash, 2);
		return;
	}

	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, dattash);

	cp_dir = _strdup(diir);
	set_env("PWD", cp_dir, dattash);

	free(cp_pwd);
	free(cp_dir);

	dattash->status = 0;

	chdir(diir);
}
