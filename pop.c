#include "monty.h"
/**
 * pop - Removes the top element from the stack.
 * @node: Pointer to a pointer to the top of the stack.
 * @compteur: Current line number.
 */
void pop(_stack_t **node, unsigned int compteur)
{
	_stack_t *courant = *node;

	if (node == NULL || *node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", compteur);
		exit(EXIT_FAILURE);
	}
	if (courant->next != NULL)
	{
		*node = courant->next;
		courant->next->prev = NULL;
	}
	else
	{
		*node = NULL;
	}

	free(courant);
}
