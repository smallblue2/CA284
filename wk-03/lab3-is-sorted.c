/* 
 * Author: Niall Ryan
 * Description: Sorts a given array and outputs it in order
 * Input: An integer array given from cmd line
 * Output: The integer array, sorted
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
void bubbleSort(int *new_list, int length);

/* Main function */
int main(int argc, char **argv) {
	
	/* Ensuring we've been given atleast one argument */
	if (argc > 1) {
	
		/* Initializing a variable equal to the length of our list */
		int length = argc - 1;
		/* Initializing our list, equalling its length to the no. arguments */
		int int_list[length];

		/* Filling our list with cmdline arguments, integerised */
		for ( int i = 0; i < length; ++i) {
			int_list[i] = atoi(argv[i + 1]);
		}

		/* Here we call bubbleSort */
		bubbleSort(int_list, length);
		
		/* Outputting all elements of our bubble-sorted list */
		for ( int i = 0; i < length; ++i) {
			printf("%i\n", int_list[i]);
		}

	}

	/* Returning 0 for successful execution */
	return 0;
}

/* Bubble-sort function */
void bubbleSort(int *new_list, int length) {
	/* Initializing a counter variable, to see if we've changed the order of any element */
	int counter;
	/* Initializing a temporary variable, to help us swap elements */
	int tmp;
	/* Keep looping until our counter equals the length, AKA we haven't swapped this cycle */
	while ( counter != length ) {
		/* Reset the counter for each cycle of bubble sort */
		counter = 0;
		/* Iterate over the loop */
		for ( int i = 0; i < length; ++i ) {
			/* Swap an element if the second is larger than the first */
			if ( i + 1 != length & new_list[i] > new_list[i + 1] ) {
				tmp = new_list[i];
				new_list[i] = new_list[i + 1];
				new_list[i + 1] = tmp;
			} else {
				/* Otherwise add to the counter */
				counter++;
			}
		}
	}
	return;
}
