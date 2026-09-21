#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a given index.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 if successful, or -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current;
	listint_t *previous;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		current = *head;
		*head = current->next;
		free(current);
		return (1);
	}

	previous = *head;
	for (i = 0; previous != NULL && i < index - 1; i++)
		previous = previous->next;

	if (previous == NULL || previous->next == NULL)
		return (-1);

	current = previous->next;
	previous->next = current->next;
	free(current);

	return (1);
}
