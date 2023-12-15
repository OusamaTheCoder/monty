#include "monty.h"

/**
 * noOpera - Performs no operation.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void nOpera(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swapNodes - Exchanges the positions of the top two elements in the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swapNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		morErr(8, line_number, "swap");

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * addNodes - Computes the sum of the top two elements in the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void addNodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		morErr(8, line_number, "add");

	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subNodes - Subtracts the top element from the second element in the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void subNodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		morErr(8, line_number, "sub");

	(*stack) = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;

	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divNodes - Divides the second element from the top,
 * by the top element in the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void divNodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		morErr(8, line_number, "div");

	if ((*stack)->n == 0)
		morErr(9, line_number);

	(*stack) = (*stack)->next;
	result = (*stack)->n / (*stack)->prev->n;

	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
