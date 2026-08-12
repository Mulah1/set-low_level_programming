#include "main.h"

char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*a == *s)
				return s;
			a++;
		}
		s++;
	}
	return 0;
}
