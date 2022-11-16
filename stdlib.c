#include "shell.h"

/**
 * get_len - Get the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */
int get_len(int n)
{
	unsigned int num;
	int len = 1;

	if (n < 0)
	{
		len++;
		num = n * -1;
	}
	else
	{
		num = n;
	}
	while (num > 9)
	{
		len++;
		num = num / 10;
	}

	return (len);
}
/**
 * aux_itoa - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *aux_itoa(int n)
{
	unsigned int num1;
	int length = get_len(n);
	char *buff;

	buff = malloc(sizeof(char) * (length + 1));
	if (buff == 0)
		return (NULL);

	*(buff + length) = '\0';

	if (n < 0)
	{
		num1 = n * -1;
		buff[0] = '-';
	}
	else
	{
		num1 = n;
	}

	length--;
	do {
		*(buff + length) = (num1 % 10) + '0';
		num1 = num1 / 10;
		length--;
	}
	while (num1 > 0)
		;
	return (buff);
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, ui = 0, pn = 1, n = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				n *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		ui = ui + ((*(s + i) - 48) * n);
		n /= 10;
	}
	return (ui * pn);
}
