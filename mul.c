#include "monty.h"
/**
 * mul - Multiplies the top element of the stack by the second element.
 * @node: Pointer to a pointer to the top of the stack.
 * @compter: Current line number.
 */
void mul(_stack_t **node, unsigned int compter)
{
	int multiples;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", compter);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}
	multiples = (*node)->n * (*node)->next->n;
	pop(node, compter);
	(*node)->n = multiples;
}
