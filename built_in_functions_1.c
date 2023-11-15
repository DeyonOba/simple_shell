#include "shell.h"

/**
 * is_numeric - Checks if a string contains numbers
 * @string: Input string
 *
 * Return: 1 is numeric, or 0 not numeric
 */
int is_numeric(char *string)
{
	char *endptr;

	strtod(string, &endptr);
	return (*string != '\0' && *endptr == '\0');
}

/**
 * shell_exit - Controls shell exit and exit status
 * @filename: Name of file
 * @cmds_args: An array of string containing arguments
 * @cmd_count: Number of string array in cmds_args
 * @num_shell_calls: Number of shell executions
 * @ctrl_loop: Pointer to a pointer that controls the loop of the shell
 *
 * Return: Shell exit status
 */
int shell_exit(
	char *filename, char **cmds_args, int cmd_count,
	int num_shell_calls, int **ctrl_loop
)
{
	if (cmd_count == 1)
	{
		**ctrl_loop = 0;
		return (EXIT_SUCCESS);
	}
	else if (is_numeric(cmds_args[1]))
	{
		if (string_to_number(cmds_args[1]) < 0)
		{
			exit_error(filename, num_shell_calls, cmds_args);
			return (2);
		}
		else
		{
			**ctrl_loop = 0;
			return (string_to_number(cmds_args[1]));
		}
	}
	else
	{
		exit_error(filename, num_shell_calls, cmds_args);
		return (2);
	}
}

/**
 * print_env - Prints environment variables
 * @env: Array of strings containing environment variables
 */
void print_env(char **env)
{
	int i = 0;

	for (; env[i] != NULL; i++)
	{
		_dprintf(STDOUT_FILENO, "%s\n", env[i]);
	}
}
