#include "shell.h"

/**
 * _getenv - Gets the environment variable value
 * @env: Shell environment
 * @vname: Variable name
 *
 * Return: Dynamically allocated variable value or NULL on failure
 */
char *_getenv(char **env, char *vname)
{
	int i;
	char *token, *value;

	for (i = 0; env[i] != NULL; i++)
	{
		token = strtok(env[i], "=");
		if (strcmp(token, vname) == 0)
		{
			token = strtok(NULL, "=");
			value = strdup(token);

			return (value);
		}
	}
	return (NULL);
}

/**
 * _getpath - Get the path for an executable command
 * @cmd: Command
 * @env: Environment
 *
 * Return: Dynamicall allocated string contain the path or NULL on failure
 */
char *_getpath(char *cmd, char **env)
{
	char *token, *temp_path;
	char *path = _getenv(env, "PATH");
	char path_buffer[1024];
	struct stat fstatus;

	if (path == NULL)
	{
		return (NULL);
	}

	temp_path = strdup(path);
	free(path);

	token = strtok(temp_path, ":");

	while (token != NULL)
	{
		strcpy(path_buffer, token);
		strcat(path_buffer, "/");
		strcat(path_buffer, cmd);

		if (stat(path_buffer, &fstatus) == 0 && fstatus.st_mode & S_IXUSR)
		{
			free(temp_path);
			return (strdup(path_buffer));
		}
		token = strtok(NULL, ":");
	}

	free(temp_path);

	if (stat(cmd, &fstatus) == 0 && fstatus.st_mode & S_IXUSR)
	{
		return (strdup(cmd));
	}

	return (NULL);
}
