#include "monty.h"

/**
 * err - Outputs relevant error messargses based on the provided error code.
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
void err(int codeErr, ...)
{
	va_list args;
	char *opr;
	int lineNum;

	va_start(args, codeErr);
	switch (codeErr)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;

		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;

		case 3:
			lineNum = va_arg(args, int);
			opr = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, opr);
			break;

		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;

		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;

		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * morErr - Manargses errors with corresponding error codes.
 * @errorCode: The error codes and their meanings are as follows:
 *   (6) => Attempting to print from an empty stack.
 *   (7) => Attempting to poperat from an empty stack.
 *   (8) => Insufficient elements in the stack for the operateration.
 *   (9) => Division by zero.
 */
void morErr(int codeErr, ...)
{
	va_list args;
	char *opr;
	int lineNum;

	va_start(args, codeErr);
	switch (codeErr)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;

		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;

		case 8:
			lineNum = va_arg(args, unsigned int);
			opr = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lineNum, opr);
			break;

		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;

		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * strErr - Manargses errors related to string operaterations.
 * @errorCode: The error codes and their meanings are as follows:
 *   (10) => Value inside a node is outside ASCII bounds.
 *   (11) => Attempting a string operateration on an empty stack.
 */
void strErr(int codeErr, ...)
{
	va_list args;
	int lineNum;

	va_start(args, codeErr);
	lineNum = va_arg(args, int);
	switch (codeErr)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNum);
			break;

		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNum);
			break;

		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
