#include "main.h"

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *a;

	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*s == *a)
				break;
			a++;
		}
		if (*a == '\0')
			return (count);
		count++;
		s++;
	}
	return (count);
}
