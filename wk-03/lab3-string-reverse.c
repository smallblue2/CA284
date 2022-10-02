/* 
 * Author: Niall Ryan
 * Description: Reverses a given string
 * Input: Single string argument
 * Output: Input string reversed
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
int count(char *string);
void reverse(char *string, int being, int end);

/* Main function */
int main(int argc, char *argv[]) {
	
	/* Ensuring we're given an argument */
	if (argc == 2) {
		/* Initializing string argument to variable */
		char my_string[50];
		/* Copy string from cmd argument to variable */
		strcpy(my_string, argv[1]);

		/* Reverse our string */
		reverse(my_string, 0, count(my_string) - 1);
		/* Output our string after being reversed */
		printf("%s\n", my_string);
	} else {
		printf("One argument needed!\n");
	}

	/* Return 0 for successful execution */
	return 0;
}

/* Count function */
int count(char *string) {
	/* Initialize counter integer */
	int counter = 0;
	/* Iterate over string, incrementing counter until we reach the end */
	while ( string[counter] != '\0' ) {
		counter++;
	}
	/* Return counter integer */
	return counter;
}

/* Recursive reverse function */
void reverse(char *string, int begin, int end) {
	/* As we're using recursion, we need a statement to stop infinite recursion
	 * This stops when we reach halfway through the string */
	if ( begin >= end ) {
		return;
	}
	
	/* Initialize temporary tmp variable */
	char tmp;

	/* Swap the last character in our string with the first character */ 
	tmp = string[begin];
	string[begin] = string[end];
	string[end] = tmp;
	
	/* Call function again, reducing beginning and end integers */
	reverse(string, ++begin, --end);
}
