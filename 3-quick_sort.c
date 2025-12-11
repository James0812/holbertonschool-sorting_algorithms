#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 * @array: Array to partition
 * @lo: Starting index
 * @hi: Ending index
 * @size: Size of the array
 * Return: The partition index
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo, j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(array + i, array + j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != hi)
	{
		swap_ints(array + i, array + hi);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts an array
 * @array: Array to sort
 * @lo: Starting index
 * @hi: Ending index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		quick_sort_recursive(array, lo, p - 1, size);
		quick_sort_recursive(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

