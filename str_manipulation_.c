#include "main.h"

/**
 * _token - tokenize strings and adds them to array
 * @exec: input
 * Return: true
 */

bool _token(struct_var *exec)
{
	register unsigned int j = 0;
	char *tok, *s_copy;

	if (words_num(exec->buffer) == 0)
	{
		exec->args = NULL;
		free(exec->buffer);
		return (false);
	}
	exec->args = malloc((words_num(exec->buffer) + 1) * sizeof(char *));
	s_copy = _strdup(exec->buffer);
	tok = _strtok(s_copy, " ");
	while (tok)
	{
		exec->args[j] = _strdup(tok);
		tok = _strtok(NULL, " ");
		j++;
	}
	exec->args[j] = NULL;
	free(s_copy);
	return (true);
}

/**
 * words_num - counts words in a string
 * @str: string input
 * Return: word num_count
 */

unsigned int words_num(char *str)
{
	register int str_words = 0;
	bool word = false;

	while (*str)
	{
		if (space(*str) && word)
			word = false;
		else if (!space(*str) && !word)
		{
			word = true;
			str_words++;
		}
		str++;
	}
	return (str_words);
}

/**
 * space - checks for space in string
 * @a: character input
 * Return: true or false
 */

bool space(char a)
{
	return (a == ' ');
}
