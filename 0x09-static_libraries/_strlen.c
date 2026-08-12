#include "main.h"

int _strlen(char *s)
{
	int len = 0;
	while (s && s[len])
		len++;
	return len;
}
