#include "main.h"

char *_strcpy(char *dest, char *src)
{
	char *d = dest;

	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dest);
}
