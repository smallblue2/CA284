// Parse a paragraph of text into sentences, storing the text and length in an array of structs.
//
// A sentence starts with any character except a space, and ends with a period or question mark.
// However, punctuation inside quotes don't end a sentence.
//
// The text is stored in a single string, and the sentence structs point into that string.
// The string is modified by replacing the end-of-sentence punctuation with a null character.
// The length of the sentence is stored in the struct.
// The last sentence in the paragraph is followed by a null character.
// The last sentence in the array is followed by a null pointer.
// 
// This uses standard libraries.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A sentence is a pointer to the start of the sentence, and the length of the sentence.
struct sentence {
    char *start;
    int length;
};

// Parse a paragraph of text into sentences, storing the text and length in an array of structs.
// The text is modified by replacing the end-of-sentence punctuation with a null character.
// The last sentence in the paragraph is followed by a null character.

struct sentence *parse(char *text, int *num_sentences) {
    // Allocate an array of sentence structs.
    struct sentence *sentences = malloc(100 * sizeof(struct sentence));
    if (sentences == NULL) {
	fprintf(stderr, "Out of memory");
	exit(1);
    }

    // Parse the text into sentences.
    int i = 0;
    int in_quote = 0;
    char *start = text;
    while (*text != '\0') {
	if (*text == '\'') {
	    in_quote = !in_quote;
	}
	if (!in_quote && (*text == '.' || *text == '?')) {
	    // Found the end of a sentence.
	    if (*(start) == ' ') {
		start += 1;
	    }
	    sentences[i].start = start;
	    sentences[i].length = text - start;
	    i++;
	    // Replace the end-of-sentence punctuation with a null character.
	    //*text = '\0';
	    start = text + 1;
	}
	text++;
    }
    *num_sentences = i;
    return sentences;
}

// Print the sentences in an array of sentence structs.

void print_sentences(struct sentence *sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
	printf("%.*s\n", sentences[i].length + 1, sentences[i].start);
	printf("%i\n", sentences[i].length);
    }
}

// Find the longest sentence in an array of sentence structs.

struct sentence *longest_sentence(struct sentence *sentences, int num_sentences) {
    struct sentence *longest = &sentences[0];
    for (int i = 1; i < num_sentences; i++) {
	if (sentences[i].length > longest->length) {
	    longest = &sentences[i];
	}
    }
    return longest;
}

// Find the shortest sentence in an array of sentence structs.

struct sentence *shortest_sentence(struct sentence *sentences, int num_sentences) {
    struct sentence *shortest = &sentences[0];
    for (int i = 1; i < num_sentences; i++) {
	if (sentences[i].length < shortest->length) {
	    shortest = &sentences[i];
	}
    }
    return shortest;
}

// Test the parse function.

int main(int argc, char **argv) {
    int num_sentences;
    struct sentence *sentences = parse(*(argv + 1), &num_sentences);
    //print_sentences(sentences, num_sentences);
    // If argv + 2 is equal to "Shortest", then print the shortest sentence.
    if (strcmp(*(argv + 2), "Shortest") == 0) {
	struct sentence *shortest = shortest_sentence(sentences, num_sentences);
	printf("%.*s\n", shortest->length + 1, shortest->start);
    }
    // If argv + 2 is equal to "Longest", then print the longest sentence.
    if (strcmp(*(argv + 2), "Longest") == 0) {
	struct sentence *longest = longest_sentence(sentences, num_sentences);
	printf("%.*s\n", longest->length + 1, longest->start);
    }
    free(sentences);
    return 0;
}
