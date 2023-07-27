#include "main.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @ss: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *ss)
{
	char *nnew;
	size_t lenn;

	lenn = _strlen(ss);
	nnew = malloc(sizeof(char) * (lenn + 1));
	if (nnew == NULL)
		return (NULL);
	_memcpy(nnew, ss, lenn + 1);
	return (nnew);
}

/**
 * _strlen - Returns the lenght of a string.
 * @ss: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *ss)
{
	int lenn;

	for (lenn = 0; ss[lenn] != 0; lenn++)
	{
	}
	return (lenn);
}

/**
 * cmp_chars - compare chars of strings
 * @sttr: input string.
 * @delimm: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char sttr[], const char *delimm)
{
	unsigned int ii, j, k;

	for (ii = 0, k = 0; sttr[ii]; ii++)
	{
		for (j = 0; delimm[j]; j++)
		{
			if (sttr[ii] == delimm[j])
			{
				k++;
				break;
			}
		}
	}
	if (ii == k)
		return (1);
	return (0);
}

/**
 * _strchr - locates a character in a string,
 * @ss: string.
 * @cc: character.
 * Return: pointer to the first occur of the char c.
 */
char *_strchr(char *ss, char cc)
{
	unsigned int ii = 0;

	for (; *(ss + ii) != '\0'; ii++)
		if (*(ss + ii) == cc)
			return (ss + ii);
	if (*(ss + ii) == cc)
		return (ss + ii);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @ss: initial segment.
 * @acceptt: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *ss, char *acceptt)
{
	int ii, j, bool;

	for (ii = 0; *(ss + ii) != '\0'; ii++)
	{
		bool = 1;
		for (j = 0; *(acceptt + j) != '\0'; j++)
		{
			if (*(ss + ii) == *(acceptt + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (ii);
}
