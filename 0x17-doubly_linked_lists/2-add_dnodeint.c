#include "lists.h"

/**
 * add_dnodeint - A function that adds a new node at the beginning
 * of a doubly linked list.
 * @head: Pointer to the head of the doubly linked list
 * @n: Value to be stored in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newnode;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *head;

	if (*head != NULL)
		(*head)->prev = newnode;

	(*head) = newnode;

	return (*head);
}
