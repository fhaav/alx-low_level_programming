#include "hash_tables.h"

/**
 * print_node - Prints a key-value pair
 * @node: Pointer to a hash_node_t
 * @printed: Integer flag indicating if a pair has already been printed
 */
void print_node(hash_node_t *node, int printed)
{
	if (printed)
		printf(", ");
	printf("'%s': '%s'", node->key, node->value);
}

/**
 * print_list - Prints a linked list of nodes
 * @node: Pointer to a hash_node_t
 * @printed: Pointer to an integer flag
 */
void print_list(hash_node_t *node, int *printed)
{
	while (node != NULL)
	{
		print_node(node, *printed);
		*printed = 1;
		node = node->next;
	}
}

/**
 * hash_table_print - Prints the key-value pairs of a hash table
 * @ht: Pointer to a hash_table_t
 *
 * Description: Prints the key-value pairs of all nodes in the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int printed = 0;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		if (node)
		{
			if (node->next == NULL)
			{
				print_node(node, printed);
				printed = 1;
			}
			else
			{
				print_list(node, &printed);
			}
		}
	}
	printf("}\n");
}
