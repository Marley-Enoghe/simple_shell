#include "shell.h"

/**
 * main - used for a simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *inputs_;
	char **args_;
	int status_;

	/* the signal handlers */
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	do {
		inputs_ = get_input();
		if (!inputs_ || !*inputs_)
			break;

		args_ = tokenize_input(inputs_);
		if (!args_ || !*args_)
		{
			free(inputs_);
			free_tokens(args_);
			continue;
		}
		status_ = execute(args_);
		free(inputs_);
		free_tokens(args_);

		/* used to Set status to 1 to continue the loop */
		status_ = 1;
	} while (status_);

	return (EXIT_SUCCESS);
}