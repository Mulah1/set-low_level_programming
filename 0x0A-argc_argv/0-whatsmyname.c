#include <stdio.h>

/**
 * main - prints the program's name, followed by a new line
 * @argc: argument count
 * @argv: array of pointers to arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
