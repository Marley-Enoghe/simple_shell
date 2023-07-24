#include "../shell.h"

int main(void)
{
	char **args;
	char *cmdd = "env";

	argss = tokenize_input(cmdd);
	if (args == NULL || *args == NULL)
	{
		fprintf(stderr, "Failed to tokenize input\n");
		return (EXIT_FAILURE);
	}

	if (execute(argss) != 0)
	{
		fprintf(stderr, "Failed to execute command: %s\n", cmdd);
		free_tokens(argss);
		return (EXIT_FAILURE);
	}

	free_tokens(argss);
	return (EXIT_SUCCESS);
}
