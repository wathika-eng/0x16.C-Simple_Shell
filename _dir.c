#include "main.h"

/**
 * cd_builtin - execute cd function
 * @exec: input exec
 * Return: 1 success 0 failure
 */

int cd_builtin(struct_var *exec)
{
	register unsigned int num_count = 0;
	bool change_possible = false;

	num_count = strArg_count(exec->args);
	if (num_count == 1)
		change_possible = cd_home(exec);
	else if (num_count == 2 && _strcmp(exec->args[1], "-") == 0)
		change_possible = cd_Previous(exec);
	else
		change_possible = cd_Custom(exec);
	if (change_possible)
		env_(exec);
	return (1);
}

/**
 * cd_home - change directory to home
 * @exec: input exec
 * Return: true success false failure
 */

bool cd_home(struct_var *exec)
{
	register int m;
	char *str, *ptr;

	m = s_node(exec->environ_, "HOME");
	if (m == -1)
	{
		return (true);
	}
	str = ret_node(exec->environ_, m);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	free(str);
	return (true);
}

/**
 * cd_Previous - change to previous directory
 * @exec: input exec
 * Return: true on success, false on failure
 */

bool cd_Previous(struct_var *exec)
{
	register int m;
	char *str, *ptr;
	char *current = NULL;

	current = getcwd(current, 0);
	m = s_node(exec->environ_, "OLDPWD");
	if (m == -1)
	{
		chdir(current);
		write(STDOUT_FILENO, current, _strlen(current));
		show_nline();
		return (true);																}
	str = ret_node(exec->environ_, m);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	write(STDOUT_FILENO, ptr, _strlen(ptr));
	show_nline();
	free(str);
	return (true);
}

/**
 * cd_Custom - change directory to custom path
 * @exec: input exec
 * Return: true success false failure
 */
bool cd_Custom(struct_var *exec)
{
	register int dir_change;

	dir_change = chdir(exec->args[1]);
	if (dir_change == -1)
	{
		errno = EBADCD;
		errors(exec);
		return (false);
	}
	return (true);
}
