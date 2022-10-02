/* 
 * Author: Niall Ryan
 * Description: Finds the first duplicated item in an integer array
 * Input: An array of integers sourced from cmdline arguments
 * Output: A single integer, of which was repeated in our array
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int repeated(int *list, int length);

/* Main function */
int main(int argc, char **argv) {
	
	/* Ensure enough arguments are given */
	if ( argc > 2 ) {
		/* Initialize the length of our list in a variable */
		int length = argc - 1;
		/* Create an integer list long enough to hold our items */
		int int_list[length];
		/* Create our list, taking input from cmd line and integerising them */
		for ( int i = 0; i < length; ++i) {
			int_list[i] = atoi(argv[i + 1]);
		}
		
		/* Initializing repeated_digit to the return of our repeated */ 
		int repeated_digit = repeated(int_list, length);
		/* If repeated digit is equal to 0, we found no duplications */
		if ( repeated_digit == 0 ) {
			printf("no duplicated number\n");
		} else {
			/* Otherwise print the found digit */
			printf("%i\n", repeated_digit);
		}
	}

	/* Return 0 for succesful execution */
	return 0;
}

/* Repeated function */
int repeated(int *list, int length) {
	/* Iterating over our list */
	for (int i = 0; i < length; ++i) {
		int check_element = list[i];
		/* Iterating over our list again, and comparing each value to check_element */
		for (int j = 0; j < length; ++j) {
			/* If these elements are the same, return the element */
			if ( check_element == list[j] & i != j ) {
				return list[j];
			}
		}
	}
	/* If nothing is found, return NULL */
	return 0;
}
