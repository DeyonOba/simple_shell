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
	int i = 0;

	while (env[i] != NULL)
	{
		if (strncmp(env[i], vname, strlen(vname)) == 0)
		{
			return (env[i] + strlen(vname) + 1);
		}
		i += 1;
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
	char *token, *temp_path, *file_path;
	char *path;
	struct stat fstatus;

	if (stat(cmd, &fstatus) == 0)
	{
		file_path = strdup(cmd);
		if (file_path == NULL)
			return ("");
		return (file_path);
	}

	path = _getenv(env, "PATH");
	if (path == NULL)
		return ("");
	temp_path = strdup(path);
	if (temp_path == NULL)
		return ("");

	token = strtok(temp_path, ":");
	while (token != NULL)
	{
		char path_buffer[1024];

		strncpy(path_buffer, token, sizeof(path_buffer) - 1);
		strcat(path_buffer, "/");
		strcat(path_buffer, cmd);
		if (stat(path_buffer, &fstatus) == 0)
		{
			free(temp_path);
			file_path = strdup(path_buffer);
			if (file_path == NULL)
				return ("");
			return (file_path);
		}
		token = strtok(NULL, ":");
	}
	free(temp_path);
	return ("");
}
