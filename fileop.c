#include "monty.h"
/**
 * openf - opens file
 * @file_name: file name
 * Return: Void
 */
void openf(char *file_name)
{
FILE *fod = fopen(file_name, "r");
if (file_name == NULL || fod == NULL)
err(2, file_name);
readf(fod);
fclose(fod);
}
/**
 * readf - reads file
 * @fod: file pointer
 * Return: Void
 */
void readf(FILE *fod)
{
int lineno, fmt = 0;
char *buffer = NULL;
size_t lens = 0;
for (lineno = 1; getline(&buffer, &lens, fod) != -1; lineno++)
fmt = parseln(buffer, lineno, fmt);
free(buffer);
}
/**
 * findfct - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @fmt:  storage format. 0 - Stack, 1 - Queue.
 * @line: line number
 * Return: void
 */
void findfct(char *opcode, char *val, int fmt, int line)
{
int i;
int flag;
instruction_t func_list[] = {
{"push", addtostack},
{"pall", printstack},
{"pint", printtop},
{"pop", poptop},
{"nop", nop},
{"swap", swapnodes},
{"add", addnodes},
{"sub", subnodes},
{"div", divnodes},
{"mul", mulnodes},
{"mod", modnodes},
{"pchar", _printchar},
{"pstr", _printstr},
{"rotl", _rotl},
{"rotr", _rotr},
{NULL, NULL}
};
if (opcode[0] == '#')
return;
for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_list[i].opcode) == 0)
{
call_fun(func_list[i].f, opcode, val, line, fmt);
flag = 0;
}
}
if (flag == 1)
err(3, line, opcode);
}
/**
 * parseln - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @lineno: line number
 * @fmt:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parseln(char *buff, int lineno, int fmt)
{
char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		err(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (fmt);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findfct(opcode, value, lineno, fmt);
	return (fmt);
}
/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			addtoqueue(&node, ln);
	}
	else
		func(&top, ln);
}
