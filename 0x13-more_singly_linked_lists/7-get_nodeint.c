#include "lists.h"

/**
 * get_nodeint_at_index - a function that returns the nth
 * node of a listint_t linked list.
 *
 * @head: pointer
 * @index: input
 *
 * Return: void
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int value;

	if (head == NULL)
		return (NULL);
	for (value = 0; value < index; value++)
	{
		head = head->next;
	}
	return (head);
}
