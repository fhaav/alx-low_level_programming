#include "lists.h"

/**
 * insert_nodeint_at_index - a function that inserts a new node
 * at a given position
 * @head: pointer
 * @idx: ...
 * @n: ...
 *
 * Return: void
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *temp;
	listint_t *newnode;
	unsigned int pos;

	if (*head == NULL)
		return (NULL);
	if (idx != 0)
	{
		temp = *head;
		for (pos = 0; pos < idx - 1 && temp != NULL; pos++)
		{
			temp = temp->next;
		}
		if (temp == NULL)
			return (NULL);
	}
	newnode = malloc(sizeof(listint_t));
	newnode->n = n;

	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);

		if (newnode == NULL)
			return (NULL);
	}
	newnode->next = temp->next;
	temp->next = newnode;
	return (newnode);
}
