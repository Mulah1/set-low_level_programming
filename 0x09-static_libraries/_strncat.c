#include "main.h"

char *_strncat(char *dest, char *src, int n)
{
	char *d = dest;
	while (*d)
		d++;
	int i = 0;
	while (i < n && src[i])
	{
		d[i] = src[i];
		i++;
	}
	d[i] = '\0';
	return dest;
}
