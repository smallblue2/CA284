/* 
 * Author: Niall Ryan
 * Description: Program accepts a list of floating numbers
 * 		from argv, and finds the second second_largest number.
 *
 * Input: A list of floats from cmd line
 * Output: The second largest float up to 1 decimal point.
 */

// Header file
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float *argv_array(int length, char **argv);
void bubble_sort(float *array, int length);
float second_largest(float *array, int length);
void display(float *array, int length);

// Main function
int main(int argc, char **argv)
{
	// Initialize length as the length of our float array
	int length = argc - 1;

	// Initialize our float array pointer as the return of
	// our argv_array function
	float *array = argv_array(length, argv);
	// Ensure our array pointer was created correctly
	if (array == NULL)
	{
		printf("Failed to allocate memory!");
		return 0;
	}

	// Perform bubble_sort on our array
	bubble_sort(array, length);

	// Output the return of second_largest function, which will be our
	// second_largest number.
	printf("%.1f\n", second_largest(array, length));

	// Free allocated memory we've used
	free(array);

	// Return 0 to signal succesful execution
	return 0;
}

// Argv_array function takes parameters array length, and
// argv. Creates array pointer, allocating memory, filling
// array from argv, and returning the pointer.
float *argv_array(int length, char **argv)
{
	float *output = calloc(length, sizeof(float));
	if (!output)
	{
		return NULL;
	}
	for (int i = 0; i < length; ++i)
	{
		*(output + i) = atof(argv[i + 1]);
	}
	return output;
}

// Selection_sort function has an array and the array length
// as parameters. Simply sorts array parameter through selection
// sort.
void bubble_sort(float *array, int length)
{
	// First loop controls number of passes through array
	for (int i = 0; i < length; i++)
	{
		// Inner loop compares elements to eachother
		for (int j = 0; j < length - 1; j++)
		{
			// If element[j] is larger than element[j + 1].
			// simply swap the elements.
			if (*(array + j) > *(array + j + 1))
			{
				float tmp = *(array + j + 1);
				*(array + j + 1) = *(array + j);
				*(array + j) = tmp;
			}
		}
	}

	return;
}

// Second_largest function returns the second largest number
// in a sorted flaot array, taking into account repeats and such.
float second_largest(float *array, int length)
{
	// If the last two numbers in our array are the same
	if (*(array + length - 1) == *(array + length - 2))
	{
		// Iterate through array backwards until we have a different
		// number.
		int i = 1;
		while (*(array + length - i) == *(array + length - 1))
		{
			// If we've iterated through the entire arry,
			// just return the last number, as it's the only
			// number in the array
			if (i == length - 1)
			{
				return *(array + length - 1);
			}
			i += 1;
		}
		// After iterating through the array backwards until we found
		// the first different number to the last number, return
		// it.
		return *(array + length - i);
	}
	// The last two numbers in our array are different, so just return
	// the second last number in our sorted array.
	return *(array + length - 2);
}

// Display function isn't used in program, was used
// for debugging the program during development.
void display(float *array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%.1f ", *(array + i));
	}
	printf("\n");
	return;
}
