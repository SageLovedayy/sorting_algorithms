#include "sort.h"

/**
* counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @arr: the array to be sorted
 * @arr_size: number of elements in @arr
 */

void counting_sort(int *arr, size_t arr_size)
{
	size_t cumul;
	int *sorted_arr, index_i, index_j, max_value;

	/* Check if the array is empty or has only one element */
	if (!arr || arr_size < 2)
		return;
	max_value = 0;
	for (index_i = 0; index_i < (int)arr_size; index_i++)
		if (arr[index_i] > max_value)
			max_value = arr[index_i];
	sorted_arr = malloc(sizeof(int) * ++max_value);
	if (!sorted_arr)
		return;
	for (index_i = 0; index_i < max_value; index_i++)
		sorted_arr[index_i] = 0;
	/* Count the occurrences of each element in the array */
	for (index_i = 0; index_i < (int)arr_size; index_i++)
		sorted_arr[arr[index_i]] += 1;
	/* Reconstruct the sorted array using the counting array */
	for (index_i = index_j = 0; index_i < max_value && index_j < (int)arr_size; index_i++)
	{
		cumul = sorted_arr[index_i];
		while (cumul > 0)
		{
			arr[index_j] = index_i;
			cumul--;
			index_j++;
		}
	}
	/* Update the counting array to store cumulative frequencies */
	cumul = 0;
	for (index_i = 0; index_i < max_value; index_i++)
	{
		cumul += sorted_arr[index_i];
		sorted_arr[index_i] = cumul;
	}
	/* Print the sorted array */
	print_array(sorted_arr, max_value);
	free(sorted_arr);
}
