#include "sort.h"

/**
* lomuto_partition - Implements lomuto partition scheme
* @array: array to be partitioned
* @low: index of low bound
* @high: index of high bound
* @size: number of elements in array
* Return: Index of pivot element after partitioning
*/
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int temp, pivot;
	size_t i, j;

	if (array == NULL || low >= high || high >= size)
	{
		/* Invalid arguments in lomuto_partition */
		/*printf("Invalid arguments in lomuto_partition\n");*/
		return 0;
    }

    pivot = array[high];
    i = low - 1;

    /* Print the pivot value */
    /*printf("Pivot: %d\n", pivot);*/

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;

            if (i != j)
            {
                /* Swap array[i] and array[j] */
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                /* Print the swap and the current array */
                /*printf("Swap (%lu, %lu): ", (unsigned long)i, (unsigned long)j);*/
                print_array(array, size);
            }
        }
    }

    /* Pivot =>> swap array[i + 1] and array[high] */
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    if (i + 1 != high)
    {
        /* Print the final pivot swap and the current array */
        /*printf("Final Pivot Swap (%lu, %lu): ", (unsigned long)(i + 1), (unsigned long)high);*/
        print_array(array, size);
    }

    return (i + 1);
}


/**
* quick_sort_helper - helper func for quick sort algorithm
* @array: array to be sorted
* @low: index of low bound
* @high: index of high bound
* @size: number of elements in array
*/
void quick_sort_helper(int *array, size_t low, size_t high, size_t size)
{
    size_t pivot_index;

    /* Check if low is less than high to continue with the partitioning */
    if (low < high && high < size)
    {
        pivot_index = lomuto_partition(array, low, high, size);

        /* Recursively sort subarrays on both sides of the pivot */
        quick_sort_helper(array, low, pivot_index - 1, size);
        quick_sort_helper(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
