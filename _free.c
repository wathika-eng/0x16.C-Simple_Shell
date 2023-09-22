#include "main.h"

/**
 * _free - frees struct_var members
 * @exec: input exec
 */

void _free(struct_var *exec)
{
	if (exec->environ_)
		free_l(exec->environ_);
	if (exec->args)
		free_(exec->args);
	if (exec->buffer)
		free(exec->buffer);
}

/**
 * free_args_buffer - frees args and buffer
 * @exec: input exec
 */

void free_args_buffer(struct_var *exec)
{
	free_(exec->args);
	free(exec->buffer);
}

/**
 * free_l - frees linked list
 * @head: pointer to head of list
 */

void free_l(struct_list *head)
{
	struct_list *cur;
	struct_list *tmp;

	if (!head)
		return;
	cur = head;
	while (cur)
	{
		tmp = cur;
		cur = tmp->nxt;
		free(tmp->str);
		free(tmp);
	}
	head = NULL;
}

/**
 * free_ - function that frees arg
 * @args: array of char
 */

void free_(char **args)
{
	register unsigned int j = 0;

	while (args[j])
		free(args[j++]);
	free(args);
}
