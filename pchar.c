#include "monty.h"
/**
 * pchar - Prints the character representation of the top element of the stack
 * @node: Double pointer to the top of the stack
 * @compter: Line number where the pchar function is called
 */
void pchar(_stack_t **node, unsigned int compter)
{
	if (node == NULL || *node == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", compter);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}

	if ((*node)->n < 0 || (*node)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", compter);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*node)->n);
}
