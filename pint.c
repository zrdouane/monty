#include "monty.h"
/**
 * pint - Prints the value of the top element in the stack.
 * @node: Pointer to a pointer to the top of the stack.
 * @compteur: Current line number.
 */
void pint(_stack_t **node, unsigned int compteur)
{
	if (*node == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", compteur);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*node)->n);
}
