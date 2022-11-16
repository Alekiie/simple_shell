#include "shell.h"

/**
  * env_linked_list - Creates a linked list from the environment variables
  * @env: environment variables
  *
  * Return: linked list
  */
list_e *env_linked_list(char **env)
{
	list_e *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}

/**
  * _env - Prints the environment variables
  * @str: users command to print
  * @env: environment variables
  *
  * Return: ALways (0) on Success
  */
int _env(char **str, list_e *env)
{
	free_double_ptr(str);
	print_list(env);
	return (0);
}
