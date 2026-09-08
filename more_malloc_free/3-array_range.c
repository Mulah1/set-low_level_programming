#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers containing values from min to max.
 * @min: Starting integer (included).
 * @max: Ending integer (included).
 *
 * Return: Pointer to the newly created array, or NULL if min > max
 *         or if malloc fails.
 */
int *array_range(int min, int max)
{
	int *array;
	int size;
	int i;

	if (min > max)
		return (NULL);

	size = (max - min) + 1;

	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = min + i;

	return (array);
}
