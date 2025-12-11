#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swap two integers in an array
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
 * lomuto_partition - Order a subset of an array of integers
 * @array: Array of integers
 * @size: Size of the array
 * @lo: Starting index of the subset to order
 * @hi: Ending index of the subset to order
 *
 * Return: final partition index
 */
size_t lomuto_partition(int *array, size_t size, size_t lo, size_t hi)
{
	size_t i, j;

	for (i = j = lo; j < hi; j++)
	{
		if (array[j] < array[hi])
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
 * lomuto_sort - Quick sort recursion using Lomuto partition scheme
 * @array: Array of integers
 * @size: Size of the array
 * @lo: Starting index of the subset
 * @hi: Ending index of the subset
 */
void lomuto_sort(int *array, size_t size, size_t lo, size_t hi)
{
	size_t p;

	if (hi <= lo)
		return;

	p = lomuto_partition(array, size, lo, hi);

	if (p > 0)
		lomuto_sort(array, size, lo, p - 1);
	lomuto_sort(array, size, p + 1, hi);
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

