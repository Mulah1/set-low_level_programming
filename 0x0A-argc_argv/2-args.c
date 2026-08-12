#include <stdio.h>

/* Prints all arguments, one per line, including the program name. */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return 0;
}
