#include "shell.h"

/**
  * main - Creates a simple shell
  * @ac:The number of arguments
  * @av: The array of arguments
  * @env: The environmental arguments
  *
  * Return: Always (0) on Success
  */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	prompt(env);

	return (0);
}
