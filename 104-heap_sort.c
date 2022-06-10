#include "sort.h"

int		get_parent(int i)
{
	return ((i - 1) / 2);
}

int		get_child(int i, int is_right)
{
	return (2 * i + 1 + (is_right != 0));
}

void	siftdown(int *array, int i, size_t size, size_t print_size)
{
	int	left, right, max, tmp;

	left = get_child(i, 0);
	right = get_child(i, 1);
	if (left < size && array[left] > array[i])
		max = left;
	else
		max = i;
	if (right < size && array[right] > array[max])
		max = right;
	if (max != i)
	{
		tmp = array[i];
		array[i] = array[max];
		array[max] = tmp;
		print_array(array, print_size);
		siftdown(array, max, size, print_size);
	}
}

void	heap_sort(int *array, size_t size)
{
	int	i, tmp;

	i = get_parent(size - 1);
	while (i >= 0)
	{
		siftdown(array, i, size, size);
		i--;
	}
	i = size - 1;
	while (i > 0)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		i--;
		siftdown(array, 0, i + 1, size);
	}
}
