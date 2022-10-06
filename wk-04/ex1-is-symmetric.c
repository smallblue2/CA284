/* 
 * Author: Niall Ryan
 * Approach:
 * 	1. Take string input in
 * 	2. Have a is_symmetric function, called in main passing the string to be checked
 * 	3. Have a reverse string function that gets called in is_symmetric function
 * 	4. Have a passive string counter function to counter strings whenever necessary
 * 	5. Have the is_symmetric function return 1 if it is symmetric, otherwise 0
 * 	4. Output "no" or "yes" in main
 *
 * Date: 6-10-22
 *
 * Input: A single string from command line
 * Output: Either "No" or "Yes", depending on if the string is symmetric
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
int is_symmetric(char string[], int length);
int counter(char string[]);
void reverse(char string[], int begin, int end);

/* Main Function */
int main(int argc, char **argv) {
	int length = counter(argv[1]);
	// Initialize string_input with the same byte-size of our argument
	char string_input[length];
	// Copy argv[1] to our string_input
	strcpy(string_input, argv[1]);
	// Call is_symmetric function to check if string is symmetric 
	int check = is_symmetric(string_input, length + 1);
	// Check returned value, output appropriate message
	if ( check ) {
		printf("yes\n");
	} else {
		printf("no\n");
	}
	// Return 0 to signal succesful run
	return 0;
}

int is_symmetric(char string[], int length) {
	/* Initialize a string, equal length to string argument */
	char reverse_string[length];
	/* Copy string argument to reverse_string */
	strcpy(reverse_string, string);
	/* Reverse the string copy */
	reverse(reverse_string, 0, length - 2);
	/* Check if the string reverse equals the original string argument
	 * return 1 if true, otherwise the function will return 0 */
	if ( strcmp(string, reverse_string) == 0 ) {
		return 1;
	}
	return 0;
}

void reverse(char string[], int begin, int end) {
	/* As we're using recursion, we need a statement to stop infinite recursion
	 * This stops when we reach halfway through the string */
	if ( begin >= end ) {
		return;
	}

	/* Initialize temporary swap variable */
	char tmp;

	/* Swap the last character in our string with the first character */
	tmp = string[begin];
	string[begin] = string[end];
	string[end] = tmp;

	/* Call function again, incrementing begin, and decrementing end */
	reverse(string, ++begin, --end);
}

int counter(char string[]) {
	/* Initialize counter integer */
	int counter = 0;
	/* Iterate over string, incrementing counter until we reach the end */
	while ( string[counter] != '\0' ) {
		counter ++;
	}

	/* Return counter integer */
	return counter;
}
