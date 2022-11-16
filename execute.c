#include "shell.h"

/**
  * c_exit - frees a users command and linked list before exiting
  * @str: The user input
  * @env: The environment linked list
  *
  * Return - Nothing
  */
void c_exit(char **str, list_e *env)
{
	free_double_ptr(str);
	free_linked_list(env);
	_exit(0);
}

/**
  * _execve - Executes command the user typed into the shell
  * @s: The command typed in
  * @env: The environment variable
  * @num: nth user command
  *
  * Return: Always (0) on Success
  */
int _execve(char **s, list_e *env, int num)
{
	char *h;
	int status = 0, t = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		h = s[0];
		t = 1;
	}
	else
		h = _which(s[0], env);
	if (access(h, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_double_ptr(s);
		return (120);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(h, s, NULL) == -1)
			{
				not_found(s[0], num, env);
				c_exit(s, env);
			}
		}
		else
		{
			wait(&status);
			free_double_ptr(s);
			if (t == 0)
				free(h);
		}
	}
	return (0);
}
