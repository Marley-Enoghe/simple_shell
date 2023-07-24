#include "shell.h"

/**
 * _strlen - Used for returning the length of a string
 * @s: This is the string whose length to check
 *
 * Return: Returns an integer length of string
 */
int _strlen(const char *s)
{
	int j = 0;

	if (!s)
		return (0);

	while (*s++)
		j++;
	return (j);
}

/**
 * _strcmp - Used to compare two strings.
 * @s1: This is the 1st string to compare.
 * @s2: This is the 2nd string to compare.
 * Return: Used to 0 if @s1 and @s2 are equal,
 *         negative value if @s1 is less than @s2,
 *         or  positive value if @s1 is greater than @s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return ((int) (*s1) - (*s2));
}

/**
 * _strncmp - Used to Compare two strings up to a specified length.
 * @s1: The 1st string to compare.
 * @s2: The 2nd string to compare.
 * @n: The max number of characters to compare.
 *
 * Return: Rturns 0 if the strings are equal up to n characters, negative value
 *         if s1 is less than s2, or a positive value if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1, c2;

	while (n-- > 0)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;

		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			break;
	}

	return (0);
}

/**
 * _strstr - Used to checks if needle starts with haystack
 * @haystack: used in string to search
 * @needle: This is the substring to find
 *
 * Return: Return an address of next char of haystack or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int je;

	for (je = 0; haystack[je] != '\0'; je++)
	{
		if (haystack[je] == needle[0])
		{
			int p;

			for (p = 0; needle[p] != '\0'; p++)
			{
				if (haystack[je + p] != needle[p])
				{
					break;
				}
			}

			if (needle[p] == '\0')
			{
				return (&haystack[je]);
			}
		}
	}
	return (NULL);
}

/**
 * _strchr - Thia is a function that locates a character in a string
 *
 * @s: This is a pointer to our string array input
 * @c: This is a character to locate from input array
 *
 * Return: Used to return first occurence of charatcer or null if not found
*/

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	/**
	 * if c is '\0', you should return
	 * the pointer to the '\0' of the
	 * string s
	*/
	if (*s == c)
		return (s);
	/*return null if not found*/
	return (NULL);
}