#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swap two integers in an array
 * @a: pointer to first int
 * @b: pointer to second int
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array of integers
 * @lo: low index
 * @hi: high index
 * @size: size of the array
 * Return: pivot index
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo;
	int j;

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
	if (i != hi && array[i] != array[hi])
	{
		swap_ints(array + i, array + hi);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_rec - recursive quick sort
 * @array: array of integers
 * @lo: low index
 * @hi: high index
 * @size: size of the array
 */
void quick_sort_rec(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		quick_sort_rec(array, lo, p - 1, size);
		quick_sort_rec(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - Quick sort using Lomuto scheme
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

