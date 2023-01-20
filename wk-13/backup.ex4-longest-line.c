/*
 * Author: Niall Ryan
 *
 * Description: Program accepts two inputs from cmd line.
 *              First input is the paragraph to be read.
 *              Second input is either 'longest' or 'shortest'.
 *              If the second input is either, the program will
 *              print "Not Valid!". If the second input is 'longest',
 *              the program will print the longest line in the paragraph,
 *              and the length. If the second input is 'shortest', the
 *              program will print the shortest line in the paragraph,
 *              and the length. A sentence is defined as starting with
 *              any character except a space, and ending with a period or
 *              a question mark or an exclamation mark. I have to use structs,
 *              linked lists, dynamic memory allocation and function pointers.
 *
 * Approach: I will use a linked list to store the sentences in the paragraph.
 *           I will use a struct to store the sentence and the length of the sentence.
 *           I will use a function pointer to point to the function that will print
 *           the shortest or longest sentence.
 *           I will use a function pointer to point to the function that will print
 *           the length of the shortest or longest sentence.
 *
 * Date: 13 - 12 - 2022
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sentence struct
typedef struct sentence {
    char *start;
    int length;
    struct sentence *next;
} stc;

typedef struct llist {
    stc *head;
    stc *tail;
} llist;

// Function Prototypes
stc *parse(char *text, int *num_sentences);
stc *shortest_sentence(struct sentence *sentences, int num_sentences);
stc *longest_sentence(struct sentence *sentences, int num_sentences);
void print_sentences(struct sentence *sentences, int num_sentences);

// Main Function
int main(int argc, char **argv) {
    int num_sentences;
    llist *list = malloc(sizeof(llist));
    stc *sentences = parse(*(argv + 1), &num_sentences);
    //print_sentences(sentences, num_sentences);
    // If argv + 2 is equal to "Shortest", then print the shortest sentence.
    if (strcmp(*(argv + 2), "shortest") == 0) {
	stc *shortest = shortest_sentence(sentences, num_sentences);
	printf("%i\n", shortest->length + 1);
	printf("%.*s\n", shortest->length + 1, shortest->start);
    // If argv + 2 is equal to "Longest", then print the longest sentence.
    } else if(strcmp(*(argv + 2), "longest") == 0) {
	stc *longest = longest_sentence(sentences, num_sentences);
	printf("%i\n", longest->length + 1);
	printf("%.*s\n", longest->length + 1, longest->start);
    } else {
	    printf("Not valid!\n");
    }
    free(sentences);
    return 0;
}

// Find the shortest sentence in an array of sentence structs.
stc *shortest_sentence(struct sentence *sentences, int num_sentences) {
    struct sentence *shortest = &sentences[0];
    for (int i = 1; i < num_sentences; i++) {
	if (sentences[i].length < shortest->length) {
	    shortest = &sentences[i];
	}
    }
    return shortest;
}

// Find the longest sentence in an array of sentence structs.
stc *longest_sentence(struct sentence *sentences, int num_sentences) {
    struct sentence *longest = &sentences[0];
    for (int i = 1; i < num_sentences; i++) {
	if (sentences[i].length > longest->length) {
	    longest = &sentences[i];
	}
    }
    return longest;
}

// Print the sentences in an array of sentence structs.
void print_sentences(struct sentence *sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
	printf("%.*s\n", sentences[i].length + 1, sentences[i].start);
	printf("%i\n", sentences[i].length);
    }
}

stc *parse(char *text, int *num_sentences) {
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
	    start = text + 1;
	}
	text++;
    }
    *num_sentences = i;
    return sentences;
}
