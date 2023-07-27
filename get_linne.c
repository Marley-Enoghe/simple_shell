#include "main.h"

/**
 * bring_line - assigns the line var for get_line
 * @lineptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @j: size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - Read inpt from stream
 * @lineptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int ii;
	static ssize_t inputt;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (inputt == 0)
		fflush(stream);
	else
		return (-1);
	inputt = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		ii = read(STDIN_FILENO, &t, 1);
		if (ii == -1 || (ii == 0 && inputt == 0))
		{
			free(buffer);
			return (-1);
		}
		if (ii == 0 && inputt != 0)
		{
			inputt++;
			break;
		}
		if (inputt >= BUFSIZE)
			buffer = _realloc(buffer, inputt, inputt + 1);
		buffer[inputt] = t;
		inputt++;
	}
	buffer[inputt] = '\0';
	bring_line(lineptr, n, buffer, inputt);
	retval = inputt;
	if (ii != 0)
		input = 0;
	return (retval);
}
