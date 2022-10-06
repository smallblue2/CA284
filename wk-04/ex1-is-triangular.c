/* 
 * Author: Niall Ryan
 * Approach:
 *	1. Have a check_triangle function, returning either
 *	   a 1 if it is, or a 0 if it isn't.
 *	2. The pattern I see in triangle numbers, is that they're
 *	   generated from the summation of natural numbers
 *	3. I will generate a for loop which will sum natural numbers
 *	   up until it equals the inputted number, or is above it
 *
 * Date: 6-10-22
 *
 * Input: One integer command line argument
 * Output: Either "<number> is a triangular number", or "<number> isn't a triangular number"
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int is_triangle(int n);

int main(int argc, char **argv) {
	/* Initialize n as our input from command line */
	int n = atoi(argv[1]);
	/* Initialize check as the return of is_triangle, will either be 1 or 0 */
	int check = is_triangle(n);
	/* If check is 1, n is a triangle number, otherwise it isn't */
	if ( check ) {
		printf("%i is a triangular number\n", n);
	} else {
		printf("%i is not a triangular number\n", n);
	}

	/* Return 0 signals a succesful execution */
	return 0;
}

int is_triangle(int n) {
	/* Initialize sum to keep track of our addition */
	int sum = 0;
	/* Repeatedly keep adding the natural numbers until we reach n, or go over */
	for (int i = 0; i <= n; ++i) {
		sum += i;
		/* if our sum equals n, it's a triangle number */
		if ( sum == n ) {
			return 1;
		}
	}
	/* If it reaches here, it's not a triangle number */
	return 0;
}
