#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Adds positive numbers provided as arguments.
 * If no numbers are provided, prints 0.
 * If any argument contains non-digit characters, prints "Error" and returns 1.
 */
int main(int argc, char *argv[])
{
	int i, j;
	int sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return 0;
	}

	for (i = 1; i < argc; i++)
	{
		/* empty string is invalid */
		if (argv[i][0] == '\0')
		{
			printf("Error\n");
			return 1;
		}

		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit((unsigned char)argv[i][j]))
			{
				printf("Error\n");
				return 1;
			}
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return 0;
}
