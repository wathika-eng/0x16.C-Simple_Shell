#include "main.h"

/**
 * help_fetch - fetch instructions on use of builtin commands
 * @exec: exec
 * Return: 1
 */

int help_fetch(struct_var *exec)
{
	builtin_struct help_arr[] = {
		{"exit", h_exit},
		{"env", h_env},
		{"cd", h_cd},
		{"setenv", h_setenv},
		{"unsetenv", h_unsetenv},
		{"help", h_help},
		{NULL, NULL}
	};
	register int j = 0, i = 1, arg_count = strArg_count(exec->args);
	bool command_found = false;

	if (arg_count == 1)
		return (help_options());
	while (i < arg_count)
	{
		j = 0;
		while (help_arr[j].cmd)
		{
			if (_strcmp(exec->args[i], help_arr[j].cmd) == 0)
			{
				command_found = true;
				help_arr[i].func(exec);
				break;
			}
			j++;
		}
		i++;
	}
	if (command_found == false)
	{
		errno = ENOBUILTIN;
		errors(exec);
	}
	return (1);
}

/**
 * help_options - give help options
 * Return: 1
 */

int help_options(void)
{
	char str[81] = "Type help\n\nbuilt-ins:";
	char *c = "\n\n\thelp\n\tenv\n\tcd\n\tsetenv\n\tunsetenv\n\texit\n";

	_strcat(str, c);
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}


/**
 * h_exit - exi shell instructions
 * @exec: exec to provide instructions
 * Return: 1
 */

int h_exit(struct_var *exec)
{
	char str[82] = "exit: exit [n]\n\tExit shell.\n\n\t";
	char *str2 = "Exit with status of n, if n is omitted, 0.\n";

	(void)exec;
	_strcat(str, str2);
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * h_env - environment instructions
 * @exec: input
 * Return: 1
 */

int h_env(struct_var *exec)
{
	char str[] = "env: env\n\tPrint the environment.\n";

	(void)exec;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}
