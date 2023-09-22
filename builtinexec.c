#include "main.h"

/**
 * get_builtins - get inbuilt commands and execute
 * @exec: input
 * Return: true or false
 */

bool get_builtins(struct_var *exec)
{
	register int j = 0;
	builtin_struct get_inbuild[] = {
		{"exit", exit_},
		{"env", _env},
		{"cd", cd_builtin},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"help", help_fetch},
		{NULL, NULL}
	};

	while (get_inbuild[j].cmd)
	{
		if (_strcmp(exec->args[0], get_inbuild[j].cmd) == 0)
		{
			get_inbuild[j].func(exec);
			free_args_buffer(exec);
			return (true);
		}
		j++;
	}
	return (false);
}

/**
 * exit_ - exit the application
 * @exec: input
 * Return: 1 or 0
 */

int exit_(struct_var *exec)
{
	register int arg_count, exitStatus;

	arg_count = strArg_count(exec->args);
	if (arg_count == 1)
	{
		_free(exec);
		if (exec->error)
			exit(exec->error);
		exit(EXIT_SUCCESS);
	}
	else if (arg_count > 1)
	{
		exitStatus = str_int(exec->args[1]);
		if (exitStatus == -1)
		{
			errno = EILLEGAL;
			exec->error = 2;
			errors(exec);
			return (0);
		}
		_free(exec);
		exit(exitStatus);
	}
	return (1);
}
