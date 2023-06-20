#include "monty.h"
/**
 * add_node_end - Adds a new node at the end of a stack
 * @head: Double pointer to the head of the stack
 * @n: Value to be assigned to the new node
 *
 * Return: Address of the newly created node
 */
_stack_t *add_node_end(_stack_t **head, const int n)
{
	_stack_t *new_node = NULL;
	_stack_t *current = NULL;

	new_node = malloc(sizeof(_stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_tous(taxi.stack, taxi.file);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = new_node;

	return (new_node);
}
/**
 * rotl - Rotates the stack to the top
 * @node: Double pointer to the head of the stack
 * @compter: Unused unsigned integer parameter
 *
 */
void rotl(_stack_t **node, unsigned int compter)
{
	int n;

	(void)compter;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		return;

	n = (*node)->n;
	pop(node, compter);
	add_node_end(node, n);
}
