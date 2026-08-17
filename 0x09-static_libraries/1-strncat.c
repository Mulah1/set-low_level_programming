#include "main.h"

char *_strncat(char *dest, char *src, int n)
{
	char *d = dest;
	int i = 0;

	while (*d)
		d++;
	while (src[i] && i < n)
		*d++ = src[i++];
	*d = '\0';
	return (dest);
}
