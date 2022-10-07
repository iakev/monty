#include "monty.h"
/**
 * push_error - error handling on invalid push instruction
 *
 * @line_number: line number where invalid instruction is
 *
 * Return: Nothing
 */
void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_argv(argv);
	exit(EXIT_FAILURE);
}
/**
 * pint- execute pint opcode
 *
 * @stack: address containing the head of the doubly linked stack behaving as
 * stack or queue
 * @line_number: line number being executed
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int j = -1;
	
	j = print_top(*stack);
	if (j == 0)
	{
		pint_error(line_number);
	}
}
