#include "shell.h"


int main(int argc, char **argv, char **env)
{
	int hsh_num_calls = 0;

	/* void cast the main prototypes*/
	(void)(argc);
	(void)(argv);
	(void)(env);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
			fflush(stdout);
			
			execute_shell(&hsh_num_calls);
		}
		else
			execute_shell(&hsh_num_calls);
	}
	return (EXIT_SUCCESS);
}