#include "shell.h"

/**
 * command_error - Handles command error
 * @file_name: File name
 * @sh_call_num: Number of shell call (hsh)
 * @command: Command string
 *
 * Return: Error message
 */
void command_error(char *file_name, int sh_call_num, char *command)
{
	_dprintf(
			STDERR_FILENO,
			"%s: %d: %s: not found\n",
			file_name, sh_call_num,
			command
		);
}

/**
 * default_error - Handles error
 * @file_name: File name
 * @sh_call_num: Number of shell call (hsh)
 * @command: Command string
 *
 * Return: Error message
 */
void default_error(char *file_name, int sh_call_num, char *command)
{
	(void)file_name;
	(void)sh_call_num;
	(void)command;
}

/**
 * file_error - Handles file error
 * @file_name: File name
 * @sh_call_num: Number of shell call (hsh)
 * @command: Command string
 *
 * Return: Error message
 */
void file_error(char *file_name, int sh_call_num, char *command)
{
	(void)file_name;
	(void)sh_call_num;
	(void)command;
}
