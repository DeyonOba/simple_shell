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
	int hsh_num_calls = 0;

	/* void cast the main prototypes*/
	(void)(argc);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
			fflush(stdout);

			execute_shell(&hsh_num_calls, argv[0], env);
		}
		else
			execute_shell(&hsh_num_calls, argv[0], env);
	}
	return (EXIT_SUCCESS);
}

