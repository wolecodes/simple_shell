#include "shell.h"

int printer(char *var, int fd)
{
	return (write(fd, var, strlen(var)));
}

void (*get_func(char *command))(char **)
{
	int i;

	map_func map[] = {
		{"env", dis_env},
		{"cd", change_dir},
		{"exit", quit}
	};
	for (i = 0; i < 3; i++)
	{
		if (_strcmp(command, map[i].cmd_name) == 0)
			return (map[i].func);
	}
	return (NULL);
}
