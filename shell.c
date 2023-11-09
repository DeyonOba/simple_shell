#include "shell.h"

/**
 * main - Shell Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment
 *
 * Return: Sucess or Exit with error
 */
int main(int argc, char **argv, char **env)
{
	int exit_status = EXIT_SUCCESS, num_shell_calls = 0;
	size_t size = 0;
	char *line = NULL;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
			fflush(stdout);
		}

		if (getline(&line, &size, stdin) == -1)
			break;

		execute_shell(line, &num_shell_calls, argv[0], env);
		free(line);
		line = NULL;
	}
	free(line);
	return (exit_status);
}

