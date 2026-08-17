#include <stdio.h>

/**
 * main - prints the number of arguments passed into the program
 * @argc: argument count
 * @argv: array of pointers to arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (0);
}
