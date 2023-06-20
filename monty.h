#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} _stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(_stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct taxi_s - a struct that handle global var.
 * @file : Pointer to a FILE object for file operations.
 * @line : line to read from file.
 * @line_number : Current line number.
 * @stack : pointer to a stack object.
*/
typedef struct taxi_s
{
	FILE *file;
	char **line;
	int line_number;
	_stack_t *stack;
} taxi_t;

extern taxi_t taxi;
/* push.c */
int is_number(const char *string);
void free_tous(_stack_t *node, FILE *lime);
void free_stack(_stack_t *stack);
void push(_stack_t **node, unsigned int compteur);

/* pall.c */
void pall(_stack_t **node, unsigned int compteur);

/* split.c */
char **split(char *str, char *delim);

/* opcode.c */
void (*opc(char *s))(_stack_t **stack, unsigned int line_number);

/* pint.c */
void pint(_stack_t **node, unsigned int compteur);

/* pop.c */
void pop(_stack_t **node, unsigned int compteur);

/* swap.c */
void swap(_stack_t **node, unsigned int compteur);

/* add.c */
void add(_stack_t **node, unsigned int compteur);

/* nop.c */
void nop(_stack_t **node, unsigned int compteur);

/* sub.c */
void sub(_stack_t **node, unsigned int compteur);

/* div.c */
void ft_div(_stack_t **node, unsigned int compter);

/* mul.c */
void mul(_stack_t **node, unsigned int compter);

/* mod.c */
void mod(_stack_t **node, unsigned int compter);

/* comments.c */
void comments(_stack_t **node, unsigned int compteur);

/* pchar.c */
void pchar(_stack_t **node, unsigned int compter);

/* pstr.c */
void pstr(_stack_t **node, unsigned int compter);

/* rotl.c */
void rotl(_stack_t **node, unsigned int compter);
_stack_t *rotate_stack(_stack_t **node, unsigned int compter);

/* rotr.c */
void rotr(_stack_t **node, unsigned int compter);
_stack_t *add_node(_stack_t **node, const int number);
void delete_node_at_end(_stack_t **node);
#endif /* MONTY_H */
