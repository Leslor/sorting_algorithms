#include "sort.h"
/**
 * partition - partitions the array
 * @array: array to take in
 * @start: start of array;
 * @end: end of array
 * @size: full size of array
 * Return: position of pivot
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int pIndex = start, i, temp;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			if (pIndex != i)
			{
				temp = array[pIndex];
				array[pIndex] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			pIndex++;
		}
	}
	if (pIndex != end)
	{
		temp = array[pIndex];
		array[pIndex] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (pIndex);
}
/**
 * QuickSort - quick sorts with recursion
 * @array: array to sort through
 * @start: start of array or subarray
 * @end: end of array or subarray
 * @size: size of full array
 */
void QuickSort(int *array, int start, int end, int size)
{
	int pIndex;

	if (start < end)
	{
		pIndex = partition(array, start, end, size);
		QuickSort(array, start, pIndex - 1, size);
		QuickSort(array, pIndex + 1, end, size);
	}
}
/**
 * quick_sort - quick sorts an array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	QuickSort(array, 0, size - 1, size);
}
