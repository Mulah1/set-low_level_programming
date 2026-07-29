#include "main.h"

/**
 * check_prime - Helper function to recursively test divisibility
 * @n: Number to check
 * @i: Current divisor candidate
 *
 * Return: 1 if prime, 0 if divisible
 */
int check_prime(int n, int i)
{
	if (i * i > n)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - Checks if an integer is a prime number
 * @n: Number to evaluate
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (check_prime(n, 2));
}
