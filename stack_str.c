#include "monty.h"

/**
 * printChar - Displays the ASCII value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void printChar(stack_t **stack, unsigned int line_number)
{
	int asciiVal;

	if (stack == NULL || *stack == NULL)
		strErr(11, line_number);

	asciiVal = (*stack)->n;
	if (asciiVal < 0 || asciiVal > 127)
		strErr(10, line_number);

	printf("%c\n", asciiVal);
}

/**
 * printStr - Displays a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineN: Interger representing the line number of of the opcode.
 */
void printStr(stack_t **stack, __attribute__((unused))unsigned int lineN)
{
	int asciiVal;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		asciiVal = temp->n;
		if (asciiVal <= 0 || asciiVal > 127)
			break;

		printf("%c", asciiVal);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotatLeft - Moves the top node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineN: Interger representing the line number of of the opcode.
 */
void rotatLeft(stack_t **stack, __attribute__((unused))unsigned int lineN)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotatRight - Moves the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineN: Interger representing the line number of of the opcode.
 */
void rotatRight(stack_t **stack, __attribute__((unused))unsigned int lineN)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
