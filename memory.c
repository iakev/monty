#include "monty.h"
/**
 * free_argv - frees the argument vector
 * @argv: argument vector
 * Return: Nothing
 */
void free_argv(char **argv)
{

	int i = 0;

	while (argv[i] != NULL)
	{
		if (argv[i])
		{
			free(argv[i++]);
		}
	}
	if (argv)
	{
		free(argv);
	}
}
/**
 * free_dlistint - function that frees a dlistint_t list
 *
 * @head: pointer to the head node
 *
 * Return: Nothing.
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp = NULL;

	if (head)
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
			free(temp->prev);
		}
		free(temp);
	}
}
