#include "main.h"

char *_strcat(char *dest, char *src)
{
	char *d = dest;
	while (*d)
		d++;
	while ((*d++ = *src++))
		;
	return dest;
}
