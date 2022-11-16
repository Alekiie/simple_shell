#include "shell.h"

/**
 * rev_string - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, i, k;
	char *str, tmp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (k = i + 1; k > 0; k--)
		{
			tmp = *(str + k);
			*(str + k) = *(str + (k - 1));
			*(str + (k - 1)) = tmp;
		}
	}
}
