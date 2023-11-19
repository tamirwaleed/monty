#include "main.h"
/**
 * _printchar - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void _printchar(stack_t **stack, unsigned int linenumber)
{
int ascii;
if (stack == NULL || *stack == NULL)
stringerr(11, linenumber);
ascii = (*stack)->n;
if (ascii < 0 || ascii > 127)
string_err(10, linenumber);
printf("%c\n", ascii);
}
/**
 * _printstr - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _printstr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
int ascii;
stack_t *temp;
if (stack == NULL || *stack == NULL)
{
printf("\n");
return;
}
temp = *stack;
while (temp != NULL)
{
ascii = temp->n;
if (ascii <= 0 || ascii > 127)
break;
printf("%c", ascii);
temp = temp->next;
}
printf("\n");
}
/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
stack_t *temp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
temp = *stack;
while (temp->next != NULL)
temp = temp->next;
temp->next = *stack;
(*stack)->prev = temp;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}
/**
 * _rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
stack_t *temp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
tmp = *stack;
while (temp->next != NULL)
temp = temp->next;
temp->next = *stack;
temp->prev->next = NULL;
temp->prev = NULL;
(*stack)->prev = temp;
(*stack) = temp;
}
