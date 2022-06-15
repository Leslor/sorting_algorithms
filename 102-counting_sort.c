#include "sort.h"

/**
 * max_f - function that return the max value in a array
 *
 * @list: Array to be evaluated
 * @size: Size of the array
 * Return: max number
 */
int max_f(int *list, int size)
{
	int max = 0, i;

	for (i = 0; i < size; i++)
	{
		if (list[i] > max)
			max = list[i];
	}
	return (max);
}

/**
 * counting_sort - counting sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *bucket_tmp, *bucket_index;
	size_t i, k, lar;

	if (array == NULL || size <= 1)
		return;
	/*1. Determine max number*/
	lar = max_f(array, size);
	/*2. Create an empty index array of size range*/
	bucket_index = malloc(sizeof(int) * (lar + 1));
	if (bucket_index == NULL)
		return;
	for (i = 0; i <= lar; i++)
		bucket_index[i] = 0;
	/*3. Fill Index array with the number of occurence*/
	for (k = 0; k < size; k++)
		bucket_index[array[k]] += 1;
	/*4. Sum up Index array or frecuencia absoluta*/
	for (i = 1; i <= lar; i++)
		bucket_index[i] += bucket_index[i - 1];
	print_array(bucket_index, lar + 1);
	/*5. Create output array to store sorted values*/
	bucket_tmp = malloc(sizeof(int) * size);
	if (bucket_tmp == NULL)
		return;
	/*6. Map the input-index-output array*/
	for (k = 0; k < size; k++)
	{
		bucket_tmp[bucket_index[array[k]] - 1] = array[k];
		bucket_index[array[k]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = bucket_tmp[i];

	free(bucket_tmp);
	free(bucket_index);
}
