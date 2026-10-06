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
	char *charset = "A-CHRDw87lblroO&pn44sen3311";

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);

	/* Key byte 0 */
	key[0] = charset[(len ^ 59) & 63];

	/* Key byte 1 */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += username[i];
	key[1] = charset[(sum ^ 79) & 63];

	/* Key byte 2 */
	sum = 1;
	for (i = 0; i < len; i++)
		sum *= username[i];
	key[2] = charset[(sum ^ 85) & 63];

	/* Key byte 3 */
	max = username[0];
	for (i = 0; i < len; i++)
	{
		if (username[i] > max)
			max = username[i];
	}
	srand(max ^ 14);
	key[3] = charset[rand() & 63];

	/* Key byte 4 */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += username[i] * username[i];
	key[4] = charset[(sum ^ 239) & 63];

	/* Key byte 5 */
	rand_val = 0;
	for (i = 0; i < username[0]; i++)
		rand_val = rand();
	key[5] = charset[(rand_val ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
