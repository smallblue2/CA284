/* 
 * Author: Niall Ryan
 * Approach:
 * 	1. Take arguments in main
 * 	2. Use a helper function to assign arguments into a list
 * 	   and convert them to floats.
 * 	3. Use another helper function, implementing linear search to
 *	   find largest or smallest
 *	4. Output the answer in main
 *
 * Date: 6-10-22
 *
 * Input: A string, followed by a float array of n size
 * Output: Either the largest or smallest float, depending
 * 	   on input string
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
void fill_list(float *list, int length, int argc, char **argv);
float linear_search(char *operation, float *list, int length);

/* Main function */
int main(int argc, char **argv) {
	// Ensure the user has given enough arguments
	if (argc > 2) {
		// Initialize length of our float array
		int length = argc - 2;
		// Initialize our array to length n of input
		float input_list[length];
		// Call our fill_list function to fill our list from input
		fill_list(input_list, length, argc, argv);
		// Initialize output variable to the return of our linear_search function
		float output = linear_search(argv[1], input_list, length);
		// Print our output number
		printf("%.2f\n", output);
	} else {
		// Output error to user
		printf("Invalid number of arguments\n");
	}
	// Return 0 to signal successful exit
	return 0;
}

/* List function */
void fill_list(float *list, int length, int argc, char **argv) {
	// Fill our list from argv, ensuring float conversion
	for (int i = 0; i < length; ++i) {
		list[i] = atof(argv[i + 2]);
	}
	// Void function so we don't return anything
	return;
}

/* Linear search function */
float linear_search(char *operation, float *list, int length) {
	// Initialize holder variable to keep track of our largest or smallest number
	float holder = list[0];
	// Check to see if we're finding the largest or the smallest number in our array
	if (strcmp(operation, "largest") == 0) {
		// Iterate over list for linear search
		for ( int i = 1; i < length; ++i ) {
			// If our holder variable is less than the current value, hold onto it
			if ( list[i] > holder ) {
				holder = list[i];
			}
		}
	} else if (strcmp(operation, "smallest") == 0) {
		// Iterate over list for linear search
		for ( int i = 1; i < length; ++i) {
			// If our holder variable is greater than the current value, hold onto it
			if ( list[i] < holder) {
				holder = list[i];
			}
		}
	} else {
		// If both logic checks above fail, input is an error
		// Alert user, and return 0 to signify 
		printf("Invalid first parameter\n");
		return 0;
	}
	
	// Return our found value after lienar search
	return holder;
}
