#include "main.h"

/**
* strArg_count - counts arguments
* @args: array of strings
* Return: argument num_count
*/

int strArg_count(char **args)
{
	register int j = 0;

	while (args[j])
		j++;
	return (j);
}

/**
* str_int - converts string to an integer
* @strput: string input
* Return: converted number
*/

int str_int(char *strput)
{
	register int j = 0;
	unsigned long conv_num = 0;

	while (strput[j])
	{
		if (strput[j] >= '0' && strput[j] <= '9')
			conv_num = conv_num * 10 + strput[j] - '0';
		else
			return (-1);
		j++;
	}
	if (conv_num > INT_MAX)
	{
		return (-1);
	}
	return (conv_num);
}
