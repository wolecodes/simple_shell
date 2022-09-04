#include "shell.h"

int main(int argc __attribute__ ((unused)), char **argv)
{
	char **args;
	char *input;
	int cmd_type;
	(void) argv;

	signal(SIGINT, ctrl_C);

	while (1)
	{
		printer(" ($) ", STDOUT_FILENO);
		input = _getline();

		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				break;
		}
		args = tokenize(input, DELIM);
		cmd_type = check_command(args[0]);
		shell_execute(args, cmd_type);
	}
	return (1);
}
