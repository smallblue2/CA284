/* 
 * Author: Niall Ryan
 * Description: Program counts occurances of char in a string
 * Input: A single charater and string from cmd line
 * Output: A single integer, signalling occurences
 *
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
int count(char *str, char lookup);

// Main function
int main(int argc, char **argv) {
	// Take input from cmdline
	char input_char = argv[1][0];
	char input_string[strlen(argv[2]) + 1];
	strcpy(input_string, argv[2]);
	// Output the return from our count function	
	printf("%i\n", count(input_string, input_char));

	// Return 0 signals successful execution
	return 0;
}

/* Count function takes in a char pointer to char array and a single character.
 * Iterates over the character array at every instance of char argument.
 * Counts number of iterations and returns value. */
int count(char *str, char lookup) {
	char *pChar = str;
	int counter = 0;

	while (pChar = strchr(pChar, lookup)) {
		counter++;
		pChar++;
	}

	return counter;
}
