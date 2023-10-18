#include "shell.h"

char *hsh_read_line(void)
{
	char *line = NULL;
	size_t size = 0;

	if (getline(&line, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			/*_print("\n", 1);*/
			exit(1);
		}
		else
			perror("Read Line Failed");
	}
	return (line);
}

char **hsh_parse_line(char *line, int *cmd_count)
{
	int  MAX_CMDS = 10;
	char **cmds_args = malloc(MAX_CMDS * sizeof(char *));
	char *whitespace = " \n\t\r";
	char *token = strtok(line, whitespace);

	while (token != NULL)
	{
		cmds_args[*cmd_count] = strdup(token);
		*cmd_count += 1;

		if (*cmd_count >= MAX_CMDS)
		{
			MAX_CMDS += 5;
			cmds_args = realloc(cmds_args, MAX_CMDS * sizeof(char *));
		}

		token = strtok(NULL, whitespace);
	}

	return (cmds_args);
}
