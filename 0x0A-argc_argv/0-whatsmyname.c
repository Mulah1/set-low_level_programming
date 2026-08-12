#include <stdio.h>

/* Prints the program name (argv[0]) followed by a newline. */
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return 0;
}
