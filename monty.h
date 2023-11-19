#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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

extern stack_t *top;
typedef void (*op_func)(stack_t **, unsigned int);

void openf(char *file_name);
void readf(FILE *);
void findfct(char *, char *, int, int);
int parseln(char *buffer, int line_number, int format);
int lenchrs(FILE *);
void call_fun(op_func func, char *op, char *val, int ln, int format);
stack_t *create_node(int n);
void freenodes(void);
void printstack(stack_t **, unsigned int);
void addtostack(stack_t **, unsigned int);
void addtoqueue(stack_t **, unsigned int);
void printtop(stack_t **, unsigned int);
void poptop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swapnodes(stack_t **, unsigned int);
void addnodes(stack_t **, unsigned int);
void subnodes(stack_t **, unsigned int);
void divnodes(stack_t **, unsigned int);
void mulnodes(stack_t **, unsigned int);
void modnodes(stack_t **, unsigned int);
void _printchar(stack_t **, unsigned int);
void _printstr(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);
void _rotr(stack_t **, unsigned int);
void err(int error_code, ...);
void moreerr(int error_code, ...);
void stringerr(int error_code, ...);

#endif
