#include "monty.h"
/**
 * pint_error - error handling on invalid push instruction
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
/**
 * pop_error - error handling on invalid push instruction
 *
 * @line_number: line number where invalid instruction is
 *
 * Return: Nothing
 */
void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_argv(argv);
	exit(EXIT_FAILURE);
}
/**
 * pop- execute pop opcode (removes top element of stack)
 *
 * @stack: address containing the head of the doubly linked stack behaving as
 * stack or queue
 * @line_number: line number being executed
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	int j = -1;

	j = delete_dnodeint_at_index(stack, 0);
	if (j == -1)
	{
		pop_error(line_number);
	}
}
/**
 * swap- execute swap opcode (swaps the top two elements of the stack)
 *
 * @stack: address containing the head of the doubly linked stack behaving as
 * stack or queue
 * @line_number: line number being executed
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	size_t j = -1;
	stack_t *temp = NULL;

	j = dlistint_len(*stack);
	if (j < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (j != 2)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->next->prev = (*stack);
		(*stack)->prev = temp;
		temp->next = (*stack);
		temp->prev = NULL;
		(*stack) = temp;
	}
	else
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		(*stack)->prev = temp;
		temp->next = (*stack);
		temp->prev = NULL;
		(*stack) = temp;
	}
}
