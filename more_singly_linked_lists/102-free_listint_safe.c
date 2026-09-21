#include <stdlib.h>
#include "lists.h"

/**
 * find_cycle - Finds the first node in a loop.
 * @head: Head of the list.
 *
 * Return: First node in the loop, or NULL if no loop exists.
 */
static const listint_t *find_cycle(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	const listint_t *entry;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			entry = head;
			while (entry != slow)
			{
				entry = entry->next;
				slow = slow->next;
			}
			return (entry);
		}
	}
	return (NULL);
}

/**
 * free_listint_safe - Frees a listint_t list safely, including loops.
 * @h: Pointer to the head pointer.
 *
 * Return: Number of nodes freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current;
	listint_t *next;
	const listint_t *entry;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	entry = find_cycle(*h);
	if (entry == NULL)
	{
		while (*h != NULL)
		{
			current = *h;
			*h = current->next;
			free(current);
			count++;
		}
		return (count);
	}

	current = *h;
	while (current != entry)
	{
		next = current->next;
		free(current);
		count++;
		current = next;
	}

	next = current;
	do {
		current = next;
		next = current->next;
		free(current);
		count++;
	} while (next != entry);

	*h = NULL;
	return (count);
}
