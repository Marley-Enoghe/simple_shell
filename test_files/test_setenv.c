#include "../shell.h"

int main(void)
{
	char *unset_argss[] = {"unsetenv", "MYVAR", NULL};
	char *argss[] = {"setenv", "MYVAR", "hello", NULL};

	/* Set environment variable */
	if (shell_setenv(argss) == -1)
	{
		fprintf(stderr, "Failed to set environment variable\n");
		exit(EXIT_FAILURE);
	}

	/* value of the environment variable */
	char *val = getenv("MYVAR");
	if (val == NULL)
	{
		fprintf(stderr, "Failed to get environment variable\n");
		exit(EXIT_FAILURE);
	}
	if (strcmp(val, "hello") != 0)
	{
		fprintf(stderr, "Unexpected environment variable value: %s\n", val);
		exit(EXIT_FAILURE);
	}

	/* Unset environment variable */
	if (shell_unsetenv(unset_argss) == -1)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
		exit(EXIT_FAILURE);
	}

	/* value of the environment variable again */
	val = getenv("MYVAR");
	if (val != NULL)
	{
		fprintf(stderr, "Environment variable was not unset\n");
		exit(EXIT_FAILURE);
	}

	printf("All tests passed\n");
	return (EXIT_SUCCESS);
}
