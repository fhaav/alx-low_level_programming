#include "hash_tables.h"

/**
 * hash_node_create - Creates a new hash_node_t node
 * @key: The key string
 * @value: The value string
 *
 * Return: The created hash_node_t node
 */
hash_node_t *hash_node_create(const char *key, const char *value)
{
	hash_node_t *node = malloc(sizeof(hash_node_t));

	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to add/update the key/value to
 * @key: The key string
 * @value: The value string
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	hash_node_t *cur;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	i = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[i];

	while (cur != NULL)
	{
		if (strcmp(cur->key, key) == 0)
		{
			free(cur->value);
			cur->value = strdup(value);
			if (cur->value == NULL)
				return (0);
			return (1);
		}
		cur = cur->next;
	}

	new_node = hash_node_create(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[i];
	ht->array[i] = new_node;

	return (1);
}
