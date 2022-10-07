#include "monty.h"
/**
 * push_error - error handling on invalid push instruction
 *
 * @line_number: line number where invalid instruction is
 *
 * Return: Nothing
 */
void push_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_argv(argv);
	exit(EXIT_FAILURE);
}
/**
 * verify- function that verifies that something can be an iterger
 * @string: string to be verified if lead to interger
 * Return: 0 on success, 1 on failure
 */
int verify(char *string)
{
	int x = 0;
	int len = strlen(string);

	while (x < len)
	{
		if (x == 0 && string[x] == '-')
		{
			++x;
			continue;
		}
		if (!isdigit(*(string + x)))
			return (1);
		++x;
	}
	return (0);
}
/**
 * push- execute push opcode
 *
 * @stack: address containing the head of the doubly linked stack behaving as
 * stack or queue
 * @line_number: line number being executed
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n = -1, i = 0;

	printf("inside push before segfault\n");
	while (argv[i])
	{
		i++;
	}
	if (i > 1)
	{
		if (i != 2 || (verify(argv[1]) == 1))
			push_error(line_number);
		n = atoi(argv[1]);
		add_dnodeint(stack, n);

	}
	push_error(line_number);
}
/**
 * pall- execute the pall instruction opcode
 *
 * @stack: address containing the head of the doubly linked stack behaving as
 * stack or queue
 * @line_number: line number being executed
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int i = -1;

	i = print_dlistint(*stack);
	if (i == -1)
	{
		opcode_error(line_number, argv[0]);
	}
}
/**
 * execute_opcode- execute the current instruction/opcode
 *
 * @line_number: line number being executed
 * @head: address containing the head of the linked list
 * @argv: global variable containing commands and their arguments
 * Return: Nothing
 */
void execute_opcode(int line_number, stack_t **head, char **argv)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"NULL", NULL}
	};

	while (strcmp(opcodes[i].opcode, "NULL") != 0)
	{
		if (strcmp(argv[0], opcodes[i].opcode) == 0)
		{
			opcodes[i].f(head, line_number);
			break;
		}
		i++;
	}
	if (strcmp(opcodes[i].opcode, "NULL") == 0)
	{
		opcode_error(line_number, argv[0]);
	}
}
