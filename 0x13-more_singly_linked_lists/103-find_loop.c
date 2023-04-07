#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop in a linked list.
 *
 * @head: Pointer
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast;
	listint_t *slow;

	slow = fast = head;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = fast;
			break;
		}
	}
	if (!slow || !fast || !fast->next)
		return (NULL);
	while (slow != fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return (fast);
}
