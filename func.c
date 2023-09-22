#include "main.h"

/**
 * add_new_node - adds a new node
 * @head: reference to head
 * @str: string to be added
 * Return: address of head;
 */

struct_list *add_new_node(struct_list **head, char *str)
{
	struct_list *new_addednode;
	char *new_addedstr;

	if (!str)
		return (NULL);
	new_addednode = malloc(sizeof(struct_list));
	if (!new_addednode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	new_addedstr = _strdup(str);
	if (!new_addedstr)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	new_addednode->str = new_addedstr;
	new_addednode->nxt = *head;
	*head = new_addednode;
	return (*head);
}

/**
 * node_end - adds a new node at the end
 * @head: head of list
 * @str: string to be added
 * Return: address of new end node
 */

struct_list *node_end(struct_list **head, char *str)
{
	struct_list *new_addednode;
	struct_list *last = *head;
	char *new_addedstr;

	if (!str)
		return (NULL);
	new_addednode = malloc(sizeof(struct_list));
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
	if (!*head)
	{
		*head = new_addednode;
		return (new_addednode);
	}
	while (last->nxt)
		last = last->nxt;
	last->nxt = new_addednode;
	return (last);
}

/**
 * print_elements - prints all elements
 * @head: pointer to head
 * Return: number of elements
 */

size_t print_elements(const struct_list *head)
{
	register int i = 0;

	while (head)
	{
		write(STDOUT_FILENO, head->str, _strlen(head->str));
		show_nline();
		head = head->nxt;
		i++;
	}
	return (i);
}

/**
 * del_node - deletes the node at _index
 * _index of a struct_list
 * @head: pointer to head of list
 * @_index: _index of node to be deleted
 * Return: 1 success -1 fail
 */

int del_node(struct_list **head, unsigned int _index)
{
	struct_list *cur;
	struct_list *next;

	register unsigned int j;

	if (!head || !(*head))
		return (-1);
	cur = *head;
	if (!_index)
	{
		*head = cur->nxt;
		free(cur);
		return (1);
	}
	for (j = 0; cur && j < _index - 1; j++)
		cur = cur->nxt;
	if (!cur || !(cur->nxt))
		return (-1);
	next = cur->nxt->nxt;
	free(cur->nxt->str);
	free(cur->nxt);
	cur->nxt = next;
	return (1);
}

/**
 * num_elements - returns the number of elements in a linked list
 * @head: head of linked list
 * Return: number of elements in list_t
 */

size_t num_elements(struct_list *head)
{
	register unsigned int i = 0;

	while (head)
	{
		head = head->nxt;
		i++;
	}
	return (i);
}
