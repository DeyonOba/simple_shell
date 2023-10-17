#include "shell.h"

char *hsh_read_line(int **ctrl_hsh)
{
	char *line = NULL;
	size_t size = 0;

	if (getline(&line, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			**ctrl_hsh = 0;
			_print("\n", STDOUT_FILENO);
		}
		else
			perror("Read Line Failed");
	}
	return (line);
}

char **hsh_parse_line(char *line)
{
	int cmds_count = 0, MAX_CMDS = 10;
	char **cmds_args = malloc(MAX_CMDS * sizeof(char *));
	char *whitespace = " \n\t\r";
	char *token = strtok(line, whitespace);

	while (token != NULL)
	{
		cmds_args[cmds_count] = token;
		cmds_count++;

		if (cmds_count >= MAX_CMDS)
		{
			MAX_CMDS += 5;
			cmds_args = realloc(cmds_args, MAX_CMDS * sizeof(char *));
		}

		token = strtok(NULL, whitespace);
	}
	cmds_args[cmds_count] = NULL;
	return (cmds_args);
}
