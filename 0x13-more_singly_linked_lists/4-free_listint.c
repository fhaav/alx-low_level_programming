#include "lists.h"

/**
 * free_listint - a function that frees a listint_t list.
 *
 * @head: a pointer to listint_t list.
 *
 * Return: void
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
