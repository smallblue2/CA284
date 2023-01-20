/*
 * Author: Niall Ryan
 *
 * Description: This program takes a list of integers from
 *         the command line, and removes all duplicate
 *         elements from the list. Outputting only unique
 *         numbers.
 * 
 * Input: A list of integers from the command line.
 * Output: A list of unique integers.
 *
 * Approach: The program will take in a list of integers from the
 *          command line, and store them in a linked list of
 *          structs. 
 *          The program will then uses a nested for loop to compare
 *          each element of the list to every other element.
 *          If a duplicate is found, the duplicate is removed from
 *          the list, including the first instance of the duplicate.
 *          The program will then output the list of unique integers.
 *
 * Date: 13 - 10 - 2022
 */

//Relevant Libraries
#include <stdio.h>
#include <stdlib.h>

//Structure Definitions
typedef struct Node nd;

// Structure for a node in a linked list
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

//Function Prototypes
nd* createList(int argc, char **argv);
void printList(nd*);
void removeDuplicates(nd*);
void freeList(nd*);

//Main
int main(int argc, char **argv) {
    // Create a linked list from the command line arguments
    nd *linklist = createList(argc, argv);
    // Remove the duplicates
    removeDuplicates(linklist);
    // Print the list
    printList(linklist);
    // Free the memory allocated to the list
    freeList(linklist);
    // Return 0 to indicate successful completion
    return 0;
}

// Function to create a linked list from the command line arguments
nd* createList(int argc, char **argv) {
    // Create the head of the list
    nd *head = malloc(sizeof(nd));
    // Create a pointer to the current node
    nd *cur;
    // Set the head to point to the first node
    head->next = malloc(sizeof(nd));
    // Set the current node to the first node
    cur = head->next;
    // Iterate through the command line arguments
    for (int i=0; i < argc - 1; i++) {
	// Fill the data of the current node
        nd *temp = cur;
        cur->next = malloc(sizeof(nd));
        cur->data = atoi(*(argv + i + 1));
        cur = cur->next;
        cur->prev = temp;
    }
    // Return the head of the list
    return head;
}

// Function to print the list
void printList(nd* head){
    // Iterate through the linked list
    for (nd* cur = head->next; cur->next != NULL; cur = cur->next) {
	// Print the data of the current node
        printf("%d\n", cur->data);
    }
}

// Function to remove duplicates from the list
void removeDuplicates(nd* head){
    // Initialise our variables
    nd *cur;
    nd *temp;
    nd *dup;
    nd hold;
    int isDup = 0;
    // Set cur to the first node
    cur = head->next;
    // Keep track of the previous node, head
    cur->prev = head;
    // Iterate through the list
    while (cur->next != NULL) {
	// Set temp to the current node
        temp = cur;
	// Iterate through the list again
        while (temp->next != NULL) {
            // Check if the current node is a duplicate
	    if (cur->data == temp->next->data) {
		// Remove the duplicate node
                temp->next = temp->next->next;
                temp->next->prev = temp;
		// Raise our isDup flag, so that we
		// know to remove the original
                isDup = 1;
            } else {
		// If no dupe is found, just move on
                temp = temp->next;
            }
        }
	// If we found a duplicate, remove the original
        if(isDup == 1){
	    // Removing the original
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
	    // Reset the isDup flag
            isDup = 0;
        }
	// Move on to the next node
        cur = cur->next;
    }
}

// Function that frees the memory allocated to the linked list
void freeList(nd *head) {
    // Initialize variables
    nd *cur = head;
    nd *temp;
    // Iterate through the list, freeing memory
    // as we go.
    while (cur->next != NULL) {
	temp = cur;
	cur = cur->next;
	free(temp);
    }
    // Free the last node
    free(cur);
}
