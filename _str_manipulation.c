#include "main.h"

/**
 * *_strcpy - copies the content of source to destination string
 * @dest: string destination
 * @src: string source
 * Return: pointer to string
 */

char *_strcpy(char *dest, char *src)
{
	char *tmp = dest;

	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (tmp);
}

/**
 * _strtok - parse strings separated by delimiter
 * @str: input string
 * @delim: separator
 * Return: first string
 */

char *_strtok(char *str, char *delim)
{
	static char *ptr;
	char i;

	if (str == NULL)
		str = ptr;
	do {
		i = *str++;
		if (!i)
			return (NULL);
	} while (_strchr(delim, i));
	str--;
	ptr = str + _strcspn(str, delim);
	if (*ptr)
		*ptr++ = 0;
	return (str);
}

/**
 * _strcspn - returns first occurence of any character in
 * second string in first string
 * @string: string input
 * @chars: character to check
 * Return: pointer to first the first match
 */

int _strcspn(char *string, char *chars)
{
	char i;
	char *j, *k;

	for (k = string, i = *k; i; k++, i = *k)
		for (j = chars; *j; j++)
			if (i == *j)
				return (k - string);
	return (k - string);
}

/**
 * _strchr - find character in a string
 * @strput: string input
 * @tar_char: target character
 * Return: pointer to first occurrence of c or null
 */

char *_strchr(char *strput, char tar_char)
{
	char c;

	while (true)
	{
		c = *strput++;
		if (c == tar_char)
			return (strput - 1);
		if (!c)
			return (NULL);
	}
}
