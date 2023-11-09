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
	char **cmds_args = hsh_parse_str(line, &cmd_count, " \n\t\r");

	*num_shell_calls += 1;

	if (cmds_args[0] != NULL)
	{
		exec_command(cmds_args, file_name, *num_shell_calls, env);
	}

	free_array(cmds_args, cmd_count);
}

/**
 * exec_command - Execute commands
 * @cmds: Array of arguments
 * @num_shell_calls: Number of shell calls
 * @env: Environment
 * @file_name: File name
 */
void exec_command(
char **cmds, char *file_name,
int num_shell_calls, char **env
)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(cmds[0], cmds, env) == -1)
		{
			command_error(file_name, num_shell_calls, cmds[0]);
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
