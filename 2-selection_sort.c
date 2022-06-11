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
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t index, min_position, idx_cpr;

	if (size < 2)
		return;
	for (index = 0; index < size - 1; index++)
	{
		min_position = index;
		for (idx_cpr = index + 1; idx_cpr < size; idx_cpr++)
		{
			if (array[min_position] > array[idx_cpr])
				min_position = idx_cpr;
		}
		if (min_position != index)
		{
			swap(array, index, min_position);
			print_array(array, size);
		}

	}
}
