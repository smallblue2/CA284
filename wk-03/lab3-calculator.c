/* 
 * Author: Niall Ryan
 * Description: Calculates product or division of
 * 		two floating point numbers.
 * Input: One string and Two floats from command args
 * Output: Single float from calculation
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
float calculate(float x, float y, char *operator);

/* Main function */
int main(int argc, char *argv[]) {
	
	/* Ensure three arguments given */
	if (argc == 4) {

		/* Initialize data from cmd line */
		char operator[9];
		strcpy(operator, argv[1]);
		float num1 = atof(argv[2]);
		float num2 = atof(argv[3]);

		/* Initializing output to the return of our calculate function */
		float output = calculate(num1, num2, operator);
		/* If our function returns a 0, there's an error, and we'll 
		 * output "invalid", otherwise output return */
		if (output == 0) {
			printf("invalid\n");
		} else {
			printf("%f\n", calculate(num1, num2, operator));
		}
	} else {
		/* Cancelling programme if insuffiecient amount of arguments */
		printf("Three arguments required.\n");
		return 1;
	}

	return 0;
}

/* Calculation function */
float calculate(float x, float y, char *operator) {
	
	/* Ensures float arguments are valid */
	if (x == 0 || y == 0) {
		return 0;
	}
	/* Checks the operator, and returns such operation on two float arguments */
	if (strcmp(operator, "multiply") == 0) {
		return x * y;
	} else if (strcmp(operator, "divide") == 0) {
		return x / y;
	} else {
		return 0;
	}
}
