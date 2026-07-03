#include <stdio.h>

/**
 * main - Entry point
 * Description: Print all single digit numbers starting from 0
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar('0' + i);
	}
	putchar(10);
	return (0);
}
