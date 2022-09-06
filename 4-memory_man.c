#include "shell.h"
/**
 * *_realloc- reallocate memory using malloc and free
 * @ptr: pointer
 * @old: the old size
 * @new: the new size
 * Return: return the void pointer else null
 */
void *_realloc(void *ptr, int old, int new)
{
	void *tmp;
	int i, min;

	if (!ptr)
		return (malloc(new));
	else if (new == old)
		return (ptr);
	else if (new == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		min = (new < old) ? new : old;
		tmp = malloc(new);
		if (tmp)
		{
			for (i = 0; i < min; i++)
				*((char *)tmp + i) = *((char *)ptr + i);
			free(ptr);
			return (tmp);
		}
		else
			return (NULL);
	}
}
