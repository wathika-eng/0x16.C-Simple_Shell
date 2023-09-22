#include "main.h"

struct_var *struct_mcall(struct_var *exec)
{
	exec->environ_ = generate_list(environ);
	exec->env_list = NULL;
	exec->args = NULL;
	exec->buffer = NULL;
	exec->path = env_var("PATH", environ);
	exec->f_path = NULL;
	exec->num_count = 0;
	exec->shell_identity = NULL;
	exec->error = 0;
	return (exec);
}

/**
 * main - program entry point
 * @argc: argument, not used
 * @vectr: argument vector
 *
 * Return: 0 on success
*/

int main(int argc, char **vectr)
{
	struct_var exec;

	(void)argc; /* not used */
	signal(SIGINT, signal_);
	struct_mcall(&exec);
	exec.shell_identity = vectr[0];
	shell(&exec);
	return (0);
}
