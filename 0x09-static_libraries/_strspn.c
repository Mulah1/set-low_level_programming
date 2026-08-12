#include "main.h"

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *a;

	while (*s)
	{
		a = accept;
		while (*a && *a != *s)
			a++;
		if (*a == '\0')
			break;
		count++;
		s++;
	}
	return count;
}
