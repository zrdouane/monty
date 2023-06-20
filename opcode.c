#include "monty.h"
/**
 * opc - Returns a function pointer based on the given opcode string.
 * @s: The opcode string.
 *
 * Return: A function pointer.
 */
void (*opc(char *s))(_stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", ft_div},
		{"mul", mul},
		{"mod", mod},
		{"#", comments},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
		};

	int i;

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", taxi.line_number, s);
	free_tous(taxi.stack, taxi.file);
	exit(EXIT_FAILURE);
}
