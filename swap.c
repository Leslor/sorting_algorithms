#include <stdio.h>
#include "sort.h"

/**
 * swap - change the position of two values in a array
 *
 * @A: The array to be modified
 * @index: The index of the array to be swaped
 */
void swap(int A[], size_t index)
{
	size_t temp;

	temp = A[index];
	A[index] = A[index + 1];
	A[index + 1] = temp;
}
