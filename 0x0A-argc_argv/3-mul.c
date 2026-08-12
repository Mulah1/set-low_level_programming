#include <stdio.h>
#include <stdlib.h>

/* Multiplies two integers passed as arguments and prints the result.
 * If the number of arguments is not 2, prints "Error" and returns 1.
 */
int main(int argc, char *argv[])
{
	int a, b, res;

	if (argc != 3)
	{
		printf("Error\n");
		return 1;
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	res = a * b;
	printf("%d\n", res);

	return 0;
}
