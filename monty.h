#ifndef MONTY_H
#define MONTY_H

/* Define _GNU_SOURCE to enable GNU extensions */
#define _GNU_SOURCE

/* Define include necessary header files */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

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
typedef void (*func_op)(stack_t **, unsigned int);

/* Document Handling */
void openFile(char *fileName);
int parseLine(char *buffer, int line_number, int format);
void readFile(FILE *);
int lenChar(FILE *);
void findFunc(char *, char *, int, int);

/* Character and String Manipulations */
void printChar(stack_t **, unsigned int);
void printStr(stack_t **, unsigned int);
void rotatLeft(stack_t **, unsigned int);

/* Memory Structure Manipulation */
void showTop(stack_t **, unsigned int);
void popTop(stack_t **, unsigned int);
void nOpera(stack_t **, unsigned int);
void swapNodes(stack_t **, unsigned int);

void callFunc(func_op, char *, char *, int, int);

void freeNodes(void);
stack_t *createNode(int n);
void showStack(stack_t **, unsigned int);
void add2Stack(stack_t **, unsigned int);
void add2Queue(stack_t **, unsigned int);

/* Arithmetic Operations on Data Structures */
void divNodes(stack_t **, unsigned int);
void mulNodes(stack_t **, unsigned int);
void modNodes(stack_t **, unsigned int);
void addNodes(stack_t **, unsigned int);
void subNodes(stack_t **, unsigned int);

/* Exception handling */
void err(int codeErr, ...);
void morErr(int codeErr, ...);
void strErr(int codeErr, ...);
void rotatRight(stack_t **, unsigned int);

#endif
