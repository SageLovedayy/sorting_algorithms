# 0x1B. C - Sorting algorithms & Big O

This repository contains C implementations of various sorting algorithms as part of the 0x1B project on Sorting algorithms and Big O notation. The project involves implementing the Bubble sort, Insertion sort, Selection sort, and Quick sort algorithms. Each sorting algorithm has a specific function that sorts an array of integers or a doubly linked list of integers in ascending order.

## Bubble Sort Algorithm

### Function Prototype
```c
void bubble_sort(int *array, size_t size);
```

### Description
The `bubble_sort` function sorts an array of integers in ascending order using the Bubble sort algorithm. It prints the array after each time two elements are swapped.

### Example Usage
```c
int array[] = {64, 34, 25, 12, 22, 11, 90};
size_t size = sizeof(array) / sizeof(array[0]);

bubble_sort(array, size);
```

### Big O Notation (Bubble Sort)
Write the time complexity of the Bubble sort algorithm in the file `0-O`:

```text
# 0-O
Best Case: O(n)
Average Case: O(n^2)
Worst Case: O(n^2)
```

## Insertion Sort Algorithm

### Function Prototype
```c
void insertion_sort_list(listint_t **list);
```

### Description
The `insertion_sort_list` function sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm. It prints the list after each time two elements are swapped.

### Example Usage
```c
listint_t *list = /* initialize a doubly linked list */;

insertion_sort_list(&list);
```

### Big O Notation (Insertion Sort)
Write the time complexity of the Insertion sort algorithm in the file `1-O`:

```text
# 1-O
Best Case: O(n)
Average Case: O(n^2)
Worst Case: O(n^2)
```

## Selection Sort Algorithm

### Function Prototype
```c
void selection_sort(int *array, size_t size);
```

### Description
The `selection_sort` function sorts an array of integers in ascending order using the Selection sort algorithm. It prints the array after each time two elements are swapped.

### Example Usage
```c
int array[] = {64, 34, 25, 12, 22, 11, 90};
size_t size = sizeof(array) / sizeof(array[0]);

selection_sort(array, size);
```

### Big O Notation (Selection Sort)
Write the time complexity of the Selection sort algorithm in the file `2-O`:

```text
# 2-O
Best Case: O(n^2)
Average Case: O(n^2)
Worst Case: O(n^2)
```

## Quick Sort Algorithm

### Function Prototype
```c
void quick_sort(int *array, size_t size);
```

### Description
The `quick_sort` function sorts an array of integers in ascending order using the Quick sort algorithm with the Lomuto partition scheme. The pivot is always the last element of the partition being sorted. It prints the array after each time two elements are swapped.

### Example Usage
```c
int array[] = {64, 34, 25, 12, 22, 11, 90};
size_t size = sizeof(array) / sizeof(array[0]);

quick_sort(array, size);
```

### Big O Notation (Quick Sort)
Write the time complexity of the Quick sort algorithm in the file `3-O`:

```text
# 3-O
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n^2)
```

## Getting Started
1. Clone the repository: `git clone https://github.com/yourusername/sorting-algorithms-c.git`
2. Navigate to the project directory: `cd sorting-algorithms-c`
3. Compile the code: `gcc -Wall -Werror -Wextra -pedantic *.c -o sort`

## Usage
After compiling the code, run the executable to test the sorting algorithms.

```bash
./sort
```

## Contributing
Feel free to contribute by adding new sorting algorithms, improving existing implementations, or addressing issues. Follow the guidelines in the [CONTRIBUTING.md](CONTRIBUTING.md) file.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Happy sorting!