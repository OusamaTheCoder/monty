#include "monty.h"

/**
 * handleError - Outputs relevant error messargses based on the provided error code.
 * @errorCode: The error codes and their meanings are as follows:
 *   (1) => No input file or multiple files given to the program.
 *   (2) => Unable to operaten or read the specified file.
 *   (3) => Invalid instruction found in the provided file.
 *   (4) => Memory allocation failure.
 *   (5) => Parameter for "push" instruction is not an integer.
 *   (6) => Attempting to print from an empty stack.
 *   (7) => Attempting to poperat from an empty stack.
 *   (8) => Insufficient elements in the stack for the operateration.
 */
void handleErr(int errorCode, ...)
{
	va_list args;
	char *operat;
	int lineNum;

	va_start(args, errorCode);
	switch (errorCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't operate on file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			lineNum = va_arg(args, int);
			operat = va_arg(args, char *);
			fprintf(stderr, "L%d: Unknown instruction %s\n", lineNum, operat);
			break;
		case 4:
			fprintf(stderr, "Error: Memory allocation failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: Usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	releaseNodes();
	exit(EXIT_FAILURE);
}

/**
 * modeErr - Manargses errors with corresponding error codes.
 * @errorCode: The error codes and their meanings are as follows:
 *   (6) => Attempting to print from an empty stack.
 *   (7) => Attempting to poperat from an empty stack.
 *   (8) => Insufficient elements in the stack for the operateration.
 *   (9) => Division by zero.
 */
void modeErr(int errorCode, ...)
{
	va_list args;
	int lineNum;
	char *operat;
	

	va_start(args, errorCode);
	switch (errorCode)
	{
		case 6:
			fprintf(stderr, "L%d: Unable to pint, stack is empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: Unable to pop from an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			lineNum = va_arg(args, unsigned int);
			operat = va_arg(args, char *);
			fprintf(stderr, "L%d: Unable to %s, stack too short\n", lineNum, operat);
			break;
		case 9:
			fprintf(stderr, "L%d: Division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	releaseNodes();
	exit(EXIT_FAILURE);
}

/**
 * strErr - Manargses errors related to string operaterations.
 * @errorCode: The error codes and their meanings are as follows:
 *   (10) => Value inside a node is outside ASCII bounds.
 *   (11) => Attempting a string operateration on an empty stack.
 */
void strErr(int errorCode, ...)
{
	va_list args;
	int lineNum;

	va_start(args, errorCode);
	lineNum = va_arg(args, int);
	switch (errorCode)
	{
		case 10:
			fprintf(stderr, "L%d: Unable to perform pchar, value out of range\n", lineNum);
			break;
		case 11:
			fprintf(stderr, "L%d: Unable to perform pchar, stack is empty\n", lineNum);
			break;
		default:
			break;
	}
	releaseNodes();
	exit(EXIT_FAILURE);
}
