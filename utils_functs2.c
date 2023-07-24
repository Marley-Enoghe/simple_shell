#include "shell.h"

/**
 * _strcpy - this is used to copy a string
 * @dest: this is the destination
 * @src: this is the source
 *
 * Return: Returns a pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int je = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[je])
	{
		dest[je] = src[je];
		je++;
	}
	dest[je] = 0;
	return (dest);
}

/**
 * _strcat - uesd to concatenate 2 strings
 * @dest: this is the destination buffer
 * @src: this is the source buffer
 *
 * Return: Returns a pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strdup -used to duplicate a string
 * @str: this is the string to duplicate
 *
 * Return:this a pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int lengths = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lengths++;
	ret = malloc(sizeof(char) * (lengths + 1));
	if (!ret)
		return (NULL);
	for (lengths++; lengths--;)
		ret[lengths] = *--str;
	return (ret);
}

/**
 *_putchar -used to write the character c to stdout
 * @c: This is the character to print
 * Return:Returns 1 On success.
 * On error, return -1 is, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strspn - this is a function that gets the
 *           length of a prefix substring
 *
 * @s: this is a pointer to string input
 * @accept: a substring prefix to look for
 *
 * Return: this is the number of bytes in the initial segment
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int in, jo;

	for (in = 0; s[in]; in++)
	{
		for (jo = 0; accept[jo]; jo++)
		{
			if (s[in] == accept[jo])
				break;
		}
		if (!accept[jo])
			return (in);
	}

	return (in);
}