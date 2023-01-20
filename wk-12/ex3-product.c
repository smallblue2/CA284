/* 
 * Author: Niall Ryan
 *
 * Description: Program recieves input from command line
 * 		Stores information about a product <code, country, price>
 * 		The program finds all products whose origin country is "Ireland"
 * 		and multiplies the price by 1.2
 * 		Finally the program displays all products line by line
 *
 * Approach: 1. Use a struct to store the information about the product
 *           2. Use a linked list to store the products
 * 	     3. Use a function to find the products whose origin country is "Ireland"
 * 	     4. Use a function to multiply the price by 1.2
 * 	     5. Use a function to display all products line by line
 * 	     6. Use a function to free the memory allocated to the linked list
 * 
 * Input: <code> <country> <price> <code> <country> <price> ...
 * Output: <code>\n<country>\n<price>\n<code>\n<country>\n<price>\n...
 *
 * Date: 30/11/2022
 */

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Type definitions
typedef struct product prod;
typedef struct product_list prodlist;

// Struct to store the information about the product
// The struct contains a pointer to the next product
struct product {
    char *code;
    char *country;
    int price;
    struct product *next;
};

// Struct to store linked list of products
struct product_list {
    struct product *head;
    struct product *tail;
};

// Function prototypes
prodlist *new_product_list();
prod *new_product(char *code, char *country, int price);
void add_product(prodlist *list, prod *product);
void find_ireland(prodlist *list);
void display_products(prodlist *list);
void free_list(prodlist *list);

// Main function
int main(int argc, char **argv) {
    // Create a new product list
    prodlist *list = new_product_list();
    // Fill our product list with newly created
    // & filled products
    for (int i = 1; i < argc; i += 3) {
	char *code = malloc(strlen(argv[i]) + 1);
	strcpy(code, argv[i]);
	char *country = malloc(strlen(argv[i + 1]) + 1);
	strcpy(country, argv[i + 1]);
	int price = atof(argv[i + 2]);
	prod *product = new_product(code, country, price);
	add_product(list, product);
    }
    // Find the products whose origin country is "Ireland"
    // Multiplies the price by 1.2
    find_ireland(list);
    // Display all products line by line
    display_products(list);
    // Free the memory allocated to the linked list
    free_list(list);
    // Return 0
    return 0;
}

// Function to create a new product
// The function takes the code, country and price as input
// The function returns a pointer to the new product
prod *new_product(char *code, char *country, int price) {
    prod *new = malloc(sizeof(prod));
    new->code = code;
    new->country = country;
    new->price = price;
    new->next = NULL;
    return new;
}

// Function to create a new product list
// The function returns a pointer to the new product list
prodlist *new_product_list() {
    prodlist *new = malloc(sizeof(prodlist));
    new->head = NULL;
    new->tail = NULL;
    return new;
}

// Function to add a product to the product list
// The function takes the product list and the product as input
void add_product(prodlist *list, prod *product) {
    if (list->head == NULL) {
	list->head = product;
	list->tail = product;
    } else {
	list->tail->next = product;
	list->tail = product;
    }
}

// Function to find the products whose origin country is "Ireland"
// The function takes the product list as input
// The function multiplies the products' price by 1.2
void find_ireland(prodlist *list) {
    prod *current = list->head;
    while (current != NULL) {
	if (strcmp(current->country, "Ireland") == 0) {
	    current->price *= 1.2;
	}
	current = current->next;
    }
}

// Function to display all products line by line
// The function takes the product list as input
// The function displays the code, country and price of each product
void display_products(prodlist *list) {
    prod *current = list->head;
    while (current != NULL) {
	printf("%s\n", current->code);
	printf("%s\n", current->country);
	printf("%i\n", current->price);
	current = current->next;
    }
}

// Function to free the memory allocated to the linked list,
// takes the product list as input.
// Frees the memory allocated to each product
//  & the memory allocated to the product list
// The function sets the product list to NULL.
void free_list(prodlist *list) {
    prod *current = list->head;
    while (current != NULL) {
	prod *temp = current;
	current = current->next;
	free(temp);
    }
    free(list);
    list = NULL;
}

