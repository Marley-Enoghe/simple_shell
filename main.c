#include "main.h"

/**
 * free_data -free data struct
 *
 * @dattash: data struct
 * Return: no return
 */
void free_data(data_shell *dattash)
{
	unsigned int ii;

	for (ii = 0; dattash->_environ[ii]; ii++)
	{
		free(dattash->_environ[ii]);
	}

	free(dattash->_environ);
	free(dattash->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @dattash: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(data_shell *dattash, char **av)
{
	unsigned int ii;

	dattash->av = av;
	dattash->input = NULL;
	dattash->args = NULL;
	dattash->status = 0;
	dattash->counter = 1;

	for (ii = 0; environ[ii]; ii++)
		;

	dattash->_environ = malloc(sizeof(char *) * (ii + 1));

	for (ii = 0; environ[ii]; ii++)
	{
		dattash->_environ[ii] = _strdup(environ[ii]);
	}

	dattash->_environ[ii] = NULL;
	dattash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @acc: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int acc, char **av)
{
	data_shell dattash;
	(void) acc;

	signal(SIGINT, get_sigint);
	set_data(&dattash, av);
	shell_loop(&dattash);
	free_data(&dattash);
	if (dattash.status < 0)
		return (255);
	return (dattash.status);
}
