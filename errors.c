#include "main.h"

/**
 * errors - prints error message
 * @exec: exec
 */

void errors(struct_var *exec)
{
	register int i;
	static char error[BUFSIZE];
	char *ptr, *alp;

	alp = int_to_string(exec->num_count);
	_strcat(error, exec->shell_identity);
	_strcat(error, ": ");
	_strcat(error, alp);
	_strcat(error, ": ");
	_strcat(error, exec->args[0]);
	_strcat(error, err_message());
	if (exec->args[1])
	{
		if (errno != EBADCD)
			_strcat(error, ": ");
		_strcat(error, exec->args[1]);
	}
	_strcat(error, "\n");
	ptr = _strchr(error, '\n');
	i = ptr - error;
	write(STDERR_FILENO, error, i + 1);
	free(alp);
	null_byte(error, 0);
}

/**
 * err_message - matches error to string
 * Return: string of error message
 */

char *err_message(void)
{
	char *str;

	switch (errno)
	{
		case EBADCD:
			str = ": No such file or directory ";
			break;
		case ENOENT:
			str = ": command not found";
			break;
		case ENOSTRING:
			str = ": bad variable name";
			break;
		case EILLEGAL:
			str = ": Illegal number";
			break;
		case EWSIZE:
			str = ": invalid number of arguments";
			break;
		case ENOBUILTIN:
			str = ": type help for a list of built-ins";
			break;
		case EACCES:
			str = ": Permission denied";
			break;
		default:
			str = ": no error number assigned";
	}
	return (str);
}

/**
 * _digits - num_count number of digits in a number
 * @num: input number
 * Return: number of digits
 */
unsigned int _digits(int num)
{
	register int symbols = 0;

	while (num > 0)
	{
		symbols++;
		num /= 10;
	}
	return (symbols);
}

/**
 * int_to_string - integer to string
 * @num: input integer
 * Return: string type
 */

char *int_to_string(unsigned int num)
{
	register int numbers = 0;
	char *str;

	numbers += _digits(num);
	str = malloc(sizeof(char) * (numbers + 1));
	if (!str)
	{
		perror("Malloc: failed\n");
		exit(errno);
	}
	null_byte(str, numbers);
	while (num > 0)
	{
		str[numbers - 1] = num % 10 + '0';
		num = num / 10;
		numbers--;
	}
	return (str);
}
