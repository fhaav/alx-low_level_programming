#include "lists.h"

/**
 * free_listint2 - a function that frees a listint_t list.
 *
 * @head: pointer to listint_t list.
 *
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;


	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}
