#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 *
 * Return: Number of nodes in the list, not counting repeated cycle nodes.
 * Exit with status 98 if a loop is detected.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	const listint_t *loop;
	size_t count = 0;

	if (head == NULL)
		return (0);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (fast == NULL || fast->next == NULL)
	{
		while (head != NULL)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			count++;
			head = head->next;
		}
		return (count);
	}

	loop = head;
	while (loop != slow)
	{
		loop = loop->next;
		slow = slow->next;
	}

	while (head != loop)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		head = head->next;
	}

	printf("[%p] %d\n", (void *)head, head->n);
	count++;
	printf("-> [%p] %d\n", (void *)loop, loop->n);
	exit(98);

	return (count);
}
