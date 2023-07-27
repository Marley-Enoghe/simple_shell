#include "shell.h"

/**
 * _atoi - Used to converts a string to an integer.
 * @str: This the string to be converted.
 *
 * Return: Returns the integer value of the string.
 */
int _atoi(const char *str)
{
	int po, signs;
	unsigned int num_;

	po = 0;
	signs = 1;
	num_ = 0;

	while (str[po] != '\0')
	{
		if (str[po] == '-')
			signs *= -1;
		else if (str[po] >= '0' && str[po] <= '9')
			num_ = (num_ * 10) + (str[po] - '0');
		else
			break;
		po++;
	}
	return (num_ * signs);
}

/**
 **_memset - used to fill the memory with a constant byte
 *@s: This is the pointer to the memory area
 *@b: This is the byte to fill *s with
 *@n: This is the amount of bytes to be filled
 *Return: Returns a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int po;

	for (po = 0; po < n; po++)
		s[po] = b;
	return (s);
}

/**
 * _memcpy - This is a function for coping the memory area
 *
 * @dest: This is a buffer where we will copy to
 * @src: This is what is to be copied
 * @n: the n bytes of @src
 *
 * Return: Always return 0 on Success
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int ke;

	for (ke = 0; ke < n; ke++)
		dest[ke] = src[ke];
	return (dest);
}

/**
 * _realloc -used to reallocate a block of memory
 * @ptr:This is a pointer to previous malloc'ated block
 * @old_size: The byte size of previous block
 * @new_size:The byte size of new block
 *
 * Return: Returns a pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pj;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	pj = malloc(new_size);
	if (!pj)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		pj[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (pj);
}

/**
 * _calloc -This  a function that allocates memory for an array using malloc
 *          It is basically the equivalent to
 *           malloc followed by memset
 *
 * @nmemb: A size of array
 * @size: A size of each element
 *
 * Return:This is a pointer with new allocated memory
 *         or NULL if it fails
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *pj;

	if (nmemb == 0 || size == 0)
		return (NULL);

	pj = malloc(nmemb * size);
	if (pj == NULL)
		return (NULL);

	_memset(pj, 0, nmemb * size);

	return (pj);
}
