/* 
 * Author: Niall Ryan
 * Description: Finds the largest number in an array
 * Input: Multiple integers given through command line
 * Output: Largest integer in array
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int biggest(int int_arg[], int argc);

/* Main function */
int main(int argc, char *argv[]) {
	
	/* Initializing integer arg list */
	int int_arg[argc - 1];

	/* Iterating through argv, cloning elements to int_arg as ints */
	for ( int i = 0; i < argc; ++i ) {
		int_arg[i] = atoi(argv[i]);
	}

	/* Outputting largest number */
	printf("%i\n", biggest(int_arg, argc));

	/* Return 0 for successful execution */
	return 0;
}

/* Biggest function */
int biggest(int int_arg[], int argc) {
	/* Initializing largest variable */
	int largest = 0;

	/* Iterating through argv, declaring largest as arg[v]
	 * where it's less than current largest */
	for ( int i = 0; i < argc; ++i) {	
		if ( int_arg[i] > largest ) {
			largest = int_arg[i];
		}
	}
	
	/* Returning largest */
	return largest;
}
