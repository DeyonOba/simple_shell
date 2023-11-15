#include "shell.h"

/**
 * command_error - Handles command error
 * @file_name: File name
 * @num_shell_calls: Number of shell call (hsh)
 * @command: Command string
 *
 * Return: Error message
 */
void command_error(char *file_name, int num_shell_calls, char *command)
{
	_dprintf(
			STDERR_FILENO,
			"%s: %d: %s: not found\n",
			file_name, num_shell_calls,
			command
		);
}

/**
 * exit_error - Handles exit error
 * @file_name: File name
 * @num_shell_calls: Number of shell call (hsh)
 * @commands: Command string
 *
 * Return: Error message
 */
void exit_error(char *file_name, int num_shell_calls, char **commands)
{
	_dprintf(
			STDERR_FILENO,
			"%s: %d: %s: Illegal number: %s\n",
			file_name, num_shell_calls,
			commands[0], commands[1]
	);
}

/**
 * default_error - Handles error
 * @file_name: File name
 * @num_shell_calls: Number of shell call (hsh)
 * @command: Command string
 *
 * Return: Error message
 */
void default_error(char *file_name, int num_shell_calls, char *command)
{
	(void)file_name;
	(void)num_shell_calls;
	(void)command;
}

/**
 * file_error - Handles file error
 * @file_name: File name
 * @num_shell_calls: Number of shell call (hsh)
 * @command: Command string
 *
 * Return: Error message
 */
void file_error(char *file_name, int num_shell_calls, char *command)
{
	(void)file_name;
	(void)num_shell_calls;
	(void)command;
}
