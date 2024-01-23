#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	size_t max_value, i, j;
	int *count_array, *sorted_array;

	if (!array || size < 2)
		return;

	max_value = 0;
	for (i = 0; i < size; i++)
		if ((size_t)array[i] > max_value)
			max_value = (size_t)array[i];

	count_array = malloc(sizeof(int) * (max_value + 1));
	sorted_array = malloc(sizeof(int) * size);

	if (!count_array || !sorted_array)
	{
		free(count_array);
		free(sorted_array);
		return;
	}
	for (i = 0; i <= max_value; i++)
		count_array[i] = 0;
	/* Count occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count_array[array[i]] += 1;
	print_array(count_array, max_value + 1);
	/* Update count_array to store cumulative counts */
	for (i = 1; i <= max_value; i++)
		count_array[i] += count_array[i - 1];
	for (j = size - 1; (int)j >= 0; j--)
	{
		sorted_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]] -= 1;
	}
	/* Copy the sorted array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	/* Clean up */
	free(count_array);
	free(sorted_array);
}

