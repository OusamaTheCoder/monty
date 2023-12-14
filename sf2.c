nclude "monty.h"

/**
 *  * noOpera - Performs no operation.
 *   * @stack: Pointer to a pointer pointing to the top node of the stack.
 *    * @lineNumber: Integer representing the line number of the opcode.
 *     */
void noOpera(stack_t **stack, unsigned int lineNumber)
{
		(void)stack;
			(void)lineNumber;
}

/**
 *  * swwapNodes - Exchanges the positions of the top two elements in the stack.
 *   * @stack: Pointer to a pointer pointing to the top node of the stack.
 *    * @lineNumber: Integer indicating the line number of the opcode.
 *     */
void swapNodes(stack_t **stack, unsigned int lineNumber)
{
		stack_t *tempNode;

			if (stack == NULL || *stack == NULL || (*stack) -> next == NULL)
						modeErr(8, lineNumber, "swap");

				tempNode = (*stack)->next;
					(*stack) -> next = tempNode -> next;

						if (tempNode -> next != NULL)
									tempNode -> next-> prev = *stack;

							tempNode -> next = *stack;
								(*stack) -> prev = tempNode;
									tempNode -> prev = NULL;
										*stack = tempNode;
}

/**
 *  * addNodes - Computes the sum of the top two elements in the stack.
 *   * @stack: Pointer to a pointer pointing to the top node of the stack.
 *    * @lineNumber: Integer representing the line number of the opcode.
 *     */
void addNodes(stack_t **stack, unsigned int lineNumber)
{
		int result;

			if (stack == NULL || *stack == NULL || (*stack) -> next == NULL)
						modeErr(8, lineNumber, "add");

				(*stack) = (*stack)->next;
					result = (*stack) -> n + (*stack) -> prev -> n;

						(*stack) -> n = result;
							free((*stack) -> prev);
								(*stack) -> prev = NULL;
}

/**
 *  * subNodes - Subtracts the top element from the second element in the stack.
 *   * @stack: Pointer to a pointer pointing to the top node of the stack.
 *    * @lineNumber: Integer representing the line number of the opcode.
 *     */
void subNodes(stack_t **stack, unsigned int lineNumber)
{
		int result;

			if (stack == NULL || *stack == NULL || (*stack) -> next == NULL)

						modeErr(8, lineNumber, "sub");

				(*stack) = (*stack)->next;
					result = (*stack) -> n - (*stack) -> prev -> n;

						(*stack) -> n = result;
							free((*stack) -> prev);
								(*stack) -> prev = NULL;
}


/**
 *  * divNodes - Divides the second element from the top by the top element in the stack.
 *   * @stack: Pointer to a pointer pointing to the top node of the stack.
 *    * @lineNumber: Integer representing the line number of the opcode.
 *     */
void divNodes(stack_t **stack, unsigned int lineNumber)
{
		int result;

			if (stack == NULL || *stack == NULL || (*stack) -> next == NULL)
						modeErr(8, lineNumber, "div");

				if ((*stack)->n == 0)
							modeErr(9, lineNumber);

					(*stack) = (*stack)->next;
						result = (*stack) -> n / (*stack) -> prev -> n;

							(*stack) -> n = result;
								free((*stack)->prev);
									(*stack) -> prev = NULL;
}
