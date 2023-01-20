// Parse a paragraph of text into sentences.
// A sentence starts with any character except a space, and ends with a period or question mark.
// However, punctuation inside quotes don't end a sentence.
// This uses standard libraries.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function
int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
	printf("Usage: ./sentence text");
	return 1;
    }

    // Get text
    char *text = argv[1];

    // Count sentences
    int sentences = 0;
    int length = strlen(text);
    int start = 0;
    for (int i = 0; i < length; i++) {
	if (text[i] == '.' || text[i] == '?') {
	    sentences++;
	    
	}

	// Check for quotes
	if (text[i] == '\'') {
	    // Skip to next quote
	    while (text[i] != '\'') {
		i++;
	    }
	}
    }
    // Print number of sentences
    printf("%i\n", sentences);
    return 0;
}
