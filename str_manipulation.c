#include "main.h"

/**
 * _strlen - length of a string
 * @strput: input string
 * Return: length
 */

int _strlen(char *strput)
{
	int i = 0;

	while (*strput != '\0')
	{
		++i;
		++strput;
	}
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: string destination
 * @src: string source
 * Return: concatenated string
 */

char *_strcat(char *dest, char *src)
{
	char *tmp = dest + _strlen(dest);

	while (*src)
		*tmp++ = *src++;
	*tmp = 0;
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @put1: input 1
 * @put2: input 2
 * Return: 1 or 0
 */

int _strcmp(char *put1, char *put2)
{
	while (*put1)
	{
		if (*put1 != *put2)
			break;
		put1++;
		put2++;
	}

	return (*(unsigned char *)put1 - *(unsigned char *)put2);
}

/**
 * _strdup - duplicates the content of astring to another
 * @str: string to be duplicated
 * Return: duplicated string
 */

char *_strdup(char *str)
{
	int j, m;
	char *s_copy;

	if (!str)
		return (NULL);
	m = _strlen(str);
	s_copy = malloc(sizeof(char) * m + 1);
	if (!s_copy)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	for (j = 0; j < m; j++)
		s_copy[j] = str[j];
	s_copy[j] = 0;
	return (s_copy);
}
