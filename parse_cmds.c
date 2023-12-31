#include "shell.h"

/**
 * hsh_parse_str - Parse string by a specified seperator
 * @line: Input string of a line from stdin
 * @args_count: Number of arguments parsed
 * @sep: Seperator or Delimeter
 *
 * Return: Dynamically allocated array of strings or NULL on failure
 */
char **hsh_parse_str(char *line, int *args_count, char *sep)
{
	int  MAX_CMDS = 10;
	char *token = strtok(line, sep);
	char **cmds_args = malloc((MAX_CMDS + 1) * sizeof(char *));
	char **new_cmds_args = NULL;

	if (cmds_args == NULL)
		return (NULL);

	while (token != NULL)
	{
		cmds_args[*args_count] = strdup(token);
		*args_count += 1;

		if (*args_count >= MAX_CMDS)
		{
			MAX_CMDS += 5;
			new_cmds_args = _realloc(cmds_args, MAX_CMDS * sizeof(char *));

			if (new_cmds_args == NULL)
			{
				free_array(cmds_args);
				return (NULL);
			}
			cmds_args = new_cmds_args;
		}

		token = strtok(NULL, sep);
	}
	cmds_args[*args_count] = NULL;

	return (cmds_args);
}
