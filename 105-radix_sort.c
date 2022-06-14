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
 * num_digits - function that return the num of digits
 * ofthe max value
 *
 * @n: the max value of the array
 * Return: The large of the max value
*/
int num_digits(int n)
{
	int counter = 0;

	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

/**
 * radix_sort - function that sorts an array of integers
 * in ascending order using the Radix sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int max_n = max_f(array, size);
	int LAR = num_digits(max_n);
	int bucket[10][10], bucket_cnt[10];
	size_t i;
	int j, k, r, divisor = 1, pass;

	if (array == NULL || size < 2)
		return;

	for (pass = 0; pass < LAR; pass++)
	{
		for (i = 0; i < 10; i++)
			bucket_cnt[i] = 0;
		for (i = 0; i < size; i++)
		{
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++)
			{
				array[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;
		print_array(array, size);
	}
}
