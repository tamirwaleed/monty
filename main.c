#include "monty.h"
/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
openf(argv[1]);
freenodes();
return (0);
}
/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
stack_t *node;
node = malloc(sizeof(stack_t));
if (node == NULL)
err(4);
node->next = NULL;
node->prev = NULL;
node->n = n;
return (node);
}
/**
 * freenodes - Frees nodes in the stack.
 */
void freenodes(void)
{
stack_t *temp;
if (top == NULL)
return;
while (top != NULL)
{
temp = top;
top = top->next;
free(temp);
}
}
/**
 * addtoqueue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void addtoqueue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
while (temp->next != NULL)
temp = temp->next;
temp->next = *new_node;
(*new_node)->prev = temp;
}
