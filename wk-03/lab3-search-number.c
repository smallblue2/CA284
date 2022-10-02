/* 
 * Author: Niall Ryan
 * Description: Finds a number in an array
 * Input: A list of integers through cmd line arguments
 * Output Found <value> at <index>; when finds integer
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int search(int list[], int to_find, int length);

/* Main functions */
int main(int argc, char **argv) {
	
	/* Ensure arguments are given */
	if ( argc > 2 ) {
		/* Initialize find as our integer to find */
		int find = atoi(argv[1]);
		/* Initialize the length of our integer list to search */
		int length = argc - 2;
		/* Initialize our integer array list */
		int numbers[length];
		/* Fill out numbers integer array from cmd line */
		for (int i = 0; i < length; ++i) {
			numbers[i] = atoi(argv[i + 2]);
		}

		/* Call the search function to get back the found index */
		int index = search(numbers, find, length);
		/* Check if we found an index */
		if ( index == -1 ) {
			printf("Not found!");
		} else {
			printf("Found %i at %i\n", find, index);
		}
	}

	/* Return 0 for successful execution */ 
	return 0;
}

/* Search function */
int search(int list[], int to_find, int length) {
	/* Perform linear search through our list */
	for ( int i = 0; i < length; ++i ) {
		if ( to_find == list[i] ) {
			/* Return index if found */
			return i;
		}
	}
	/* If nothing is found, return -1 as an index */
	return -1;
}
