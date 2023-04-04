#include "lists.h"

/**
 * pop_listint - a function that deletes the head node of a
 * listint_t linked list, and returns the head node’s data (n).
 *
 * @head: pointer.
 * Return: void.
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int result;

	if (head == NULL || *head == NULL)
		return (0);

	result = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (result);
}
