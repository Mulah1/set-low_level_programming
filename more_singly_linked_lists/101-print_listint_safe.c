#include <stdio.h>
#include "lists.h"

/**
 * print_until - Prints nodes up to a specified node.
 * @head: Starting node.
 * @stop: Node where printing stops.
 *
 * Return: Number of nodes printed.
 */
static size_t print_until(const listint_t *head, const listint_t *stop)
{
	size_t count = 0;

	while (head != stop)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		head = head->next;
	}
	return (count);
}

/**
 * print_cycle - Prints every node in a cycle once.
 * @entry: First node in the cycle.
 *
 * Return: Number of cycle nodes printed.
 */
static size_t print_cycle(const listint_t *entry)
{
	const listint_t *current = entry;
	size_t count = 0;

	do {
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
	} while (current != entry);

	printf("-> [%p] %d\n", (void *)entry, entry->n);
	return (count);
}

/**
 * find_cycle - Finds the first node of a cycle.
 * @head: Head of the list.
 *
 * Return: First node in the cycle, or NULL if no cycle exists.
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
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 *
 * Return: Number of nodes printed.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *entry;
	size_t count;

	if (head == NULL)
		return (0);
	entry = find_cycle(head);
	if (entry == NULL)
		return (print_until(head, NULL));
	count = print_until(head, entry);
	return (count + print_cycle(entry));
}
