#include "lists.h"

/**
 * delete_nodeint_at_index - a function that deletes the node
 * at index index of a listint_t linked list.
 *
 * @head: Pointer
 * @index: index of the node to be deleted
 *
 * Return: void
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *next;
	listint_t *temp;
	unsigned int pos;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
		return (1);
	}
	else
	{
		temp = *head;
		for (pos = 0; pos < index - 1; pos++)
		{
			if (temp != NULL)
			{
				temp = temp->next;
			}
		}
	}
	next = temp->next;
	temp->next = temp->next->next;
	free(next);
	return (1);
}

