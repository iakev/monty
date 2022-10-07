#include "monty.h"
/**
 * print_dlistint - function that prints the data in a doubly linked list
 *
 * @h: pointer to the head node
 * Return: size_t representing number of nodes in list
 */
size_t print_dlistint(stack_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		i++;
		h = h->next;
	}
	return (i);
}
/**
 * add_dnodeint - function that adds a new node at beggining of list
 *
 * @head: address containing pointer to the head node
 * @n: data to be stored in a node of the list
 * Return: address of new node or NULL on failure
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = NULL;

	if (head == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*head == NULL)
	{
		new->prev = NULL;
		new->n = n;
		new->next = NULL;
		*head = new;
		return (*head);
	}
	new->prev = NULL;
	new->n = n;
	new->next = *head;
	(*head)->prev = new;
	*head = new;

	return (*head);
}
/**
 * print_top - function that prints the top data only in a doubly linked list
 *
 * @h: pointer to the head node
 * Return: size_t representing number of nodes in list
 */
size_t print_top(stack_t *h)
{
	size_t i = 0;

	while (i == 0 && h != NULL)
	{
		printf("%d\n", h->n);
		i++;
		h = h->next;
	}
	return (i);
}
