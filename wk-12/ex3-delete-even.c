/* 
 * Author: Niall Ryan
 *
 * Description: Program accepts a list of poisitive integers from the command line
 * 		The program finds all even numbers and deletes them from the list
 * 		Program then calculates the sum of the remaining numbers
 * 		Prints out all numbers in the list and the sum
 *
 * Approach: 1. Use a doubly linked list to store the numbers
 * 	     2. Use a function to delete all even numbers from the list
 * 	     3. Use a function to calculate the sum of the remaining numbers
 * 	     4. Use a function to print out all numbers in the list
 * 	     5. Print the sum of the remaining numbers using the sum function
 * 	     6. Use a function to free the memory allocated to the list
 *
 * Date: 30/11/2022
 */

// Header files
#include <stdio.h>
#include <stdlib.h>

// Struct definitions
typedef struct node node;
typedef struct list list;

// Struct to store the numbers
struct node {
	int data;
	node *next;
	node *prev;
};

// Struct to store the head and tail of the list
struct list {
	node *head;
	node *tail;
};

// Function prototypes
void delete_even(list *l);
int sum(list *l);
void print_list(list *l);
void free_list(list *l);

// Main Function
int main(int argc, char **argv) {

	// Create a list
	list *l = malloc(sizeof(list));
	l->head = NULL;
	l->tail = NULL;

	// Add the numbers to the list
	for (int i = 1; i < argc; i++) {
		// Create a new node
		node *n = malloc(sizeof(node));
		n->data = atoi(argv[i]);
		n->next = NULL;
		n->prev = NULL;
		
		// Add the node to the list

		// If the list is empty
		if (l->head == NULL) {
			l->head = n;
			l->tail = n;
		} else {
			l->tail->next = n;
			n->prev = l->tail;
			l->tail = n;
		}
	}

	// Delete all even numbers from the list
	delete_even(l);

	// Declare our sum into a node and append it
	// to the end of our list
	node *n = malloc(sizeof(node));
	n->data = sum(l);
	n->next = NULL;
	n->prev = l->tail;
	l->tail->next = n;
	
	// Print out all numbers in the list
	print_list(l);

	// Print out the sum of the numbers
	//printf("%i\n", sum(l));

	// Free the memory allocated to the list
	free_list(l);

	return 0;
}

// Function to delete all even numbers from the list
void delete_even(list *l) {
	// Create a pointer to the head of the list
	node *current = l->head;
	// Create a temp pointer
	node *temp = NULL;
	// Loop through the list
	while (current != NULL) {
		// If the number is even
		if (current->data % 2 == 0) {
			// If the number is the head of the list
			if (current == l->head) {
				// Set the head to the next node
				l->head = current->next;
				// If the list is not empty
				if (l->head != NULL) {
					l->head->prev = NULL;
				}
				// Free the memory allocated to the node
				temp = current;
				current = current->next;
				free(temp);
			// Else, if the number is the tail of the list 
			} else if (current == l->tail) {
				// Set the tail to the previous node
				l->tail = current->prev;
				// If the list is not empty
				if (l->tail != NULL) {
					l->tail->next = NULL;
				}
				// Free the memory allocated to the node
				temp = current;
				current = current->next;
				free(temp);
			// Else, if the number is in the middle of the list
			} else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
				temp = current;
				current = current->next;
				free(temp);
			}
		// Else, if the number is odd
		} else {
			// Continue to next node
			current = current->next;
		}
	}
}

// Function to calculate the sum of the remaining numbers
int sum(list *l) {
	// Initialize a sum counter
	int sum = 0;
	// Create a pointer to the head of the list
	node *current = l->head;
	// Loop through the list
	while (current != NULL) {
		// Add the number to the sum
		sum += current->data;
		// Continue to next node
		current = current->next;
	}
	// Return the sum
	return sum;
}

// Function to print out all numbers in the list
void print_list(list *l) {
	// Create a pointer to the head of the list
	node *current = l->head;
	// Loop through the list
	while (current != NULL) {
		// Print out the data of the node
		printf("%i\n", current->data);
		current = current->next;
	}
}

// Function to free the memory allocated to the list
void free_list(list *l) {
	// Create a pointer to the head of the list
	node *current = l->head;
	// Create a temp pointer
	node *temp = NULL;
	// Loop through the list
	while (current != NULL) {
		// Free the memory allocated to the node
		temp = current;
		current = current->next;
		free(temp);
	}
}
