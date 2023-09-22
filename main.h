#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 256
#define ENOSTRING 1106
#define EILLEGAL 227
#define EWSIZE 410
#define ENOBUILTIN 415
#define EBADCD 726

extern char **environ;

/**
 * struct l_list - data structure
 * @str: string path
 * @nxt: next node
 */

typedef struct l_list
{
	char *str;
	struct l_list *nxt;
} struct_list;

/**
 * struct var - values for structure
 * @environ_: local environ_ variables
 * @env_list: array of environ_ variables
 * @args: arguments
 * @buffer: buffer input
 * @path: path variable
 * @f_path: path variable
 * @shell_identity: name shell
 * @num_count: number of lines
 * @error: error status
 */
typedef struct var
{
	struct_list *environ_;
	char **env_list;
	char **args;
	char *buffer;
	char *path;
	char *f_path;
	char *shell_identity;
	unsigned int num_count;
	int error;
} struct_var;

/**
 * struct inbuild - the shell
 * @cmd: input
 * @func: output
 */

typedef struct inbuild
{
	char *cmd;
	int (*func)(struct_var *exec);
} builtin_struct;


struct_var *struct_mcall(struct_var *exec);


bool get_builtins(struct_var *exec);
int exit_(struct_var *exec);


int cd_builtin(struct_var *);
bool cd_home(struct_var *exec);
bool cd_Previous(struct_var *exec);
bool cd_Custom(struct_var *exec);
bool env_(struct_var *exec);


int dir_update(struct_var *exec);
bool dir_cur(struct_var *exec, int _index);

int _env(struct_var *exec);
int set_env(struct_var *exec);
int unset_env(struct_var *exec);
int check_alpha(int c);

int help_fetch(struct_var *exec);
int help_options(void);
int h_exit(struct_var *exec);
int h_env(struct_var *exec);

int h_cd(struct_var *biuld);
int h_setenv(struct_var *exec);
int h_unsetenv(struct_var *exec);
int h_help(struct_var *exec);

int strArg_count(char **args);
int str_int(char *strput);

void shell(struct_var *exec);
void get_input(struct_var *exec);
void child_process(struct_var *exec);
void ignore_comments(char *str);
void make_array(struct_var *exec);

char *env_var(char *input, char **environ);

void errors(struct_var *exec);
unsigned int _digits(int num);
char *int_to_string(unsigned int num);
char *err_message();

void null_byte(char *s, unsigned int _index);
void prompt_display(void);
void show_nline(void);
void signal_(int sigint);

bool _path(struct_var *);
bool check_edge(struct_var *exec);


bool _token(struct_var *exec);
unsigned int words_num(char *s);
bool space(char c);

int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *put1, char *put2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

char *_strtok(char *str, char *delim);
int _strcspn(char *string, char *chars);
char *_strchr(char *strput, char tar_char);

struct_list *add_new_node(struct_list **head, char *str);
struct_list *node_end(struct_list **head, char *str);
size_t print_elements(const struct_list *head);
int s_node(struct_list *head, char *str);
size_t num_elements(struct_list *head);

int del_node(struct_list **head, unsigned int _index);
struct_list *generate_list(char **array);
struct_list *add_node(struct_list **head, int _index, char *str);
char *ret_node(struct_list *head, unsigned int _index);

void *_mem(void *ptr, unsigned int prev_size, unsigned int cur_size);
char *_fillmem(char *dest, char *src, unsigned int num_bytes);

void _free(struct_var *exec);
void free_args_buffer(struct_var *exec);
void free_(char **args);
void free_l(struct_list *head);

#endif
