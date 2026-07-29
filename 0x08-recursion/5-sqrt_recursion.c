#include "main.h"

/**
 * actual_sqrt - Helper function to find square root recursively
 * @n: Number to find square root of
 * @i: Current root candidate
 *
 * Return: Square root, or -1 if no natural root exists
 */
int actual_sqrt(int n, int i)
{
	if (i * i > n)
	{
		return (-1);
	}
	if (i * i == n)
	{
		return (i);
	}
	return (actual_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: Number to evaluate
 *
 * Return: Natural square root, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (actual_sqrt(n, 1));
}
