#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point of the program.
 * @argc: Count of command-line arguments.
 * @argv: List of command-line arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openFile(argv[1]);
	freeNodes();
	return (0);
}

/**
 * @createNode - Allocates memory for a node and assigns a value.
 * @value: Number to go inside the node.
 * Return: Upon success,
 * returns a pointer to the node. Otherwise, returns NULL.
 */
stack_t *createNode(int n)
{
	stack_t *nod = malloc(sizeof(stack_t));

	if (nod == NULL)
		err(4);

	nod->next = NULL;
	nod->prev = NULL;
	nod->n = n;
	return (nod);
}

/**
 * freeNodes - Releases memory allocated for nodes in the stack.
 */
void freeNodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * add2Queue - Adds a node to the stack or queue.
 * @newNode: Pointer to the new node.
 * @lineNum: Line number of the opcode.
 */
void add2Queue(stack_t **newNode, __attribute__((unused))unsigned int lineNum)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *newNode;
	(*newNode)->prev = temp;

}
