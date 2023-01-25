#include "sort.h"

/**
 * swap_integers - function that swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_integers(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm,
 * using the Knuth sequence: n+1 = n * 3 + 1 -> 1, 4, 13, 40, 121, ...
 * @array: the array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, idx, gap = 1;

	if (!array || size < 2)
		return;
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = 0; i < size - gap; i++)
		{
			for (j = i + gap; j < size; j += gap)
			{
				idx = j;
				while ((idx >= gap) && array[idx - gap] > array[idx])
				{
					swap_integers(array + (idx - gap), array + idx);
					idx -= gap;
				}
			}
		}
		print_array((const int *)array, size);
		gap = (gap - 1) / 3;
	}
}
