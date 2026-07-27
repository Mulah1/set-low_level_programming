#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: initial segment string
 * @accept: string containing accepted bytes
 *
 * Return: number of bytes in initial segment of s consisting only of accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, found;

	while (*s)
	{
		found = 0;
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				found = 1;
				break;
			}
		}
		if (!found)
		{
			break;
		}
		count++;
		s++;
	}

	return (count);
}
