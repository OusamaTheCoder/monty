#include "monty.h"

/**
 * openFile - Opens a file for reading.
 * @fileName: The path to the file.
 * Return: void
 */
void openFile(char *fileName)
{
	FILE *fileDes = fopen(fileName, "r");

	if (fileName == NULL || fileDes == NULL)
		err(2, fileName);

	readFile(fileDes);
	fclose(fileDes);
}


/**
 * readFile - Reads the contents of a file.
 * @fileDes: Pointer to the file descriptor.
 * Return: void
 */
void readFile(FILE *fileDes)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t leng = 0;

	for (line_number = 1; getline(&buffer, &leng, fileDes) != -1; line_number++)
	{
		format = parseLine(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parseLine - Breaks down each line into tokens to determine
 * which function to call.
 * @buffer: Line from the file.
 * @lineNumber: Line number.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is for stack, 1 if for queue.
 */
int parseLine(char *buffer, int line_number, int format)
{
	char *opcode, *fee;
	const char *delimi = "\n ";

	if (buffer == NULL)
		err(4);
	opcode = strtok(buffer, delimi);

	if (opcode == NULL)
		return (format);
	fee = strtok(NULL, delimi);

	if (strcmp(opcode, "stack") == 0)
		return (0);

	if (strcmp(opcode, "queue") == 0)
		return (1);

	findFunc(opcode, fee, line_number, format);
	return (format);
}

/**
 * findFunc - Finds the appropriate function for the given opcode.
 * @opcode: Opcode.
 * @fee: Argument of the opcode.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 * @lineN: Line number.
 * Return: void
 */
void findFunc(char *opcode, char *fee, int lineN, int format)
{
	int x;
	int flag;

	instruction_t func_list[] = {
		{"push", add2Stack},
		{"pall", showStack},
		{"pint", showTop},
		{"pop", popTop},
		{"nOpera", nOpera},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", printChar},
		{"pstr", printStr},
		{"rotatLeft", rotatLeft},
		{"rotatRight", rotatRight},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, x = 0; func_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, func_list[x].opcode) == 0)
		{
			callFunc(func_list[x].f, opcode, fee, lineN, format);
			flag = 0;
		}
	}

	if (flag == 1)
		err(3, lineN, opcode);
}


/**
 * callFunc - Invokes the necessary function.
 * @func: Pointer to the function to be called.
 * @oper: String representing the opcode.
 * @opcode: String representing the opcode.
 * @valu: String representing a numeric operand.
 * @lineN: Line number for the instruction.
 * @format: Format specifier. If 0, Nodes will be entered as a stack.
 *          If 1, Nodes will be entered as a queue.
 */
void callFunc(func_op func, char *oper, char *valu, int lineN, int format)
{
	stack_t *node;
	int flag;
	int x;

	flag = 1;

	if (strcmp(oper, "push") == 0)
	{
		if (valu != NULL && valu[0] == '-')
		{
			valu = valu + 1;
			flag = -1;
		}

		if (valu == NULL)
			err(5, lineN);
		for (x = 0; valu[x] != '\0'; x++)
		{
			if (isdigit(valu[x]) == 0)
				err(5, lineN);
		}

		node = createNode(atoi(valu) * flag);
		if (format == 0)
			func(&node, lineN);
		if (format == 1)
			add2Queue(&node, lineN);
	}
	else
		func(&head, lineN);
}
