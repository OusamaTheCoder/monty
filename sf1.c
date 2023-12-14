#include "monty.h"

/**
 * addToStack - Pushes a new node onto the stack.
 * @newNode: Pointer to the new node.
 * @lineNum: Integer representing the line number of the opcode.
 */
void pushToStack(stack_t **newNode, __attribute__((unused))unsigned int lineNum)
{
	stack_t *temp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *newNode;
		return;
	}

	temp = head;
	head = *newNode;
	head -> next = temp;
	temp -> prev = head;
}

/**
 * showStack - Displays the contents of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void showStack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp -> next;
	}
}

/**
 * popTop - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void popTop(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		modeErr(7, lineNumber);

	temp = *stack;
	*stack = temp -> next;

	if (*stack != NULL)
		(*stack) -> prev = NULL;
	free(temp);
}

/**
 * printTopElm - Displays the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void displayTopElm(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		modeErr(6, lineNumber);

	printf("%d\n", (*stack) -> n);
}
