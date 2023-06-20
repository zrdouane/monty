#include "monty.h"
/**
 * mod - Computes the modulo of the second top
 * element of the stack by the top element.
 * @node: Double pointer to the top of the stack.
 * @compter: Line number where the mod function is called.
 */
void mod(_stack_t **node, unsigned int compter)
{
	int modulo;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", compter);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}

	if ((*node)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", compter);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}

	modulo = (*node)->next->n % (*node)->n;
	pop(node, compter);
	(*node)->n = modulo;
}
