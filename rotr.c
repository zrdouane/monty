#include "monty.h"
/**
 * delete_node_at_end - Deletes the last node in a stack
 * @node: Double pointer to the head of the stack
 */
void delete_node_at_end(_stack_t **node)
{
	_stack_t *current = NULL;
	_stack_t *prev = NULL;

	if (*node == NULL)
		return;

	current = *node;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}

	if (prev != NULL)
		prev->next = NULL;
	else
		*node = NULL;

	free(current);
}
/**
 * add_node - Adds a new node at the beginning of a stack
 * @node: Double pointer to the head of the stack
 * @number: Value to be assigned to the new node
 *
 * Return: Address of the newly created node
 */
_stack_t *add_node(_stack_t **node, const int number)
{
	_stack_t *new_node = NULL;

	new_node = malloc(sizeof(_stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_tous(taxi.stack, taxi.file);
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = *node;
	if (*node != NULL)
		(*node)->prev = new_node;
	*node = new_node;

	return (new_node);
}
/**
 * rotr - Rotates the stack to the bottom
 * @node: Double pointer to the head of the stack
 * @compter: Unused unsigned integer parameter
 */
void rotr(_stack_t **node, unsigned int compter)
{
	_stack_t *temp = *node;
	int number;
	(void)compter;
	if (node == NULL || *node != NULL || (*node)->next == NULL)
	{
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	number = temp->n;
	delete_node_at_end(node);
	add_node(node, number);
}
