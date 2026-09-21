#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 *
 * Return: Number of nodes printed.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast, *entry, *current;
	size_t count = 0;

	if (head == NULL)
		return (0);

	slow = head;
	fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (fast == NULL || fast->next == NULL)
	{
		current = head;
		while (current != NULL)
		{
			printf("[%p] %d\n", (void *)current, current->n);
			count++;
			current = current->next;
		}
		return (count);
	}

	entry = head;
	while (entry != slow)
	{
		entry = entry->next;
		slow = slow->next;
	}

	current = head;
	while (current != entry)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
	}

	printf("[%p] %d\n", (void *)entry, entry->n);
	count++;
	current = entry->next;
	while (current != entry)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
	}

	printf("-> [%p] %d\n", (void *)entry, entry->n);
	return (count);
}
