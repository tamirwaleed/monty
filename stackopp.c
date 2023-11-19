#include "main.h"
/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int linenumber)
{
(void)stack;
(void)linenumber;
}
/**
 * swapnodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void swapnodes(stack_t **stack, unsigned int linenumber)
{
stack_t *temp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
moreerr(8, linenumber, "swap");
temp = (*stack)->next;
(*stack)->next = temp->next;
if (temp->next != NULL)
temp->next->prev = *stack;
temp->next = *stack;
(*stack)->prev = temp;
temp->prev = NULL;
*stack = temp;
}
/**
 * addnodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void addnodes(stack_t **stack, unsigned int linenumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
moreerr(8, linenumber, "add");
(*stack) = (*stack)->next;
sum = (*stack)->n + (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
/**
 * subnodes - subs the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void subnodes(stack_t **stack, unsigned int linenumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
moreerr(8, linenumber, "sub");
(*stack) = (*stack)->next;
sum = (*stack)->n - (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
/**
 * divnodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void divnodes(stack_t **stack, unsigned int linenumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_err(8, linenumber, "div");
if ((*stack)->n == 0)
moreerr(9, linenumber);
(*stack) = (*stack)->next;
sum = (*stack)->n / (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
