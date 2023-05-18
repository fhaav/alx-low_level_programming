#include "lists.h"

/**
 * add_dnodeint_end - A function that adds a new node
 * at the end of a dlistint_t list.
 * @head: Double pointer to the head of the list.
 * @n: Value to be assigned to the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newnode;
	dlistint_t *temp = *head;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
		newnode->prev = temp;
	}

	return (newnode);
}
