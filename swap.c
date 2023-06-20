#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @node: Pointer to a pointer to the top of the stack.
 * @compteur: Current line number.
 */
void swap(_stack_t **node, unsigned int compteur)
{
	int temp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", compteur);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}

	temp = (*node)->n;
	(*node)->n = (*node)->next->n;
	(*node)->next->n = temp;
}
