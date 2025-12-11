#include "sort.h"

/**
 * swap - Swap two elements in an array and print the array if values differ
 * @array: The array
 * @i: Index of first element
 * @j: Index of second element
 * @size: Size of the array
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
    if (array[i] != array[j])
    {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        print_array(array, size);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array to partition
 * @low: Start index
 * @high: End index
 * @size: Size of the array
 *
 * Return: The pivot index
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = low, j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            swap(array, i, j, size);
            i++;
        }
    }
    swap(array, i, high, size);
    return i;
}

/**
 * quick_sort_recursive - Recursively apply Quick Sort
 * @array: The array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
    if (low < high)
    {
        size_t pi = lomuto_partition(array, low, high, size);

        if (pi > 0)
            quick_sort_recursive(array, low, pi - 1, size);
        quick_sort_recursive(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order
 *             using the Quick sort algorithm (Lomuto)
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

