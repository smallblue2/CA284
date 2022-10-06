/* 
 * Author: Niall Ryan
 * Approach: 
 * 	1. Write happy_check function, passing it n, which sums the square numbers
 * 	2. happy_check will return the sum of squares, of which we can check 
 *	3. Through a lot of trial and error, I found out that the sum of squares will
 *	   loop forever, however there is a pattern.
 *	   We're told a happy number will eventually reach one.
 *	   The very difficult part was the not happy number.
 *	   After many iterations, I created a pattern where a not happy number 
 *	   will eventually reach 4
 *	   This is very important, and allows us to seperate happy and unhappy numbers.
 *	4. We keep running our sum squares until we've exhausted our number n
 *	5. We're either left with 1, which signals a happy number, or 4 which signals
 *	   an unhappy number
 *
 * Date: 6-10-22
 *
 * Input: An integer n from command line
 * Output: Either "is happy", or "not happy"
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int happy_check(int n);

/* Main Function */
int main(int argc, char **argv) {
	/* Initialize n as our input from command line */
	int n = atoi(argv[1]);

	/* Keep calculating until we exhaust n */
	while (n != 1 && n != 4) {
		/* call the happy check function on n */
		n = happy_check(n); 
	}

	/* if n is equal to 1, it's a happy number */
	if (n == 1) {
		printf("is happy\n");
	/* if n is equal to 4, it's an unhappy number */
	} else if (n == 4) {
		printf("not happy\n");
	}
	
	/* return 0 signals succesful execution of our script */
	return 0;
}

/* Happy Check */
int happy_check(int n) {
	/* Initialize our sum variable */
	int sum = 0;
	/* Initialize our leftover variable to keep track of what's leftover */
	int leftover = 0;

	/* Keep calculating while our n is positive */
	while (n > 0) {
		/* Perform calculations, get sum of squares, replace n */
		leftover = n % 10;
		sum = sum + (leftover * leftover);
		n /= 10;
	}

	/* Finally, return our sum */
	return sum;
}
