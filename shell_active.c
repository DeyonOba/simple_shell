#include "shell.h"

/**
 * interactive_mode - Handle shell in interactive mode
 * @file_name: Name of excutable file
 * @env: Environment variable
 *
 * Return: sum of numbers
 */
int interactive_mode(char *file_name, char **env)
{
	int  num_hsh_calls = 0, exit_status = 0;

	while (1)
	{
		prompt();

		exit_status = shell_cpu(file_name, env, &num_hsh_calls);
		if (num_hsh_calls == -1)
			break;
	}
	return (exit_status);
}

/**
 * exec_command - Create processes and execute commands
 *
 * @pathname: String containg path directory
 * @args: Shell arguments
 * @environ: Environment variable
 */
void exec_command(char *pathname, char **args, char **environ)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(pathname, args, environ) == -1)
			perror(pathname);
	}

	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
	}

	else
		perror("Error");
}

/**
 * shell_cpu - Brain behind shell execution
 * @file_name: Executable file name
 * @env: Environment variable
 * @num_hsh_calls: Number of shell calls
 *
 * Return: Interger
 */
int shell_cpu(char *file_name, char **env, int *num_hsh_calls)
{
	char *line = NULL, *path, **cmds = NULL;
	int cmd_count = 0;
	size_t size = 0;

	*num_hsh_calls += 1;

	if (getline(&line, &size, stdin) == -1)
	{
		free(line);
		if (feof(stdin))
		{
			*num_hsh_calls = -1;
			_print("\n", STDIN_FILENO);
			return (EXIT_FAILURE);
		}
		return (EXIT_FAILURE);
	}

	cmds = arg_parser(line, &cmd_count, " \n\t\r");
	if (cmd_count == 0)
		return (EXIT_SUCCESS);
	
	if (strcmp(cmds[0], "exit") == 0)
	{
		*num_hsh_calls = -1;
		return (exit_code(cmds, cmd_count));
	}
	path = get_file_path(cmds[0], env);
	if (path == NULL)
	{
		command_error(file_name, *num_hsh_calls, cmds[0]);
	}

	if (cmd_count > 0)
	{
		exec_command(path, cmds, env);

	}

	/*free_array(cmds);*/
	return (EXIT_SUCCESS);
}
