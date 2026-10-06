#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index at which to insert the new node
 * @n: integer value to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	if (*h == NULL)
	{
		if (idx != 0)
			return (NULL);
		return (add_dnodeint(h, n));
	}

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;
	while (current != NULL && i < idx)
	{
		current = current->next;
		i++;
	}

	if (i != idx)
		return (NULL);

	if (current == NULL)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = current->prev;
	new_node->next = current;

	if (current->prev != NULL)
		current->prev->next = new_node;
	else
		*h = new_node;

	current->prev = new_node;
	return (new_node);
}
