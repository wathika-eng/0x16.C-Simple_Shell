#include "main.h"

/**
 * _mem - allocates memory block
 * @ptr: input string
 * @prev_size: old size
 * @cur_size: new size
 * Return: allocated string
 */

void *_mem(void *ptr, unsigned int prev_size, unsigned int cur_size)
{
	void *tmp = NULL;

	if (cur_size == prev_size)
		return (ptr);
	if (!ptr)
	{
		free(ptr);
		tmp = malloc(cur_size);
		if (!tmp)
		{
			perror("Malloc failed");
			exit(errno);
		}
		return (tmp);
	}
	if (!cur_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	tmp = malloc(cur_size);
	if (!tmp)
	{
		perror("Malloc failed");
		exit(errno);
	}
	_fillmem(tmp, ptr, prev_size);
	free(ptr);
	return (tmp);
}

/**
 * _fillmem - fill memory
 * @dest: destination
 * @src: source
 * @num_bytes: no' of bytes
 * Return: destination string
 */

char *_fillmem(char *dest, char *src, unsigned int num_bytes)
{
	char *tmp = dest;

	while (num_bytes--)
		*dest++ = *src++;
	return (tmp);
}
