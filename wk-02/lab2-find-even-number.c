/* 
 * Author: Niall
 * Description: Finds all even numbers in an array of integers
 * Input: n number of integers from cmd line
 * Output: all even integers paired with their array position
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Main function */
int main(int argc, char *argv[]) {

	/* Make sure arguments are provided */
	if (argc == 1) {
		printf("Arguments needed!\n");
		return 0;
	}

	/* Define array */
	int data[argc - 1];

	/* Fill array */
	for (int i = 0; i < argc - 1; ++i) {
		data[i] = atoi(argv[i + 1]);
	}

	/* found variable */
	int found = 0;
	/* Iterate over array */
	for (int i = 0; i < argc - 1; ++i) {
		/* Check if the element is even */
		if ( data[i] % 2 == 0) {
			/* output array position with element */
			printf("%i - %i\n", i, data[i]);
			/* alert we've found atleast one */
			found = 1;
		}
	}
	
	/* If none found, output */
	if ( found == 0 ) {
		printf("Not found!\n");
	}

	return 0;
}
