#include "shell.h"


/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **splitstring(char *str, const char *delim)
{
	int i, ln;
	char **array;
	char *all;
	char *cpy;

	cpy = malloc(_strlen(str) + 1);
	if (cpy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';

	all = strtok(cpy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(all);

	i = 1;
	ln = 3;
	while (all)
	{
		all = strtok(NULL, delim);
		array = _realloc(array, (sizeof(char *) * (ln - 1)), (sizeof(char *) * ln));
		array[i] = _strdup(all);
		i++;
		ln++;
	}
	free(cpy);
	return (array);
}

/**
 * execute - executes a command
 * @argv: array of arguments
 */

void execute(char **argv)
{

	int d, status;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(_getenv("_"));
	}
	if (d == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @initial_size: initial size of previous pointer
 * @final_size: final size for our pointer
 * Return: final resized Pointer
 */

void *_realloc(void *ptr, unsigned int initial_size, unsigned int final_size)
{
	char *final;
	char *initial;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(final_size));

	if (final_size == initial_size)
		return (ptr);

	if (final_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	final = malloc(final_size);
	initial = ptr;
	if (final == NULL)
		return (NULL);

	if (final_size > initial_size)
	{
		for (i = 0; i < initial_size; i++)
			final[i] = initial[i];
		free(ptr);
		for (i = initial_size; i < final_size; i++)
			final[i] = '\0';
	}
	if (final_size < initial_size)
	{
		for (i = 0; i < final_size; i++)
			final[i] = initial[i];
		free(ptr);
	}
	return (final);
}

/**
 * freearv - frees the array of pointers arv
 *@arv: array of pointers
 */

void freearv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
