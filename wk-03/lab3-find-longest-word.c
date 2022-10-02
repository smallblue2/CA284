/*
 * Author: Niall Ryan
 * Description: Find the longest word in a given sentence
 * Input: A sentence given from cmdline
 * Output: The longest word in the inputted sentence
 *
 */

/* Includes */
#include <stdio.h>
#include <string.h>

/* Function prototypes */
void largest(char *string);

/* Main function */
int main(int argc, char **argv) {

	largest(argv[1]);
	/* We return 0 for a succesful execution */
	return 0;
}

void largest(char *string) {
	int total_length = strlen(string);
	int longest_length = 0;
	int cur_length = 0;
	int index = 0;
	for ( int i = 0; i < total_length; ++i ) {
		if ( string[i] != ' ' ) {
			cur_length++;
		} else {
			if ( cur_length > longest_length ) {
				longest_length = cur_length;
				index = i - cur_length;
			}
			cur_length = 0;
		}
	}

	char output[longest_length + 1];
	int j = 0;
	for ( int i = index; i < longest_length; ++i ) {
		output[j] = string[i];
		j++;
	}
	printf("%s\n", output);
}
