#include "monty.h"

/**
 * openFile - Opens a file for reading.
 * @filePath: The path to the file.
 * Return: void
 */
void openFile(char *filePath)
{
	FILE *fileDes = fopen(filePath, "r");

	if (filePath == NULL || fileDes == NULL)
		handleErr(2, filePath);

	readContents(fileDes);
	fclose(fileDes);
}


/**
 * readContents - Reads the contents of a file.
 * @fileDescriptor: Pointer to the file descriptor.
 * Return: void
 */
void readContents(FILE *fileDes)
{
	int lineNumber, format = 0;
	char *buffer = NULL;
	size_t bufferSize = 0;

	for (lineNumber = 1; getline(&buffer, &bufferSize, fileDes) != -1; lineNumber++)
	{
		format = analyzeLine(buffer, lineNumber, format);
	}
	free(buffer);
}

/**
 * analyzeLine - Breaks down each line into tokens to determine
 * which function to call.
 * @buffer: Line from the file.
 * @lineNumber: Line number.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is for stack, 1 if for queue.
 */
int analyzeLine(char *buffer, int lineNumber, int format)
{
	char *opcode, *operand;
	const char *delimi = "\n ";

	if (buffer == NULL)
		handleErr(4);
	opcode = strtok(buffer, delimi);

	if (opcode == NULL)
		return (format);
	operand = strtok(NULL, delimi);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	locateFun(opcode, operand, lineNumber, format);
	return (format);
}

/**
 * locateFunction - Finds the appropriate function for the given opcode.
 * @opcode: Opcode.
 * @operand: Argument of the opcode.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 * @lineNumber: Line number.
 * Return: void
 */
void locateFun(char *opcode, char *operand, int ln, int format)
{
	int x;
	int flag;

	instruction_t func_list[] = {
		{"push", pushToStack},
		{"pall", showStack},
		{"pint", displayTopElm},
		{"pop", popTop},
		{"noOpera", noOpera},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", displayChar},
		{"pstr", displayStr},
		{"rotateLeft", rotateLeft},
		{"rotateRight", rotateRight},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, x = 0; func_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, func_list[x].opcode) == 0)
		{
			executeFun(func_list[x].f, opcode, operand, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handleErr(3, ln, opcode);
}

/**
 * executeFun - Invokes the necessary function.
 * @function: Pointer to the function to be called.
 * @opcode: String representing the opcode.
 * @operand: String representing a numeric operand.
 * @lineNumber: Line number for the instruction.
 * @format: Format specifier. If 0, Nodes will be entered as a stack.
 *          If 1, Nodes will be entered as a queue.
 */
void executeFun(operationFun operation, char *opcode, char *operand, int lineNumber, int format)
{
    stack_t *node;
    int flag;

    flag = 1;
    if (strcmp(opcode, "push") == 0)
    {
        if (operand != NULL && operand[0] == '-')
        {
            operand = operand + 1;
            flag = -1;
        }
        if (operand == NULL)
            handleErr(5, lineNumber);

        for (int i = 0; operand[i] != '\0'; i++)
        {
            if (!isdigit(operand[i]))
                handleErr(5, lineNumber);
        }

		node = generateNode(atoi(operand) * flag);

        if (format == 0)
            operation(&node, lineNumber);
        if (format == 1)
            enqueueToQueue(&node, lineNumber);
    }
    else
        operation(&head, lineNumber);
}
