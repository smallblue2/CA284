/* 
 * Author: Niall Ryan
 *
 * Description: Program accepts n arguments of floating numbers.
 * 		The program is required to use doubly linked-list 
 * 		store all input numbers. Then, the program checks
 * 		whether the list of numbers is in descending 
 * 		numerical order. If the list is in descending order,
 * 		the program prints 1, otherwise, the program prints 0.
 *
 * Input: <n> <n> <n> <n> ...
 * Output: 1 or 0
 *
 * Approach: The program will read input numbers from the command.
 * 	     The program will store the input numbers in a doubly
 * 	     linked list.
 * 	     The program will check whether the list is in descending
 * 	     order.
 * 	     If the list is in descending order, the program will
 * 	     print 1, otherwise, the program will print 0.
 *
 * Date: 13 - 10 - 2022
 */

// Header files
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    double data;
    struct node *next;
    struct node *prev;
} nd;

// Function prototypes
nd *createNode(double);
void insertNode(nd **, nd *);
void printList(nd *);
int isDescending(nd *);
void freeList(nd *);

// Main function
int main(int argc, char *argv[]) {
    // Variables
    int i;
    nd *head = NULL;
    nd *newNode = NULL;

    // Check if there are enough arguments
    if (argc < 2) {
	printf("Error: Not enough arguments!");
	return 1;
    }

    // Create a linked list
    for (i = 1; i < argc; i++) {
	newNode = createNode(atof(argv[i]));
	insertNode(&head, newNode);
    }

    // Print the linked list (For Debugging)
    // printList(head); <- Uncomment this line to print the list

    // Check if the list is in descending order
    if (isDescending(head)) {
	printf("1\n");
    } else {
	printf("0\n");
    }

    // Free the memory
    freeList(head);
    
    // Return 0 for succesful execution
    return 0;
}

// Function definitions

// Create a new node
nd *createNode(double data) {
    // Allocate memory for the new node
    nd *newNode = (nd *) malloc(sizeof(nd));
    // Check if the memory is allocated succesfully
    if (!newNode) {
	printf("Error: Memory allocation failed!");
	exit(1);
    }
    // Assign data to the new node
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    // Return the new node
    return newNode;
}

// Insert a node to the linked list
void insertNode(nd **head, nd *newNode) {
    // Check if the list is empty
    nd *current = *head;
    if (!*head) {
	// Insert the new node to the head if it's empty
	*head = newNode;
    // else, insert the new node to the end of the list
    } else {
	while (current->next) {
	    current = current->next;
	}
	// Update relationships
	current->next = newNode;
	newNode->prev = current;
    }
}

// Print the linked list
void printList(nd *head) {
    // Check if the list is empty
    nd *current = head;
    // Print the list if it's not empty
    while (current) {
	printf("%.2f ", current->data);
	current = current->next;
    }
    // Print a new line
    printf("\n");
}

// Check if the list is in descending order
int isDescending(nd *head) {
    // Check if the list is empty
    nd *current = head;
    // Check if the list is in descending order
    while (current->next) {
	// If the current node is greater than the next node
	if (current->data < current->next->data) {
	    return 0;
	}
	// Move to the next node
	current = current->next;
    }
    // Return 1 if the list is in descending order
    return 1;
}

// Function to free doubly linked list
void freeList(nd *head) {
    // Check if the list is empty
    nd *current = head;
    nd *next = NULL;
    // Free the list if it's not empty
    while (current) {
	// Store the next node
	next = current->next;
	// Free the current node
	free(current);
	// Move to the next node
	current = next;
    }

    return;
}
