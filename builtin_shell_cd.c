#include "shell.h"
/**
 * shell_cd - for changing to the current working directory of the shell
 * @args: this is an array of arguments
 */
void shell_cd(char **args)
{
	char *dirr = args[1];
	int rett;

	/* when no argument is provided, for changing to HOME directory */
	if (dirr == NULL)
	{
		dirr = _getenv("HOME");
		if (dirr == NULL)
		{
			_puts("cd: No HOME directory found\n");
			return;
		}
	}

	rett = chdir(dirr);
	if (rett == -1)
	{
		perror("cd");
	}
}
