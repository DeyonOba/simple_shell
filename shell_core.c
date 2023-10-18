#include "shell.h"

/**
 * execute_shell - Execute Shell
 * @hsh_sh_calls: Number of Shell calls
 */
void execute_shell(int *hsh_sh_calls)
{
	int cmd_count = 0;
	char *line = hsh_read_line();
	char **cmds_args = hsh_parse_str(line, &cmd_count, " \n\t\r");

	/*free(line);*/
	*hsh_sh_calls += 1;

	if (cmds_args[0] != NULL)
	{
		exec_command(cmds_args);
	}

	free_array(cmds_args, cmd_count);
	free(line);
}

/**
 * exec_command - Execute commands
 * @cmds: Array of arguments
 */
void exec_command(char **cmds)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(cmds[0], cmds, NULL) == -1)
		{
			perror("execve Failed");
			exit(1);
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

		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 1)
			{
				perror("Child pid Error");
			}
		}
	}
}
