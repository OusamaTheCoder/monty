#include "monty.h"

/**
 * displayCharr - Displays the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void displayChar(stack_t **stack, unsigned int lineNumber)
{
	int asciiValue;

	if (stack == NULL || *stack == NULL)
		strErr(11, lineNumber);

	asciiValue = (*stack)->n;
	if (asciiValue < 0 || asciiValue > 127)
		strErr(10, lineNumber);

	printf("%c\n", asciiValue);
}

/**
 * displayStr - Displays a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void displayStr(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
	int asciiValue;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		asciiValue = temp -> n;
		if (asciiValue <= 0 || asciiValue > 127)
			break;

		printf("%c", asciiValue);
		temp = temp -> next;
	}
	printf("\n");
}

/**
 * rotateLeft - Moves the top node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void rotateLeft(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack) -> next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp -> next;

	temp -> next = *stack;
	(*stack) -> prev = temp;
	*stack = (*stack)->next;
	(*stack) -> prev->next = NULL;
	(*stack) -> prev = NULL;
}

/**
 * rotateRight - Moves the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void rotateRight(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
    stack_t *temp;

    if (stack == NULL || *stack == NULL || (*stack) -> next == NULL)
        return;

    temp = *stack;

    while (temp->next != NULL)
        temp = temp->next;

    temp -> next = *stack;
    temp -> prev->next = NULL;
    temp -> prev = NULL;
    (*stack) -> prev = temp;
    (*stack) = temp;
}
