#include "main.h"

/**
 * s_node - searches linked list for string
 * @head: pointer to head of list
 * @str: input string
 * Return: _index of node
 */

int s_node(struct_list *head, char *str)
{
	register int i = 0, _index = 0, j;
	struct_list *cur;
	char *tmp, *ptr;

	cur = head;
	while (cur)
	{
		ptr = _strchr(cur->str, '=');
		i = ptr - cur->str;
		tmp = malloc(sizeof(char) * i + 1);
		for (j = 0; j < i; j++)
			tmp[j] = cur->str[j];
		tmp[j] = '\0';
		if (_strcmp(str, tmp) == 0)
		{
			free(tmp);
			return (_index);
		}
		_index++;
		cur = cur->nxt;
		free(tmp);
	}
	return (-1);
}

/**
 * generate_list - generates a linked list of env variables
 * @array: input array of strings
 * Return: head of linked list
 */

struct_list *generate_list(char **array)
{
	register int m = 0;
	struct_list *head;

	head = NULL;
	while (array[m])
	{
		node_end(&head, array[m]);
		m++;
	}
	return (head);
}

/**
 * add_node - adds node at _index
 * @head: pointer to head
 * @_index: _index
 * @str: string
 * Return: address of node
 */

struct_list *add_node(struct_list **head, int _index, char *str)
{
	register int j = 0;
	struct_list *new_addednode, *cur;
	char *new_addedstr;

	cur = *head;
	if (!str)
		return (NULL);
	new_addednode  = malloc(sizeof(struct_list));
	if (!new_addednode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	new_addedstr = _strdup(str);
	if (!new_addedstr)
	{
		free(new_addednode);
		perror("Malloc failed\n");
		exit(errno);
	}
	new_addednode->str = new_addedstr;
	new_addednode->nxt = NULL;

	while (j < _index - 1)
	{
		if (cur->nxt == NULL)
		{
			free(new_addednode);
			return (NULL);
		}
		cur = cur->nxt;
		j++;
	}
	new_addednode->nxt = cur->nxt;
	cur->nxt = new_addednode;
	return (new_addednode);
}

/**
 * ret_node - returns the nth node
 * @head: pointer to head of list
 * @_index: _index of value
 * Return: address of node
 */

char *ret_node(struct_list *head, unsigned int _index)
{
	register unsigned int num_count = 0;
	struct_list *cur;
	char *ptr;

	cur = head;
	while (cur)
	{
		if (num_count == _index)
		{
			ptr = _strdup(cur->str);
			return (ptr);
		}
		num_count++;
		cur = cur->nxt;
	}
	return (NULL);
}
