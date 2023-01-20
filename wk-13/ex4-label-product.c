/* 
 * Author: Niall Ryan
 *
 * Description: This program takes product information for a number of products
 *              from the command line. Each product has an item code, a price and
 *              the number sold. The program will calculate the total sales by multiplying
 *              the price by the number sold. The program will also calculate the total
 *              sales for all products. Products whose total sales are greater than or
 *              equal to the average sales of all items will have a status equal to 1,
 *              otherwise status will be 0. The program will then print the status of
 *              each product, followed by the country of origin. The country of origin
 *              is found by the first two letters of the item code. IE = Ireland, US = USA,
 *              FR = France, SP = Spain, RU = Russia.
 *
 * Input: ./ex4-label-product <item code> <price> <number sold> <item code> <price> <number sold> ...
 * Output: <status>\n<country of origin>\n<status>\n<country of origin> ...
 *
 * Approach: The program will first check that the number of arguments is a multiple of 3.
 *           If it is not, the program will print an error message and exit. 
 *	     The program will read input and place it into a linked list of product structs.
 *           The program will then calculate the total sales for each product and the total sales for
 *           all products.
 *           The program will then calculate the average sales of all products.
 *           The program will then calculate the status of each product.
 *           The program will then print the status of each product, followed by the country of origin.
 *
 * Date: 13 - 12 - 2022
 */

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs
typedef struct product {
    char *item_code;
    float price;
    int number_sold;
    float total_sales;
    int status;
    struct product *next;
} pdt;

// Function prototypesi
void printList(pdt *head);
void freeList(pdt *head);
void calculateTotalSales(pdt *head);
void calculateAverageSales(pdt *head, int num_products);
void calculateStatus(pdt *head, float average_sales);
void printStatus(pdt *head);

// Main function
int main(int argc, char **argv) {
    // Check that the number of arguments is a multiple of 3
    if ((argc - 1) % 3 != 0) {
	printf("Error: Invalid number of arguments. Please enter a multiple of 3 arguments.\n");
	return 1;
    }

    // Create a linked list of product structs
    pdt *head = NULL;
    pdt *current = NULL;
    pdt *previous = NULL;
    int num_products = (argc - 1) / 3;
    // Iterate through the arguments, inputting them into the linked list
    for (int i = 1; i < argc; i += 3) {
	// Allocate memory for the product struct
	current = (pdt *) malloc(sizeof(pdt));
	// Check that memory was allocated
	if (!current) {
	    printf("Error: Memory could not be allocated.\n");
	    return 1;
	}
	// Input struct data
	current->item_code = argv[i];
	current->price = atof(argv[i + 1]);
	current->number_sold = atoi(argv[i + 2]);
	// Set the next pointer to NULL
	current->next = NULL;
	// Check if this is the first product
	if (head == NULL) {
	    // Set the head to the first product
	    head = current;
	} else {
	    // Set the previous product's next pointer to the current product
	    previous->next = current;
	}
	// Set the previous product to the current product
	previous = current;
    }

    // Calculate the total sales for each product
    calculateTotalSales(head);

    // Calculate the total sales for all products
    float total_sales = 0;
    current = head;
    while (current) {
	total_sales += current->total_sales;
	current = current->next;
    }

    // Calculate the average sales of all products
    float average_sales = total_sales / num_products;

    // Calculate the status of each product
    calculateStatus(head, average_sales);

    // Print the status of each product, followed by the country of origin
    printStatus(head);

    // Free the linked list
    freeList(head);

    return 0;
}

// Function definitions

// Print the linked list (Purely for a debugging perspective)
void printList(pdt *head) {
    // Iterate through the linked list
    pdt *current = head;
    while (current) {
	// Print the product data
	printf("%s %f %d %f %d\n", current->item_code, current->price, current->number_sold, current->total_sales, current->status);
	// Move to the next product
	current = current->next;
    }
}

// Free the linked list
void freeList(pdt *head) {
    // Iterate through the linked list
    pdt *current = head;
    pdt *next = NULL;
    // Free each product
    while (current) {
	next = current->next;
	free(current);
	current = next;
    }
}

// Calculate the total sales for each product
void calculateTotalSales(pdt *head) {
    // Iterate through the linked list
    pdt *current = head;
    // Calculate the total sales for each product
    while (current) {
	// Input the total sales to the struct data
	current->total_sales = current->price * current->number_sold;
	current = current->next;
    }
}

// Calculate the average sales of all products
void calculateAverageSales(pdt *head, int num_products) {
    // Calculate the total sales for all products
    float total_sales = 0;
    pdt *current = head;
    // Iterate through the linked list
    while (current) {
	// Add all individual sales to the total counter
	total_sales += current->total_sales;
	current = current->next;
    }
    // Calculate the average sales for all products
    float average_sales = total_sales / num_products;
}

// Calculate the status of each product
void calculateStatus(pdt *head, float average_sales) {
    // Iterate through the linked list
    pdt *current = head;
    while (current) {
	// Check if the total sales is greater than the average sales
	if (current->total_sales >= average_sales) {
	    // Set the status to 1 if it is
	    current->status = 1;
	} else {
	    // Else, set the status to 0
	    current->status = 0;
	}
	// Move to the next product
	current = current->next;
    }
}

// Print the status of each product, followed by the country of origin
void printStatus(pdt *head) {
    // Iterate through the linked list
    pdt *current = head;
    while (current) {
	// Print the status
	printf("%i\n", current->status);
	// Print the country of origin
	if (strncmp(current->item_code, "IE", 2) == 0) {
	    printf("Ireland\n");
	} else if (strncmp(current->item_code, "US", 2) == 0) {
		printf("USA\n");
	} else if (strncmp(current->item_code, "FR", 2) == 0) {
		printf("France\n");
	} else if (strncmp(current->item_code, "SP", 2) == 0) {
		printf("Spain\n");
	} else if (strncmp(current->item_code, "RU", 2) == 0) {
		printf("Russia\n");
	}
	// Move to the next product
	current = current->next;
    }
}
