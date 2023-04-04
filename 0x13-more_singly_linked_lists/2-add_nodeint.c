#include "lists.h"

/**
 * add_nodeint - a function that adds a new node
 * at the beginning of a listint_t list
 *
 * @head: pointer to listint_t
 * @n: input
 *
 * Return: ...
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));

	if (!newnode)
		return (NULL);

	newnode->n = n;
	newnode->next = (*head);
	(*head) = newnode;
	return (*head);
}
