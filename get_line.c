#include "shell.h"

/**
 * get_line - used for reading input from the standard input.
 *
 * Return: to return the string enter by the user.
*/
void *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buf_poss, buf_sizee;
    char current_char;
	int input_len = 0;
	char *input_str = NULL;
	
	while (1)
	{
		if (buf_poss >= buf_sizee)
		{
			buf_sizee = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buf_poss = 0;
			if (buf_sizee == 0)
				return (input_str);
			else if (buf_sizee < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		current_char = buffer[buf_poss];

		buf_poss++;

		if (current_char == '\n')
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = '\0';
			return (input_str);
		}
		else
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = current_char;
			input_len++;
		}
	}
}