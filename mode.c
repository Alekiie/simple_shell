#include "shell.h"

/**
* checkbuild - checks if the command is a buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*checkbuild(char **arv))(char **arv)
{
	int i, d;
	target T[] = {
		{"exit", exitt},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		d = 0;
		if (T[i].name[d] == arv[0][d])
		{
			for (d = 0; arv[0][d]; d++)
			{
				if (T[i].name[d] != arv[0][d])
					break;
			}
			if (!arv[0][d])
				return (T[i].func);
		}
	}
	return (0);
}
