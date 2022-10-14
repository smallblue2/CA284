/* 
 * Author: Niall Ryan
 * Description: Programme accepts two arguments, two strings
 * 		The first string is the main string,
 * 		The second string is the one to search for.
 * 		Programme outputs the first and last character
 * 		of the string.
 *
 * 		Wanted to avoid using string.h as a challenge
 * 		Used malloc to understand memory allocation better
 *
 * Input: Two strings from command line arguments
 * Output: Two integers if the string is found
 *
 */

// Includes
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void take_input(char *str_1, char *str_2, char **argv);
long unsigned int len(const char *str);
int string_search(char *key, char *string);

// Main Function
int main(int argc, char **argv) {

	// Take string inputs from argv
	// Assign char pointers to char pointer allocated with just enough space
	char *string = (char *)malloc((len(argv[1]) + 1) * sizeof(char));
	char *key = (char *)malloc((len(argv[2]) + 1) * sizeof(char));

	// Take input string assigns input to both strings from argv
	take_input(string, key, argv);
	// Initiate index to the return of string_search
	int index = string_search(key, string);
	
	// Output our index's of found word, if one was found
	if (index != 0) {
		printf("%i %lu\n", index, index + len(key) - 1);
	}

	// Return 0 signals succesful execution
	return 0;
}

// take_input assigns strings from argv to char pointers
void take_input(char *str_1, char *str_2, char **argv) {

	int i = 0;
	while (argv[1][i] != '\0') {
		str_1[i] = argv[1][i];
		i++;
	}
	str_1[i] = '\0';
	i = 0;
	while (argv[2][i] != '\0') {
		str_2[i] = argv[2][i];
		i++;
	}
	str_2[i] = '\0';

	return;
}

// len returns length of a given string
long unsigned int len(const char *str) {
	int i;
	for (i = 0; str[i] != '\0'; ++i);
	return i;
}

// String search searches for the key string in the larger string
int string_search(char *key, char *string) {

	// Initiate all variables required
	int length = len(key);
	int count = 0;
	int i = 0;
	int index = 0;
	// Basically linear search algorithm that tracks
	// current index, found index, and num. of matched characters.
	// If num of matched characters equals length of key string,
	// return the index.
	while (string[i] != '\0') {
		if (string[i] == key[0]) {
			index = i;
			count++;
		} else if (string[i] == key[count]) {
			count++;
		}
		if (count == length) {
			return index;
		}
		i++;
	}

	// Return 0 signals nothing was found.
	return 0;
}
