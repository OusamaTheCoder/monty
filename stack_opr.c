#include "monty.h"

/**
 * mulNodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mulNodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		morErr(8, line_number, "mul");

	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;

	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modNodes - Computes the remainder of the top two elements in the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void modNodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		morErr(8, line_number, "mod");


	if ((*stack)->n == 0)
		morErr(9, line_number);

	(*stack) = (*stack)->next;
	result = (*stack)->n % (*stack)->prev->n;

	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
