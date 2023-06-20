#include "monty.h"
/**
 * ft_div - Divides the second element of the stack by the top element.
 * @node: Pointer to a pointer to the top of the stack.
 * @compteur: Current line number.
 */
void ft_div(_stack_t **node, unsigned int compteur)
{
	int devides;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", compteur);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}
	if ((*node)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", compteur);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}

	devides = (*node)->next->n / (*node)->n;
	pop(node, compteur);
	(*node)->n = devides;
}
