#include "main.h"

/**
 * leet - encodes a string into 1337 leetspeak
 * @str: string to encode
 *
 * Return: pointer to encoded string
 */
char *leet(char *str)
{
	int i = 0;
	int j;
	char sub[] = "aAeEoOtTlL";
	char leet_num[] = "4433007711";

	while (str[i] != '\0')
	{
		for (j = 0; j < 10; j++)
		{
			if (str[i] == sub[j])
			{
				str[i] = leet_num[j];
			}
		}
		i++;
	}

	return (str);
}
