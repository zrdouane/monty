#include "monty.h"
/**
 * free_stack - Frees the memory allocated for a stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(_stack_t *stack)
{
	_stack_t *courant = stack;

	if (courant == NULL)
	{
		return;
	}
	while (courant)
	{
		courant = courant->next;
		free(stack);
		stack = courant;
	}
}
/**
 * is_number - Checks if a string represents a valid number.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int is_number(const char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
/**
 * free_tous - Frees memory associated with a stack and closes a file.
 * @node: Pointer to the top of the stack.
 * @lime: Pointer to the file to be closed.
 */
void free_tous(_stack_t *node, FILE *lime)
{
	free_stack(node);
	fclose(lime);
}
/**
 * push - Adds a new node to a stack.
 * @node: Pointer to a pointer to the top of the stack.
 * @compteur: Current line number.
 */
void push(_stack_t **node, unsigned int compteur)
{
	int num;
	_stack_t *new_node = NULL;
	/*This code checks if the first argument to the push function is a number. */
	if (is_number(taxi.line[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", compteur);
		exit(EXIT_FAILURE);
	}

	num = atoi(taxi.line[1]);

	new_node = malloc(sizeof(_stack_t));
	if (new_node == NULL)
	{
		write(2, "allocation failed\n", 20);
		free_tous(*node, taxi.file);
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*node != NULL)
	{
		new_node->next = *node;
		(*node)->prev = new_node;
	}
	*node = new_node;
}
