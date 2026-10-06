#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a key for crackme5 based on a given username
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char key[7];
	char *username;
	int len, i, sum, max, rand_val;
	char *charset;

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);
	charset = "A-CHRDw87lblroO&pn44sen3311";

	/* Byte 1: XOR length with 59 */
	key[0] = charset[(len ^ 59) & 63];

	/* Byte 2: Sum of ASCII characters XOR 79 */
	for (i = 0, sum = 0; i < len; i++)
		sum += username[i];
	key[1] = charset[(sum ^ 79) & 63];

	/* Byte 3: Product of ASCII characters XOR 85 */
	for (i = 0, sum = 1; i < len; i++)
		sum *= username[i];
	key[2] = charset[(sum ^ 85) & 63];

	/* Byte 4: Seed rand with max char XOR 14 */
	for (i = 0, max = username[0]; i < len; i++)
	{
		if (username[i] > max)
			max = username[i];
	}
	srand(max ^ 14);
	key[3] = charset[rand() & 63];

	/* Byte 5: Sum of squares of ASCII characters XOR 239 */
	for (i = 0, sum = 0; i < len; i++)
		sum += username[i] * username[i];
	key[4] = charset[(sum ^ 239) & 63];

	/* Byte 6: Loop rand() first char times, XOR 229 */
	for (i = 0, rand_val = 0; i < username[0]; i++)
		rand_val = rand();
	key[5] = charset[(rand_val ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
