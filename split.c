#include "monty.h"
/**
 * split - Splits a string into tokens based on a delimiter.
 * @str: The string to be split.
 * @delim: The delimiter used to split the string.
 * Return: An array of pointers to tokens.
 */
char **split(char *str, char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0, j;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_tous(taxi.stack, taxi.file);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	for (j = 0; j < i; j++)
	{
		if (tokens[j][0] == '#')
		{
			tokens[j] = NULL;
			break;
		}
	}

	return (tokens);
}
