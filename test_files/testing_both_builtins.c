#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *dirc = _getenv("PWD");
	printf("Current directory: %s\n", dirc);

	char *argss[] = {"cd", "..", NULL};
	shell_cd(argss);

	char *argss3[] = {"cd", "_test_", NULL};
	shell_cd(argss3);

	dirc = _getenv("PWD");
	printf("Current directory: %s\n", dir);

	argss[0] = "setenv";
	argss[1] = "SHELL";
	argss[2] = "myshell";
	argss[3] = NULL;
	shell_setenv(argss);

	/* The value of the environment variable */
	char *val = getenv("SHELL");
	if (val == NULL)
	{
		fprintf(stderr, "Failed to get the  environment variable\n");
		exit(EXIT_FAILURE);
	}
	if (strcmp(val, "myshell") != 0)
	{
		fprintf(stderr, "Unexpected environment variable value: %s\n", value);
		exit(EXIT_FAILURE);
	}

	argss[0] = "unsetenv";
	argss[1] = "SHELL";
	argss[2] = NULL;
	shell_unsetenv(argss);

	/* The value of the environment variable again */
	val = getenv("MYVAR");
	if (val != NULL)
	{
		fprintf(stderr, "Environment variable was not unset\n");
		exit(EXIT_FAILURE);
	}

	printf("All setenv and unsetenv tests passed\n");

	argss[0] = "exit";
	argss[1] = NULL;
	shell_exit(argss);

	return (0);
}
