#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: nothing
 */


void bubble_sort(int *array, size_t size)
{
	size_t index, ord_idx;
	int flag;

	for (ord_idx = 1; ord_idx <= size - 1; ord_idx++)
	{
		flag = 0;
		for (index = 0; index < size - ord_idx; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(array, index);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
