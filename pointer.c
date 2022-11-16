#include "shell.h"

/**
  * free_double_ptr - frees malloced arrays
  * @str: array of strings
  *
  * Return: Nothing
  */
void free_double_ptr(char **str)
{
	int a = 0;

	while (str[a] != NULL)
	{
		free(str[a]);
		a++;
	}
	free(str);
}
