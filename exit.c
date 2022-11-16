#include "shell.h"

/**
 * c_atoi - custom atoi converts string to int
 * @s: string
 * Return: number if success, -1 if string contains non-numbers
 */
int c_atoi(char *s)
{
	int n = 0;
	unsigned int num = 0;

	while (s[n] != '\0')
	{
		if (s[n] >= '0' && s[n] <= '9')
			num = num * 10 + (s[n] - '0');
		if (s[n] > '9' || s[n] < '0')
			return (-1);
		n++;
	}
	return (num);
}

/**
 *  __exit - frees user input and then exits main program with a value
 * @str: user's command into shell (e.g. "exit 99")
 * @env: bring in environmental variable to free at error
 * @num: bring in nth user command line input to print in error message
 * @command: bring in command to free
 * Return: 0 if success 2 if fail
 */
int __exit(char **str, list_e *env, int num, char **command)
{
	int val = 0;

	if (str[1] != NULL)
		val = c_atoi(str[1]);

	if (val == -1)
	{
		illegal_number(str[1], num, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str);
	free_linked_list(env);
	if (command != NULL)
		free_double_ptr(command);
	exit(val);
}
