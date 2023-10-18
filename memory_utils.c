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
