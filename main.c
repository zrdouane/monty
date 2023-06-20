#include "monty.h"
taxi_t taxi = {NULL, NULL, 0, NULL};
/**
 * main - Entry point for the program.
 * @argc: The number of command line arguments.
 * @argv: An array of strings containing the command line arguments.
 *
 * Return: EXIT_SUCCESS if successfully, otherwise EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t lenght = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	taxi.file = fopen(argv[1], "r");
	taxi.file = taxi.file;
	if (taxi.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &lenght, taxi.file)) != -1)
	{
		taxi.line_number++;

		taxi.line = split(line, " \n\t\r");
		if (taxi.line != NULL && taxi.line[0] != NULL)
			opc(taxi.line[0])(&taxi.stack, taxi.line_number);

		free(taxi.line);
	}
	free(line);
	free_tous(taxi.stack, taxi.file);
	return (EXIT_SUCCESS);
}
