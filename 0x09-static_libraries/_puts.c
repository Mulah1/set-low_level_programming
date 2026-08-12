#include "main.h"

void _puts(char *s)
{
	while (s && *s)
		_putchar(*s++);
}
