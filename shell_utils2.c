#include "shell.h"
/**
 * check_command- check the command
 * @command: the command to be checked
 * Return: constant variable representing the type of command
 */
int check_command(char *command)
{
	int i = 0;

	char *int_cmd[] = {"exit", "cd", "env", NULL};

	while (command[i])
	{
		if (command[i] == '/')
			return (EXTERNAL_CMD);
		i++;
	}
	i = 0;
	while (int_cmd[i] != NULL)
	{
		if (_strcmp(command, int_cmd[i]) == 0)
			return (INTERNAL_CMD);
		i++;
	}
	return (INVALID_CMD);
}
/**
 * execute- execute the shell
 * @commands: command to be execute
 * @cmd_type: type of the command to be executed
 */
void execute(char **commands, int cmd_type)
{
	void (*func)(char **command);

	switch (cmd_type)
	{
		case EXTERNAL_CMD:
			{
				if (execve(commands[0], commands, NULL) == -1)
				{
					perror(_getenv("PWD"));
					exit(2);
				}
				break;
			}
		case INTERNAL_CMD:
			{
				func = get_func(commands[0]);
				func(commands);
				break;
			}
		case PATH_CMD:
			{
				break;
			}
		case INVALID_CMD:
			{
				break;
			}
	}
}
