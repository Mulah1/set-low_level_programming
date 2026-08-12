#include <stdio.h>

/* Prints the number of arguments passed to the program (not counting program name). */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);
	return 0;
}
