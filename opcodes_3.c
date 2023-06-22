#include "monty.h"
#include <stdlib.h>

/**
  * swap - swaps the top two elements of the stack
  * @stack: first node of linked list
  * @line_n: line number
  */
void swap(stack_t **stack, unsigned int line_n)
{
	int hold = (*stack)->n;

	if (!(stack) || !(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = hold;
}

/**
  * add - adds the top two elements of the stack
  * @stack: start of doubly linked list
  * @line_n: line number
  */
void add(stack_t **stack, unsigned int line_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_n);
}





