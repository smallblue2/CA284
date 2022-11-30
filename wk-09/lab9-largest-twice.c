/* 
 * Author: Niall Ryan
 * Description: Takes in a list of integers from cmd line
 * 		outputs the largest number who's half is
 * 		also contained in the list, or 0 if none
 * 		is found.
 *
 * Input: A list of unordered integer numbers
 * Output: The largest number who's half is also in the list
 */

// Header files
#include <stdio.h>
#include <stdlib.h>
// Function prototypes
void bubbleSort(int *array, int n);
int *fill_array(int n, char **argv);
void display(int *arr, int n);
int largest_twice(int *arr, int n);

// Main function
int main(int argc, char **argv)
{
	// Initialize the length of our array
	int length = argc - 1;
	// Initialize our array pointer to the return
	// of the fill_array function
	int *array = fill_array(length, argv);
	// Ensures the memory for the array was assigned
	// correctly.
	if (array == NULL)
	{
		printf("Failed to allocate memory!");
		return 0;
	}
	// Bubblesort's our array
	bubbleSort(array, length);
	// Outputs the largest number that has it's half
	// also contained in the list.
	printf("%i\n", largest_twice(array, length));
	// Returns 0 to signal successful execution.
	return 0;

}

// BubbleSort function takes an array and the array length
// as parameters, and performs bubblesort on it.
void bubbleSort(int *array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (*(array + j) > *(array + j + 1))
			{
				*(array + j) ^= *(array + j + 1);
				*(array + j + 1) = *(array + j) ^ *(array + j + 1);
				*(array + j) ^= *(array + j + 1);
			}
		}
	}
}

// Fill_array takes in parameters of the array length,
// and argv. It fills an array from the command line, returning
// a pointer.
int *fill_array(int n, char **argv)
{
	int *arr = calloc(n, sizeof(int));
	if (!arr)
	{
		return NULL;
	}
	for (int i = 0; i < n; ++i)
	{
		*(arr + i) = atoi(argv[i + 1]);
	}

	return arr;
}

// Display just displays an array of length n,
// used for debugging purposes
void display(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", *(arr + i));
	}
	printf("\n");

	return;
}

// Largest_twice function takes in two parameters, an array and
// the array length. Finds the largest number that also has it's
// half in a sorted array. 
int largest_twice(int *arr, int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (*(arr + j) * 2 == *(arr + i))
			{
				return *(arr + i);
			}
		}
	}
	return 0;
}
