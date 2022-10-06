/*
 * Author: Niall Ryan
 *
 * Approach:
 * 	1. Take single positive integer input from argument
 * 	2. Have a single hailstone function which works on n's pointer
 * 	3. Through logic checks, repeatedly run through functions until *n = 1
 *
 * Date: 6-10-22
 *
 * Input: Single positive integer n as cmdline argument
 * Output: The hailstone sequence starting from n, ending at n = 1
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void hailstone(int *p);

/* Main function */
int main(int argc, char **argv) {
	// Initialize n as our input from the cmd line, turned into an integer 
	int n = atoi(argv[1]);
	// Initialize n's pointer to n's address.
	// This is so we can work on n's value inside of the hailstone function
	int *pn = &n;
	// Call hailstone, and pass n's pointer
	hailstone(pn);

	// Return 0 for successful execution
	return 0; 
}

// Hailstone function
void hailstone(int *p) {
	// Dereference our pointer p, if it's value is not one, keep looping
	while (*p != 1) {
		// Output the value of our pointer dereferenced, before operations are carried out
		printf("%i ", *p);
		// If the dereferenced value of our pointer p is even
		if (*p % 2 == 0) {
			// Assign and divide the value p points to in half
			*p /= 2;
		// Otherise our number has to be odd
		} else {
			// Assign dereferenced value of our pointer to be multiplied by three, and incremented
			*p = (*p * 3) + 1;
		}
	}
	// Output the final value that p points to, after the hailstone algorithm
	printf("%i\n", *p);

	// Return nothing due to our function being void
	return;
}
