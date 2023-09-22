#include "main.h"

/**
 * env_ - modify enviroment variables
 * @exec: input exec
 * Return: true success false failure
 */

bool env_(struct_var *exec)
{
	register int p;

	p = dir_update(exec);
	dir_cur(exec, p);
	return (true);
}

/**
 * dir_update - updates OLDPWD to current
 * @exec: input exec
 * Return: _index in linked list of PWD
 *			-1 for failure
 */

int dir_update(struct_var *exec)
{
	register int pwd_num = 0, _index = 0;
	static char old[BUFSIZE];
	char *current = NULL;

	_strcat(old, "OLD");
	pwd_num = s_node(exec->environ_, "PWD");
	if (pwd_num == -1)
	{
		return (-1);
	}
	current = ret_node(exec->environ_, pwd_num);
	_strcat(old, current);
	null_byte(old, _strlen(current) + 4);
	free(current);
	_index = s_node(exec->environ_, "OLDPWD");
	if (_index == -1)
	{
		return (-1);
	}
	del_node(&exec->environ_, _index);
	add_node(&exec->environ_, _index, old);
	null_byte(old, 0);
	return (pwd_num);
}

/**
 * dir_cur - updates PWD current directory
 * @exec: input exec
 * @_index: _index in linked list of where to insert PWD enviroment var
 * Return: true on success, false on failure
 */
bool dir_cur(struct_var *exec, int _index)
{
	static char tmp[BUFSIZE], cwd[BUFSIZE];

	getcwd(tmp, BUFSIZE);
	_strcat(cwd, "PWD=");
	_strcat(cwd, tmp);
	if (_index > -1)
	{
		del_node(&exec->environ_, _index);
		add_node(&exec->environ_, _index, cwd);
	} else
		add_node(&exec->environ_, 0, cwd);
	null_byte(tmp, 0);
	null_byte(cwd, 0);
	return (true);
}
