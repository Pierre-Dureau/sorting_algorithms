#include "sort.h"
#include <stdio.h>

/**
 * counting_sort - counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0;
	int *count = NULL;

	if (!array)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i] + 1;
	}
	count = malloc(max * sizeof(int));
	if (!count)
		return;
	for (i = 0; i < max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 0; i < max; i++)
	{
		if (i + 1 < max)
			count[i + 1] += count[i];
		printf("%d", count[i]);
		if (i != max - 1)
			printf(", ");
		else
			printf("\n");
	}
	for (i = 0; i < max; i++)
	{
		if (i && count[i] != count[i - 1])
			array[count[i] - 1] = i;
	}
	free(count);
}
