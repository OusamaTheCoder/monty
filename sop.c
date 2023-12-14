#include "monty.h"

/**
 * mulNodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void mulNodes(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack) -> next == NULL)
		modeErr(8, lineNumber, "mul");

	(*stack) = (*stack)->next;
	result = (*stack) -> n * (*stack)->prev->n;

	(*stack) -> n = result;
	free((*stack) -> prev);
	(*stack) -> prev = NULL;
}


/**
 * modNodes - Computes the remainder of the top two elements in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void modNodes(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack) -> next == NULL)

		modeErr(8, lineNumber, "mod");


	if ((*stack) -> n == 0)
		modeErr(9, lineNumber);

	(*stack) = (*stack)->next;
	result = (*stack) -> n % (*stack) -> prev->n;

	(*stack) -> n = result;
	free((*stack)->prev);
	(*stack) -> prev = NULL;
}
