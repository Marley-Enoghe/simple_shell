#include "main.h"

/**
 * rev_string - reverses a string.
 * @ss: input string.
 * Return: no return.
 */
void rev_string(char *ss)
{
	int count = 0, ii, j;
	char *str, tempp;

	while (count >= 0)
	{
		if (ss[count] == '\0')
			break;
		count++;
	}
	str = ss;

	for (ii = 0; ii < (count - 1); ii++)
	{
		for (j = ii + 1; j > 0; j--)
		{
			tempp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = tempp;
		}
	}
}
