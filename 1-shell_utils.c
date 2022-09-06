#include "shell.h"
/**
 * ctrl_C - contol function that siganl end of transmission
 * @signum: the signal value
 */
void ctrl_C(int signum)
{
	if (signum == SIGINT)
		printer("\n ($) ", STDIN_FILENO);
}

/**
 * _getline - takes input from the user
 *
 * Return: the string read
 */
char *_getline(void)
{
	int bufSize = BUFSIZE, no_read, position = 0;

	char *buffer = malloc(bufSize * sizeof(char));
	char c;

	if (buffer == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		no_read = read(STDIN_FILENO, &c, 1);
		if (c == EOF || !no_read)
		{
			if (isatty(STDIN_FILENO) == 1)
			{
				printer("\n", STDIN_FILENO);
				return (NULL);
			}
		}
		else if (c == '\n' || !no_read)
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;
		if (position >= bufSize)
		{
			bufSize += BUFSIZE;
			buffer = _realloc(buffer, BUFSIZE, bufSize);
			if (!buffer)
			{
				perror("Failed to re-allocate a space in the memory");
				exit(EXIT_FAILURE);
			}
		}
	}
}
int is_delimeter(const char *delimeter, char c);
/**
 * tokenize - Tokenize a string
 * @str: string to be tokenize
 * @delim: character to tokenize
 * Return: pointer
 */
char **tokenize(char *str, const char *delim)
{
	int k = 0, j = 0, i = 0, count = 0, len[1200];
	char **arr;

	if (str == NULL || !(*str))
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (is_delimeter(delim, str[i]))
			continue;
		j = i;
		while (!is_delimeter(delim, str[i]) && str[i])
			i++;
		if (i > j)
			len[count++] = i - j;
		if (!str[i])
			break;
	}
	if (!count)
		return (NULL);
	arr = malloc((count + 1) * sizeof(char *));
	for (i = 0; str[i]; i++)
	{
		if (is_delimeter(delim, str[i]))
			continue;
		arr[k] = malloc((len[k] + 1) * sizeof(char));
		j = 0;
		while (!is_delimeter(delim, str[i]) && str[i])
			arr[k][j++] = str[i++];
		arr[k++][j] = '\0';
		if (!str[i])
			break;
	}
	arr[count] = NULL;
	return (arr);
}
/**
 * is_delimeter- check if a character is delimeter
 * @delimeter: pointer to delimeter
 * @c: character
 * Return: 1 if its true 0 for false
 */
int is_delimeter(const char *delimeter, char c)
{
	int i = 0;

	if (!delimeter)
		return (0);
	while (delimeter[i])
	{
		if (delimeter[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/**
 * shell_execute - check the parsed command
 * @cmd_type: check the command
 * @command: command parsed
 */
void shell_execute(char **command, int cmd_type)
{
	int stat;
	pid_t PID;

	if (cmd_type == EXTERNAL_CMD || cmd_type == PATH_CMD)
	{
		PID = fork();

	if (PID == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			perror("Failed");
			exit(2);
		}
	}
	if (PID < 0)
	{
		perror("failed to call fork");
		exit(1);
	}
	else
		wait(&stat);
	}
	else
		execute(command, cmd_type);
}
