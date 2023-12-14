#ifndef MONTY_H
#define MONTY_H

/* Define _GNU_SOURCE to enable GNU extensions */
#define _GNU_SOURCE

/* Define include necessary header files */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*operationFun)(stack_t **, unsigned int);

/* Document Handling */
void openFile(char *filePath);
int analyzeLine(char *buffer, int lineNumber, int format);
void readContents(FILE *);
int calculateLen(FILE *);
void locateFun(char *, char *, int, int);

/* Arithmetic Operations on Data Structures */
void addNodes(stack_t **stack, unsigned int size);
void subNodes(stack_t **stack, unsigned int size);
void divNodes(stack_t **stack, unsigned int size);
void mulNodes(stack_t **stack, unsigned int size);
void modNodes(stack_t **stack, unsigned int size);

/* Exception handling */
void handleErr(int errorCode, ...);
void modeErr(int errorCode, ...);
void strErr(int errorCode, ...);
void rotateRight(stack_t **stack, unsigned int size);

/* Memory Structure Manipulation */
stack_t *generateNode(int n);
void releaseNodes(void);
void showStack(stack_t **stack, unsigned int size);
void pushToStack(stack_t **stack, unsigned int size);
void enqueueToQueue(stack_t **stack, unsigned int size);

void executeFun(operationFun, char *, char *, int, int);

void displayTopElm(stack_t **stack, unsigned int size);
void popTop(stack_t **stack, unsigned int size);
void noOpera(stack_t **stack, unsigned int size);
void swapNodes(stack_t **stack, unsigned int size);

/* Character and String Manipulations */
void displayChar(stack_t **stack, unsigned int size);
void displayStr(stack_t **stack, unsigned int size);
void rotateLeft(stack_t **stack, unsigned int size);

#endif
