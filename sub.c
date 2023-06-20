#include "monty.h"
/**
 * sub - Subtracts the top element of the stack from the second element.
 * @node: Pointer to a pointer to the top of the stack.
 * @compteur: Current line number.
 */
void sub(_stack_t **node, unsigned int compteur)
{
	int subtract;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", compteur);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}
	subtract = (*node)->next->n - (*node)->n;
	pop(node, compteur);
	(*node)->n = subtract;
}
