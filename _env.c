#include "main.h"

/**
 * _env - prints the enviroment
 * @exec: input
 * Return: Always 1
 */
int _env(struct_var *exec)
{
		print_elements(exec->environ_);
		return (1);
}

/**
 * set_env - adds env variable
 * @exec: input exec
 * Return: 1
 */

int set_env(struct_var *exec)
{
	register int _index, n;
	static char buffer[BUFSIZE];

	if (strArg_count(exec->args) != 3)
	{
		errno = EWSIZE;
		errors(exec);
		return (1);
	}
	n = _strlen(exec->args[1]) + _strlen(exec->args[2]) + 2;
	_strcat(buffer, exec->args[1]);
	_strcat(buffer, "=");
	_strcat(buffer, exec->args[2]);
	null_byte(buffer, n - 1);
	_index = s_node(exec->environ_, exec->args[1]);
	if (_index == -1)
	{
		node_end(&exec->environ_, buffer);
		null_byte(buffer, 0);
		return (1);
	}
	del_node(&exec->environ_, _index);
	add_node(&exec->environ_, _index, buffer);
	null_byte(buffer, 0);
	return (1);
}

/**
 * unset_env - deletes existing env variable
 * @exec: input exec
 * Return: Always 1
 */

int unset_env(struct_var *exec)
{
	register int n, j = 1;
	bool match = false;

	while (exec->args[j])
	{
		if (check_alpha(exec->args[j][0]) || exec->args[j][0] == '_')
		{
			n = s_node(exec->environ_, exec->args[j]);
			if (n > -1)
			{
				del_node(&exec->environ_, n);
				match = true;
			}
		}
		j++;
	}
	if (match == false)
	{
		errno = ENOSTRING;
		errors(exec);
	}
	return (1);
}

/**
 * check_alpha - checks if c is an alphabetic character
 * @c: character to be checked
 * Return: 1 if c is a letter or 0
 */

int check_alpha(int c)
{
	if (c > 64 && c < 91)
		return (1);
	else if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}
