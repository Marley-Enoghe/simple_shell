#include "main.h"

/**
 * _strcat - concatenate two strings
 * @destt: char pointer the dest of the copied str
 * @ssrc: const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *destt, const char *ssrc)
{
	int ii;
	int j;

	for (ii = 0; dest[ii] != '\0'; ii++)
		;

	for (j = 0; ssrc[j] != '\0'; j++)
	{
		destt[ii] = ssrc[j];
		ii++;
	}

	destt[ii] = '\0';
	return (destt);
}

/**
 * *_strcpy - Copies the string pointed to by src.
 * @destt: Type char pointer the dest of the copied str
 * @ssrc: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *destt, char *ssrc)
{

	size_t aa;

	for (aa = 0; ssrc[aa] != '\0'; aa++)
	{
		destt[aa] = ssrc[aa];
	}
	destt[aa] = '\0';

	return (destt);
}

/**
 * _strcmp - Function that compares two strings.
 * @ss1: type str compared
 * @ss2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *ss1, char *ss2)
{
	int ii;

	for (ii = 0; ss1[ii] == ss2[i] && ss1[ii];ii++)
		;

	if (ss1[ii] > ss2[ii])
		return (1);
	if (ss1[ii] < ss2[ii])
		return (-1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (ii = 0; s[ii]; ii++)
	{
		if (s[ii] < 48 || s[ii] > 57)
			return (0);
	}
	return (1);
}
