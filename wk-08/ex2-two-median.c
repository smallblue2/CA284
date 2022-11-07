/* 
 * Author: Niall Ryan 
 *
 * Description: Take in an unordered list of integers, sorts them
 * 		and returns the two center elements.
 *
 * Approach: I will fill my input array with a helper function,
 * 	     I will pass my input array into another helper function
 * 	     to find the center numbers by dividing the length by
 * 	     two, and return a pointer that holds the two centre
 * 	     numbers, and then print my output.
 *
 * Input: A list of unordered integers, importantly of even length
 * Output: The two center elements
 *
 * Date: 03-11-22
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void fill_list(int *arr, int len, char **argv);
void bubble_sort(int *arr, int n);
int *centre_numbers(int *arr, int n);

// Main Function
int main(int argc, char **argv)
{
	// Initializd length variable
	int length = argc - 1;
	// Initialize integer pointer as NULL
	int *array = NULL;
	// Assign array integer pointer enough memory to store
	// integer inputs
	array = (int *)malloc(length * sizeof(int));
	// Ensure malloc didn't fail
	if (!array)
	{
		// Inform user and exit program with signal 1
		// if malloc fails
		printf("Memory allocation failed!");
		return 1;
	}

	// call fill_list function to fill our integer array
	fill_list(array, length, argv);
	// call bubble_sort to sort our integer array
	bubble_sort(array, length);

	// Initialize integer pointer mid_num as the return to
	// centre_numbers function
	int *mid_num = centre_numbers(array, length);
	// Output our middle numbers
	printf("%i\n", *mid_num);
	printf("%i\n", *(mid_num + 1));

	// Free the memory I've allocated
	free(array);
	free(mid_num);
	// Return 0 to signal succesful execution
	return 0;
}

// Fill_list function just fills the given arr parameter
// or length len from argv
void fill_list(int *arr, int len, char **argv)
{
	// Iterates through parameter array and argv,
	// filling array from argv
	for (int i = 0 ; i < len; ++i)
	{
		*(arr + i) = atoi(*(argv + i + 1));
	}

	return;
}

// bubble_sort function sorts given parameter array
// of length n
void bubble_sort(int *arr, int n)
{
	// First loop controls number of passes through array
	for (int i = 0; i < n; ++i)
	{
		// Inner loop compares elements and swaps
		for (int j = 0; j < (n - 1); ++j)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				int tmp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tmp;
			}
		}
	}
	return;
}

// Center_numbers function returns an integer
// pointer, holding the two middle integer values
// of parameter array
int *centre_numbers(int *arr, int n)
{
	// Initialize integer pointer 'out', to hold
	// our two middle integers
	int *out = (int *)malloc(2 * sizeof(int));
	// Ensure malloc doesn't fail, return null
	// if it does
	if (!out)
	{
		printf("Memory wasn't allocated");
		return NULL;
	}
	
	// Fill our out pointer with our middle numbers
	int index = n / 2;
	*out = *(arr + index - 1);
	*(out + 1) = *(arr + index);

	// Return our pointer
	return out;
}
