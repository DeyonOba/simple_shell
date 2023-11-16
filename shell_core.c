#include "shell.h"

/**
 * execute_shell - Execute Shell
 * @line: Allocated String from stdin
 * @num_shell_calls: Number of Shell calls
 * @file_name: File name
 * @ctrl_loop: Pointer to a variable that controls a while loop
 * @env: Environment
 *
 * Return: execution_status
 */
int execute_shell(
char *line, int *num_shell_calls,
char *file_name, int *ctrl_loop, char **env
)
{
	int cmd_count = 0, exec_status = EXIT_SUCCESS;
	char **cmds_args, *file_path;

	*num_shell_calls += 1;
	cmds_args = hsh_parse_str(line, &cmd_count, " \n\t\r");
	
	if (cmd_count == 0)
	{
		free_array(cmds_args);
		return (EXIT_SUCCESS);
	}
	
	if (strcmp(cmds_args[0], "exit") == 0)
	{
		exec_status = shell_exit(
			file_name, cmds_args, cmd_count,
			*num_shell_calls, &ctrl_loop);
	}
	else if (strcmp(cmds_args[0], "env") == 0)
		print_env(env);
	else
	{
		file_path = _getpath(cmds_args[0], env);
		if (strcmp(file_path, "") != 0)
		{
			exec_command(file_path, cmds_args, env);
			free(file_path);
		}
		else
		{
			command_error(file_name, *num_shell_calls, cmds_args[0]);
			exec_status = 127;
		}
	}
	free_array(cmds_args);
	return (exec_status);
}

/**
 * exec_command - Execute commands
 * @file_path: Path were executable is found
 * @cmds: Array of string arguments
 * @env: Environment
 *
 * Return: command status
 */
int exec_command(char *file_path, char **cmds, char **env)
{
	pid_t pid = fork();
	int command_status = EXIT_SUCCESS;

	if (pid == 0)
	{
		if (execve(file_path, cmds, env) == -1)
		{
			command_status = 2;
			perror("Error");
		}
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		int status;

		waitpid(pid, &status, 0); /* wait for the child process to end*/
	}
	return (command_status);
}
