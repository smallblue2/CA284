/* 
 * Author: Niall Ryan
 *
 * Description: This programme takes a list of numbers from argv,
 * 		assigns them into an array, and outputs any numbers
 * 		that appears more than three times. Outputting each
 * 		number n number of times, where n is the number.
 *
 * Approach: First, the programme takes the numbers from argv
 * 	     and assigns them into an array. Then, it goes through
 * 	     the array and counts the number of times each number
 * 	     appears. If the number appears more than three times,
 * 	     it is outputted n times, where n is the number.
 *
 * Date: 30-11-2022
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void bubble_sort(int *array, int size);
void swap(int *pX, int *pY);
void smart_print(int *array, int size);

// Main Function
int main(int argc, char **argv)
{
	// Declare Variables
	int size_of_array = 5;
	// Allocate memory, ensuring it works
	int *array = (int *)calloc(size_of_array, sizeof(int));
	if (!array)
	{
		printf("Error: Memory allocation failed!");
		exit(0);
	}
	// Fill our array from argv, resizing if the amount
	// needed to be stored is more than five integers.
	int counter = 0;
	// While there is room for our elements
	while (counter < size_of_array)
	{	
		// If the next element will fill our array completely
		if (counter + 1 == size_of_array)
		{
			// If the array is less than the amount of arguments we
			// need to fill
			if (size_of_array < argc - 1)
			{
				// Increase the size of our array
				size_of_array++;
				int *tmp = (int *)realloc(array, size_of_array * sizeof(int));
				if (!tmp)
				{
					printf("ERROR: Memory reallocation failed!");
					exit(0);
				}
				array = tmp;
			}
		}
		// If our array is big enough to store all the elements
		if (counter < argc)
		{
			*(array + counter) = atoi(argv[counter + 1]);
		}
		counter++;
	}
	// Bubble sort our array
	bubble_sort(array, size_of_array);
	// Smart print our array, checking for duplicates
	smart_print(array, size_of_array);
	// Return 0
	return 0;
}

// Bubblesort a given 'array' of size 'size'
void bubble_sort(int *array, int size)
{
	// First loop controls the number of passes
	for (int i = 0; i < size; ++i)
	{
		// Second loop controls the number of comparisons
		for (int j = 0; j < size - 1; ++j)
		{
			if (*(array + j) > *(array + j + 1))
			{
				swap(&*(array + j), &*(array + j + 1));
			}
		}
	}
}

// Swap two integers using 
// bitwise operators
void swap(int *pX, int *pY)
{
	*pX ^= *pY;
	*pY = *pX ^ *pY;
	*pX ^= *pY;

	return;
}

// Check for duplicates in an array
// and print them out n times if they're
// above 3, where n is the duplicate count.
void smart_print(int *array, int size)
{
	// Declare Variables
	int skip_to = 0;
	int dup_count = 0;
	// Loop through the array
	for (int i = 0; i < size - 1; ++i)
	{
		// If we're not skipping to a number continue
		if (skip_to > i)
		{
			continue;
		}
		// If the next number is the same as the current
		if (*(array + i) == *(array + i + 1))
		{
			// Increase the duplicate count
			dup_count++;
			// If the next iteration is the last
			if (i + 1 == size - 1)
			{
				// If the number of duplicates is over 3
				if (dup_count > 2)
				{
					// Print the number n times, where n is the duplicate count
					for (int j = 0; j < dup_count + 1; ++j)
					{
						printf("%i\n", *(array + i));
					}
				}
			}
		}
		else
		{
			// If the number of duplicates is over 3
			if (dup_count > 2)
			{
				// Print the number n times, where n is the duplicate count
				for (int j = 0; j < dup_count + 1; ++j)
				{
					printf("%i\n", *(array + i));
				}
			}
			// Reset the duplicate count
			dup_count = 0;
		}
	}
}
