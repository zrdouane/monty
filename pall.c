#include "monty.h"
/**
 * pall - Prints the elements of a stack.
 * @node: Pointer to a pointer to the top of the stack.
 * @compteur: Current line number.
 */
void pall(_stack_t **node, unsigned int compteur)
{
	_stack_t *head = *node;
	(void)compteur;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
