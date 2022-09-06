#include "shell.h"
/**
 * dis_env- displays enviroment variable
 * @command: command parsed
 */
void dis_env(char **command __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		printer(environ[i++], STDOUT_FILENO);
		printer("\n", STDOUT_FILENO);
	}
}
void quit(char **command)
{
	(void) command;
}

void change_dir(char **command)
{
	(void) command;
}
