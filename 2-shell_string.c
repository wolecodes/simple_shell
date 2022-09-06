#include "shell.h"
/**
 * _strlen - get the lenght of the string
 * @str: char pointer
 * Return: 1
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
/**
 * _strcmp - compare two strings
 * @str1: first string
 * @str2: second string
 * Return: identical strings ot otherwise
 */
int _strcmp(char *str1, char *str2)
{
	int len1 = _strlen(str1);
	int len2 = _strlen(str2);
	int i;

	if (len1 != len2)
		return (-1);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}
