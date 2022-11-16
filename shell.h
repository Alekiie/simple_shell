#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

#define END_OF_FILE -2
#define EXIT -3
/**
 * struct list - linked list for environmental variables
 * @str: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
		char *str;
		struct list *next;

} list_e;

/* function prototypes */
int prompt(char **env);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t get_line(char **str);
int t_strlen(char *str, int pos, char delm);
char *ignore_space(char *str);
char **_str_tok(char *str, char *delm);
char **c_str_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _cd(char **str, list_e *env, int num);
int built_in(char **token, list_e *env, int num, char **command);
void non_interactive(list_e *env);
char *_which(char *str, list_e *env);
int __exit(char **s, list_e *env, int num, char **command);
int _execve(char *argv[], list_e *env, int num);
void free_double_ptr(char **str);
void free_linked_list(list_e *list);
int _env(char **str, list_e *env);
char *get_env(char *str, list_e *env);
list_e *env_linked_list(char **env);
list_e *add_end_node(list_e **head, char *str);
size_t print_list(list_e *h);
int delete_nodeint_at_index(list_e **head, int index);
int _unsetenv(list_e **env, char **str);
int _setenv(list_e **env, char **str);
int find_env(list_e *env, char *str);
void not_found(char *str, int num, list_e *env);
void cant_cd_to(char *str, int c_n, list_e *env);
void illegal_number(char *str, int c_n, list_e *env);
char *int_to_string(int num);

#endif
