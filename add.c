#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @node: Pointer to a pointer to the top of the stack.
 * @compteur: Current line number.
 */
void add(_stack_t **node, unsigned int compteur)
{
	int somme;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", compteur);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}

	somme = (*node)->n + (*node)->next->n;
	pop(node, compteur);
	(*node)->n = somme;
}
