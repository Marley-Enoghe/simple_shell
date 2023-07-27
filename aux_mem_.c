#include "main.h"

/**
 * _memcpy - For coping information between void pointers.
 * @newptr: The destination pointer.
 * @ptr: A source pointer.
 * @size: The size of the new pointer.
 *
 * Return: None.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int j;

	for (j = 0; j < size; j++)
		char_newptr[j] = char_ptr[j];
}

/**
 * _realloc - Used to reallocate a memory block.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size, in bytes, of the allocated space of ptr.
 * @new_size: The new size, in bytes, of the new memory block.
 *
 * Return: A ptr.
 * if new_size == old_size, returns a ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp -The  reallocates a memory block of a double pointer.
 * @ptr: A double pointer to the memory previously allocated.
 * @old_size: The size, in bytes, of the allocated space of ptr.
 * @new_size: The new size, in bytes, of the new memory block.
 *
 * Return: A ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int j;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (j = 0; j < old_size; j++)
		newptr[j] = ptr[j];

	free(ptr);

	return (newptr);
}
