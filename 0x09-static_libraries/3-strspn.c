#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: initial segment
 * @accept: accepted bytes
 *
 * Return: number of accepted bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, found;

	while (*s)
	{
		found = 0;
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			return (count);
		count++;
		s++;
	}

	return (count);
}
