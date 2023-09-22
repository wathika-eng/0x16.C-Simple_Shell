#include "main.h"

/**
 * h_cd - instructions on how to exit
 * @exec: input
 * Return: 1
 */

int h_cd(struct_var *exec)
{
	char buf[194] = "cd: cd [dest]\n\t";
	char *string0 = "Change directory to target dest.\n\t";
	char *string1 = "If [dest] is ommitted, user will be taken to home.\n\t";
	char *string2 = "If \"-\" is used as second argument, user will be taken to ";
	char *string3 = "last directory.\n";

	(void)exec;
	_strcat(buf, string0);
	_strcat(buf, string1);
	_strcat(buf, string2);
	_strcat(buf, string3);
	write(STDOUT_FILENO, buf, _strlen(buf));
	return (1);
}

/**
 * h_setenv - instructions on how to exit
 * @exec: exec
 * Return: 1 on success
 */

int h_setenv(struct_var *exec)
{
	char str[186] = "setenv: setenv [var] [value]\n\t";
	char *string2 = "Set variable in the environ_.\n\n\t";
	char *string3 = "Creates a variable with [value]. ";
	char *string4 = "If the [var] already exists in the environ_, ";
	char *string5 = "the value is updated.\n";

	(void)exec;
	_strcat(str, string2);
	_strcat(str, string3);
	_strcat(str, string4);
	_strcat(str, string5);
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * h_unsetenv - unset environment
 * @exec: input
 * Return: 1
 */

int h_unsetenv(struct_var *exec)
{
	char buf[116] = "unsetenv: unsetenv [var]\n\t";
	char *string2 = "Unset a variable in the environment.\n\n\t";
	char *string3 = "[var] is an existing variable in the environment.\n";

	(void)exec;
	_strcat(buf, string2);
	_strcat(buf, string3);
	write(STDOUT_FILENO, buf, _strlen(buf));
	return (1);
}

/**
 * h_help - help support
 * @exec: input
 * Return: On success 1
 */

int h_help(struct_var *exec)
{
	char buf[129] = "help: help [built-in]\n\t";
	char *string2 = "Display information about builtin commands.\n\n\t";
	char *string3 = "If [built-in] is not specified, print list of built-ins.\n";

	(void)exec;
	_strcat(buf, string2);
	_strcat(buf, string3);
	write(STDOUT_FILENO, buf, _strlen(buf));
	return (1);
}
