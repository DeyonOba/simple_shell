#include "shell.h"

void execute_shell(int *ctrl_hsh, int *exit_code, int *hsh_sh_calls)
{
	char *line = hsh_read_line(&ctrl_hsh);
	char **cmds_args = hsh_parse_line(line);
	
	(void)exit_code;
	(void)hsh_sh_calls;

	if (cmds_args[0] != NULL)
	{
		exec_command(cmds_args);
	}

	free(cmds_args);
	free(line);
}

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
