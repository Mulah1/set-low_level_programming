#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in the hash table.
 * @ht: The hash table to add or update the key/value to.
 * @key: The key. Cannot be an empty string.
 * @value: The value associated with the key. Must be duplicated.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *temp;
	char *value_dup;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	value_dup = strdup(value);
	if (!value_dup)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = value_dup;
			return (1);
		}
		temp = temp->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(value_dup);
		return (0);
	}
	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(value_dup);
		free(new_node);
		return (0);
	}
	new_node->value = value_dup;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
