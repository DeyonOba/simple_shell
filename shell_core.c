#include "shell.h"

/**
 * execute_shell - Execute Shell
 * @line: Allocated String from stdin
 * @num_shell_calls: Number of Shell calls
 * @env: Environment
 * @file_name: File name
 */
void execute_shell(
char *line, int *num_shell_calls,
char *file_name, char **env
)
{
	int cmd_count = 0;
	char **cmds_args, *file_path;

	*num_shell_calls += 1;
	
	cmds_args = hsh_parse_str(line, &cmd_count, " \n\t\r");
	file_path = _getpath(cmds_args[0], env);

	if (strcmp(file_path, "") != 0)
	{
		exec_command(file_path, cmds_args, env);
		free(file_path);
	}
	
	else
	{
		command_error(file_name, *num_shell_calls, cmds_args[0]);
	}
	free_array(cmds_args);
}

/**
 * exec_command - Execute commands
 * @cmds: Array of arguments
 * @num_shell_calls: Number of shell calls
 * @env: Environment
 * @file_name: File name
 */
void exec_command(char *file_path, char **cmds, char **env)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		if (execve(file_path, cmds, env) == -1)
		{
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
}
