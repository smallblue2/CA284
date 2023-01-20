/* 
 * Author: Niall Ryan
 *
 * Description: Program accepts n number of integers from command line.
 * 		The program then calculates the degree of the array and
 * 		prints it.
 *
 * Approach: 1. Accept n number of integers from the command line.
 * 	     2. Store these numbers in a linked list.
 * 	     3. Calculate the degree of the array.
 * 	     4. Print the degree of the array.
 * 	     5. Free the memory allocated to the linked list.
 * 
 * Input: n number of integers from command line.
 * Output: A single integer, the degree of the array.
 *
 * Date: 30/11/2022
 */

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
typedef struct list list;

// Node struct
struct node {
	int data;
	struct node *next;
};

// Linked list struct
struct list {
	struct node *head;
	struct node *tail;
};

// Function prototypes
void add_node(list *l, int data);
void free_list(list *l);
int degree(list *l);

// Main function
int main(int argc, char **argv) {
	// Create a linked list
	list *l = (list *)malloc(sizeof(list));
	l->head = NULL;
	l->tail = NULL;

	// Add nodes to the linked list
	for (int i = 1; i < argc; i++) {
		add_node(l, atoi(argv[i]));
	}

	// Calculate the degree of the array
	int d = degree(l);
	printf("%i\n", d);

	// Free the memory allocated to the linked list
	free_list(l);

	return 0;
}

// Function to add a node to the linked list
void add_node(list *l, int data) {
	// Create a new node
	node *new_node = malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;

	// If the linked list is empty
	if (l->head == NULL) {
		l->head = new_node;
		l->tail = new_node;
	}
	// If the linked list is not empty
	else {
		l->tail->next = new_node;
		l->tail = new_node;
	}
}

// Function to free the memory allocated to the linked list
void free_list(list *l) {
	// Create a temporary node
	node *temp = l->head;

	// Free the memory allocated to the linked list
	while (temp != NULL) {
		node *next = temp->next;
		free(temp);
		temp = next;
	}
}

// Function finds the most common number in the linked list and counts its frequency
int degree(list *l) {

	int most_occur = 0;
	// Create a temporary node
	node *temp = l->head;
	// While we're not at the end of the linked list
	while (temp != NULL) {
		// Count the frequency of the current node
		int count = 0;
		// Create another temporary node
		node *temp2 = l->head;
		// While we're not at the end of the linked list
		while (temp2 != NULL) {
			// If the data in the current node is equal to the data in the other node
			if (temp->data == temp2->data) {
				// Increment the count
				count++;
			}
			// Move to the next node
			temp2 = temp2->next;
		}
		// If the count is greater than the most_occur
		if (count > most_occur) {
			// Set most_occur to count
			most_occur = count;
		}
		// Move to the next node
		temp = temp->next;
	}

	// Return the degree of the linked list
	return most_occur;
}
