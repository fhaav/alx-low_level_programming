#include "lists.h"

/**
 * delete_dnodeint_at_index - A function that deletes the node at index
 * of a dlistint_t linked list.
 * @head: A pointer to the head of the dlistint_t list.
 * @index: The index of the node to delete.
 *
 * Return: 1 (success), -1 otherwise.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	dlistint_t *temp;
	unsigned int pos;

	if (*head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	for (pos = 0; pos < index - 1; pos++)
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
	}

	if (current->next == NULL)
		return (-1);

	temp = current->next;
	current->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = current;
	free(temp);
	return (1);
}
