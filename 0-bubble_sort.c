#include "sort.h"

/**
 * swap - change the position of two values in a array
 *
 * @A: The array to be modified
 * @index: The index of the array to be swaped
 * @index_to_swap: The index of the array with index
 */

void swap(int A[], size_t index, size_t index_to_swap)
{
	size_t temp;

	temp = A[index];
	A[index] = A[index_to_swap];
	A[index_to_swap] = temp;
}


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

	if (size < 1)
		return;
	for (ord_idx = 1; ord_idx <= size - 1; ord_idx++)
	{
		flag = 0;
		for (index = 0; index < size - ord_idx; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(array, index, index + 1);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
