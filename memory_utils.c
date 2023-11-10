#include "shell.h"

/**
 * free_array - Free dynamically allocated array of strings
 * @array: Array
 * @array_count: Number of elements in array
 */
void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}

/**
 * _realloc - Reallocate dynamically allocate memory
 * @ptr: Void pointer to dynamically allocate memory
 * @size: Size of the block of memory in bytes
 *
 * Return: Void pointer to newly allocate memory
 */
void *_realloc(void *ptr, size_t size)
{
	void *rptr;
	size_t new_size;

	/* condition equivalent to free()*/
	if (size != 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* condition equivalent to malloc()*/
	if (ptr == NULL)
	{
		return (malloc(size));
	}

	rptr = malloc(size);

	/* return pointer if reallocation failed*/
	if (rptr == NULL)
		return (ptr);

	/* Borrowed code for copying size of memory*/
	/*strcpy not working for void type*/
	new_size = (size < sizeof(ptr)) ? size : sizeof(ptr);

	memcpy(rptr, ptr, new_size);

	free(ptr);
	return (rptr);
}


