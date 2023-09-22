#include "main.h"

/**
 * null_byte - appends null byte
 * @s: input string to append
 * @_index: _index to insert
 */

void null_byte(char *s, unsigned int _index)
{
	s[_index] = '\0';
}

/**
 * prompt_display - display prompt
 */

void prompt_display(void)
{
	write(STDERR_FILENO, "> ", 2);
}

/**
 * show_nline - display new line
 */

void show_nline(void)
{
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * signal_ - gets signal and reset signal
 * @sig: signal
 */

void signal_(int sig)
{
	(void)sig;
	signal(SIGINT, signal_);
	show_nline();
	prompt_display();
	fflush(stdout);
}
