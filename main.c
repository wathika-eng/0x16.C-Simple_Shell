#include "main.h"

/**
 * shell - shell
 * @exec: input
 * Return: void
 */

void shell(struct_var *exec)
{
	while (true)
	{
		get_input(exec);
		if (_token(exec) == false)
			continue;
		if (get_builtins(exec) == true)
			continue;
		_path(exec);
		child_process(exec);
	}
}

/**
 * get_input - check user input
 * @exec: input
 * Return: void
 */

void get_input(struct_var *exec)
{
	register int i;
	size_t buffer = 0;
	char *ptr, *tmp;

	exec->args = NULL;
	exec->env_list = NULL;
	exec->num_count++;
	if (isatty(STDIN_FILENO))
		prompt_display();
	i = getline(&exec->buffer, &buffer, stdin);
	if (i == EOF)
	{
		_free(exec);
		if (isatty(STDIN_FILENO))
			show_nline();
		if (exec->error)
			exit(exec->error);
		exit(EXIT_SUCCESS);

	}
	ptr = _strchr(exec->buffer, '\n');
	tmp = _strchr(exec->buffer, '\t');
	if (ptr || tmp)
		null_byte(exec->buffer, i - 1);
	ignore_comments(exec->buffer);
}

/**
 * ignore_comments - ignore comments
 * @str: input
 * Return: length
 */

void ignore_comments(char *str)
{
	register int j = 0;
	bool num_one = false;

	while (str[j])
	{
		if (j == 0 && str[j] == '#')
		{
			null_byte(str, j);
			return;
		}
		if (num_one)
		{
			if (str[j] == '#' && str[j - 1] == ' ')
			{
				null_byte(str, j);
				return;
			}
		}
		j++;
		num_one = true;
	}
}

/**
 * child_process - create child process
 * @exec: input
 * Return: void
 */

void child_process(struct_var *exec)
{
	int status;
	pid_t pid_ = fork();

	make_array(exec);
	if (pid_ == -1)
	{
		perror("error\n");
		_free(exec);
		free_(exec->env_list);
		exit(1);
	}
	if (pid_ == 0)
	{
		if (execve(exec->f_path, exec->args, exec->env_list) == -1)
		{
			errors(exec);
			_free(exec);
			free_(exec->env_list);
			if (errno == ENOENT)
				exit(127);
			if (errno == EACCES)
				exit(126);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exec->error = WEXITSTATUS(status);
		free_args_buffer(exec);
		free_(exec->env_list);
	}
}

/**
 * make_array - convert items to array
 * @exec: input
 * Return: void
 */

void make_array(struct_var *exec)
{
	register int j = 0;
	size_t element_count = 0;
	char **env_list = NULL;
	struct_list *tmp = exec->environ_;

	element_count = num_elements(exec->environ_);
	env_list = malloc(sizeof(char *) * (element_count + 1));
	if (!env_list)
	{
		perror("Malloc failed\n");
		exit(1);
	}
	while (tmp)
	{
		env_list[j] = _strdup(tmp->str);
		tmp = tmp->nxt;
		j++;
	}
	env_list[j] = NULL;
	exec->env_list = env_list;
}
