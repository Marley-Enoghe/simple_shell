#include "main.h"

/**
 * without_comment - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *without_comment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @dattash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *dattash)
{
	int loop, i_eof;
	char *inputt;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		inputt = read_line(&i_eof);
		if (i_eof != -1)
		{
			inputt = without_comment(inputt);
			if (inputt == NULL)
				continue;

			if (check_syntax_error(dattash, inputt) == 1)
			{
				dattash->status = 2;
				free(inputt);
				continue;
			}
			input = rep_var(input, dattash);
			loop = split_commands(dattash, inputt);
			datash->counter += 1;
			free(inputt);
		}
		else
		{
			loop = 0;
			free(inputt);
		}
	}
}
