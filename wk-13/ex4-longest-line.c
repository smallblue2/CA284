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
 * Approach: I will use a linked list to store the list in the paragraph.
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

// Linked List struct
typedef struct llist {
    stc *head;
    stc *tail;
} llist;

// Function Prototypes
void parse(char *text, int *num_list, llist *list);
stc *shortestSentence(llist *list, int num_list);
stc *longestSentence(llist *list, int num_list);
void printList(llist *list, int num_list);
void printSentence(stc *sentence);
void freeList(llist *list);

// Main Function
int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 3) {
	printf("Not valid!\n");
	return 0;
    }
    // Check if the second argument is valid
    if (strcmp(argv[2], "longest") != 0 && strcmp(argv[2], "shortest") != 0) {
	printf("Not valid!\n");
	return 0;
    }
    int num_list;
    // Create our linked list
    llist *list = malloc(sizeof(llist));
    // Parse the paragraph and store it in the linked list
    parse(*(argv + 1), &num_list, list);
    // Create a function pointer to point to the function that 
    // will print the shortest or longest sentence
    stc *(*sentence)(llist *, int);
    // Figure out which function to point to
    if (strcmp(*(argv + 2), "shortest") == 0) {
	// Point to the shortestSentence function
	sentence = shortestSentence;
    } else if (strcmp(*(argv + 2), "longest") == 0) {
	// Point to the longestSentence function
	sentence = longestSentence;
    }
    // Print the return sentence from the function pointer
    printSentence(sentence(list, num_list));
    // Free the linked list
    freeList(list);
    // Return 0 to indicate success
    return 0;
}

// Free the list
void freeList(llist *list) {
    // Create a temp pointer to the head of the list
    stc *temp = list->head;
    // Iterate through the list
    while (temp != NULL) {
	// Create a temp pointer to the next node
	stc *temp2 = temp->next;
	// Free the current node
	free(temp);
	// Set the current node to the next node
	temp = temp2;
    }
}

// Print a sentence
void printSentence(stc *sentence) {
    // Print the sentence length
    printf("%i\n", sentence->length + 1);
    // Print the sentence, specifying field width and precision
    printf("%.*s\n", sentence->length + 1, sentence->start);
    // Return
    return;
}

// Find the shortest sentence in an array of sentence structs.
stc *shortestSentence(llist *list, int num_list) {
    // Create a temp pointer to the head of the list
    stc *shortest = list->head;
    // Iterate through the list
    stc *current = list->head;
    while (current) {
	// Check if the current sentence is shorter than the shortest sentence
	if (current->length < shortest->length) {
	    // Set the shortest sentence to the current sentence
	    shortest = current;
	}
	// Set the current sentence to the next sentence
	current = current->next;
    }
    // Return the shortest sentence
    return shortest;
}

// Find the longest sentence in an array of sentence structs.
stc *longestSentence(llist *list, int num_list) {
    // Create a temp pointer to the head of the list
    stc *longest = list->head;
    // Iterate through the list
    stc *current = list->head;
    while (current) {
	// Check if the current sentence is longer than the longest sentence
	if (current->length > longest->length) {
	    // Set the longest sentence to the current sentence
	    longest = current;
	}
	// Set the current sentence to the next sentence
	current = current->next;
    }
    // Return the longest sentence
    return longest;
}

// Print the list in an array of sentence structs.
void printList(llist *list, int num_list) {
    // Create a temp pointer to the head of the list
    stc *current = list->head;
    // Iterate through the list
    while (current != NULL) {
	// Print the sentence, specifying field width and precision
	printf("%.*s\n" , current->length + 1, current->start);
	// Set the current sentence to the next sentence
	current = current->next;
    }
}

// Parse the paragraph and store it in the linked list
void parse(char *text, int *num_list, llist *list) {
    // Create initial variables
    int i = 0;
    int in_quote = 0;
    // Create a temp pointer to the head of the list
    char *start = text;
    // Iterate through the paragraph
    while (*text != '\0') {
	// Check if the current character is a quotation mark
	if (*text == '\'') {
	    // Switch the in_quote variable
	    in_quote = !in_quote;
	}
	// Check if the current character is a question mark or an exclamation mark
	if (!in_quote && (*text == '.' || *text == '?')) {
	    // Create a new node
	    stc *new = malloc(sizeof(stc));
	    // If start is equal to a space character
	    if (*(start) == ' ') {
		// Increment start to skip the space.
		start++;
	    }
	    // Set the start of the sentence in the new node
	    new->start = start;
	    // Set the length of the sentence in the new node
	    new->length = text - start;
	    // Input the node to the linked list
	    if (!list->head) {
		list->head = new;
		list->tail = new;
	    } else {
		list->tail->next = new;
		list->tail = new;
	    }
	    // Increment the number of sentences
	    i++;
	    // Set the start of the next sentence
	    start = text + 1;
	}
	// Increment the text pointer
	text++;
    }
    // Set the number of sentences
    *num_list = i;
}
