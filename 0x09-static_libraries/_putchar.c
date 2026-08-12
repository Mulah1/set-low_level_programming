#include <unistd.h>

int _putchar(char c)
{
	return (int)write(1, &c, 1);
}
