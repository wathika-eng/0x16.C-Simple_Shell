#include "main.h"

/**
 * env_var - retrieves env variable that matches input string
 * @input: input string
 * @local_var: local environmental variables
 * Return: string of env variable
 */

char *env_var(char *input, char **local_var)
{
	register int m = 0;
	char *tokn, *n;

	while (local_var[m])
	{
		tokn = _strtok(local_var[m], "=");
		if (_strcmp(tokn, input) == 0)
		{
			n = _strtok(NULL, "=");
			return (n);
		}
		m++;
	}
	return (NULL);
}
