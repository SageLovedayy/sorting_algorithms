#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, size_t size) {
    int max_element = 0;
    size_t i, index;
    int *counting_array;

    /* Find the maximum element in the array */
    for (i = 0; i < size; ++i) {
        if (array[i] > max_element) {
            max_element = array[i];
        }
    }

    /* Create and initialize the counting array */
    counting_array = (int *)malloc((max_element + 1) * sizeof(int));
    if (counting_array == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i <= (size_t)max_element; ++i) {
        counting_array[i] = 0;
    }

    /* Count occurrences of each element in the array */
    for (i = 0; i < size; ++i) {
        counting_array[array[i]]++;
    }

    /* Print the counting array */
    printf("Counting array: ");
    for (i = 0; i <= (size_t)max_element; ++i) {
        printf("%d ", counting_array[i]);
    }
    printf("\n");

    /* Update the original array with sorted values */
    index = 0;
    for (i = 0; i <= (size_t)max_element; ++i) {
        while (counting_array[i] > 0) {
            array[index++] = i;
            counting_array[i]--;
        }
    }

    /* Free dynamically allocated memory */
    free(counting_array);
}

