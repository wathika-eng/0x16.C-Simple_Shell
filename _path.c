#include "main.h"

/**
 * _path - searches for directory of command
 * @exec: input exec
 * Return: true or false
 */

bool _path(struct_var *exec)
{
	register int i;
	static char buffer[BUFSIZE];
	struct stat st;
	char *tokn, *copy, *delim = ":", *temp;
	bool inLoop = false;

	if (check_edge(exec))
		return (true);
	copy = _strdup(exec->path);
	tokn = _strtok(copy, delim);
	while (tokn)
	{
		temp = inLoop ? tokn - 2 : tokn;
		if (*temp == 0 && stat(exec->args[0], &st) == 0)
		{
			exec->f_path = exec->args[0];
			free(copy);
			return (true);
		}
		i = _strlen(tokn) + _strlen(exec->args[0]) + 2;
		_strcat(buffer, tokn);
		_strcat(buffer, "/");
		_strcat(buffer, exec->args[0]);
		null_byte(buffer, i - 1);
		if (stat(buffer, &st) == 0)
		{
			free(copy);
			exec->f_path = buffer;
			return (true);
		}
		null_byte(buffer, 0);
		tokn = _strtok(NULL, delim);
		inLoop = true;
	}
	exec->f_path = exec->args[0];
	free(copy);
	return (false);
}

/**
 * check_edge - check edge cases
 * @exec: input exec
 * Return: true or false
 */

bool check_edge(struct_var *exec)
{
	char *copy;
	struct stat st;

	copy = _strdup(exec->path);
	if (!copy)
	{
		exec->f_path = exec->args[0];
		free(copy);
		return (true);
	}
	if (*copy == ':' && stat(exec->args[0], &st) == 0)
	{
		exec->f_path = exec->args[0];
		free(copy);
		return (true);
	}
	free(copy);
	return (false);
}
