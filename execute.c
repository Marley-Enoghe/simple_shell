#include "shell.h"
/**
 * execute - Used to execute a command with the arguments.
 * @argv: This is an array of strings containing the command and its arguments.
 *
 * Return: Return the exit status of the executed command.
 */
int execute(char **argv)
{
	pid_t id_;
    char *cmd_path_, *env_p[2];
	int status_ = 0;

	if (argv == NULL || *argv == NULL)
		return (status_);
	if (check_for_builtin(argv))
		return (status_);

	id_ = fork();
	if (id_ < 0)
	{
		_puterror("fork");
		return (1);
	}
	if (id_ == -1)
		perror(argv[0]), free_tokens(argv), free_last_input();
	if (id_ == 0)
	{
		env_p[0] = get_path();
		env_p[1] = NULL;
		cmd_path_ = NULL;
		if (argv[0][0] != '/')
			cmd_path_ = find_in_path(argv[0]);
		if (cmd_path_ == NULL)
			cmd_path_ = argv[0];
		if (execve(cmd_path_, argv, env_p) == -1)
		{
			perror(argv[0]), free_tokens(argv), free_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(id_, &status_, WUNTRACED);
		} while (!WIFEXITED(status_) && !WIFSIGNALED(status_));
	}
	return (status_);
}