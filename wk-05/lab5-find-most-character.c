/* 
 * Author: Niall Ryan
 * Description: Program output most occurent char in a string
 * Input: A single string from cmd line
 * Output: A single char
 *
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
int count(char *str, char lookup);
char most(char *str);

// Main function
int main(int argc, char **argv) {
	// Take input from cmdline
	char input_string[strlen(argv[1]) + 1];
	strcpy(input_string, argv[1]);
	
	// Output the return of most function
	printf("%c\n", most(input_string));

	// Return 0 signals successful execution
	return 0;
}

/* Most function has a single string argument and returns a single character.
 * Iterates over the string given, and counts the occurence of every character
 * by calling the count function. Everytime a new max is found, we replace our
 * max_number, and keep hold of the character */
char most(char *str) {
	char common;
	int max_num;
	int cur_num;
	

	char *pStr = str;
	while (*pStr != '\0') {
		cur_num = count(str, *pStr);
		if (cur_num > max_num & *pStr != ' ') {
			max_num = cur_num;
			common = *pStr;
		}
		pStr++;
	}

	return common;
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
