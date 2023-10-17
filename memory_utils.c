#include "shell.h"

void free_array(char **array, int array_count)
{
	int i;
	
	for (i = 0; i < array_count; i++)
	{
		free(array[i]);
	}
	free(array);
}		
