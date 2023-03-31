#include "lists.h"

/**
 * add_node_end - a function that adds a new node at the end of a list_t list.
 *
 * @head: double pointer to list_t
 * @str: value to insert into elements
 *
 * Return: the address of the new element, or NULL if it failed.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *current;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;
	current = malloc(sizeof(list_t));
	if (!current)
		return (NULL);

	current->str = strdup(str);
	current->len = len;
	current->next = NULL;

	if (*head == NULL)
	{
		*head = current;
		return (current);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = current;
	return (current);
}
