#include "monty.h"
/**
 * mulnodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void mulnodes(stack_t **stack, unsigned int linenumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
moreerr(8, linenumber, "mul");
(*stack) = (*stack)->next;
sum = (*stack)->n * (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
/**
 * modnodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void modnodes(stack_t **stack, unsigned int linenumber)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
moreerr(8, linenumber, "mod");
if ((*stack)->n == 0)
moreerr(9, linenumber);
(*stack) = (*stack)->next;
sum = (*stack)->n % (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
