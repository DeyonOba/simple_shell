#include "shell.h"


int main(int argc, char **argv, char **env)
{
	int CTRL_HSH = 1, exit_code = EXIT_SUCCESS, hsh_num_calls = 0;

	/* void cast the main prototypes*/
	(void)(argc);
	(void)(argv);
	(void)(env);

	if (isatty(STDIN_FILENO))
	{
		while (CTRL_HSH)
		{
			prompt();
			fflush(stdout);

			execute_shell(&CTRL_HSH, &exit_code, &hsh_num_calls);
		}
	}
	else
	{
		execute_shell(&CTRL_HSH, &exit_code, &hsh_num_calls);
	}
	return (exit_code);
}