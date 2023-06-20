#include "monty.h"
/**
 * pstr - Prints the characters represented by the integer values in the stack
 * @node: Double pointer to the stack
 * @compter: Unused unsigned integer parameter
 */
void pstr(_stack_t **node, unsigned int compter)
{
	_stack_t *temp = *node;

	(void)compter;

	while (temp != NULL && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
		fprintf(stdout, "\n");
}
