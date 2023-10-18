#include "shell.h"

/**
 * free_array - Free dynamically allocated array of strings
 * @array: Array
 * @array_count: Number of elements in array
 */
void free_array(char **array, int array_count)
{
	int i;

	for (i = 0; i < array_count; i++)
	{
		free(array[i]);
	}
	free(array);
}

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


