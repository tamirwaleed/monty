#include "main.h"
/**
 * addtostack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void addtostack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *temp;
if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (top == NULL)
{
top = *new_node;
return;
}
temp = top;
top = *new_node;
top->next = temp;
temp->prev = top;
}
/**
 * printstack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: line number of  the opcode.
 */
void printstack(stack_t **stack, unsigned int linenumber)
{
stack_t *temp;
(void) linenumber;
if (stack == NULL)
exit(EXIT_FAILURE);
temp = *stack;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
/**
 * poptop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void poptop(stack_t **stack, unsigned int linenumber)
{
tack_t *temp;
if (stack == NULL || *stack == NULL)
moreerr(7, linenumber);
temp = *stack;
*stack = temp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(temp);
}
/**
 * printtop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void printtop(stack_t **stack, unsigned int linenumber)
{
if (stack == NULL || *stack == NULL)
moreerr(6, linenumber);
printf("%d\n", (*stack)->n);
}
