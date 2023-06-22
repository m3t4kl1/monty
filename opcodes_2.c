#include "monty.h"
#include <stdlib.h>

/**
 * pint - prints first node of linked list
 * @stack: first node of linked list
 * @line_n: line number
 */
void pint(stack_t **stack, unsigned int line_n)
{
	stack_t *h = *stack;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", h->n);

}

/**
 * pop - removes first node of a linked list
 * @stack: first node of linked list
 * @line_n: line number
 */
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *delete = *stack;

	if (!delete)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}
	*stack = delete->next;
	free(delete);
}
