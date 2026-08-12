#include "main.h"

char *_strstr(char *haystack, char *needle)
{
	if (!*needle)
		return haystack;
	for (; *haystack; haystack++)
	{
		char *h = haystack;
		char *n = needle;
		while (*h && *n && *h == *n)
		{
			h++;
			n++;
		}
		if (!*n)
			return haystack;
	}
	return 0;
}
