/*
 * Author: Niall Ryan
 * Description: Program takes in data for shopping items
 * 		in a cart, each item accepts the;
 * 		1. item name
 * 		2. item amount
 * 		3. price
 * 		4. promotion (on sale or not)
 * 		Program should output for each item;
 * 		<Name>, <Amount>, <Price>, <Sale(1)/No Sale(0)>
 *
 * Approach: I plan to store all data inside a struct, using an
 * 	     array of that struct to store input data and iterate
 * 	     through. I'll fill the array from argv with a helper
 * 	     function, and furthermore display the data correctly
 * 	     with another helper function.
 *
 * Input: a list of item data from argv
 * Output: the <Name>, <Amount>, <Price>, <Sale(1)/No Sale(0)> for
 * 	   each item.
 *
 * Date: 03-11-22
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>

// Data Structures
typedef struct {
	char *name;
	int amount;
	float price;
	int sale;
} item;

// Function Prototypes
void fill_items(item *arr, int n, char **argv);
void display(item *arr, int n);

// Main function
int main(int argc, char **argv)
{
	// Initialize num_of_items to be equal to
	// how many 'shopping items' we can expect
	int num_of_items = (argc - 1) / 4;
	// Initialize an item pointer to hold our multiple shopping
	// items, allocating the memory manually.
	item *array = (item *)malloc(num_of_items * sizeof(item));
	// Ensure malloc didn't fail
	if (!array)
	{
		printf("Memory wasn't correctly allocated\n");
		return 1;
	}

	// Call fill_items function to fill our array from argv
	fill_items(array, num_of_items, argv);
	// Call display function to display our items from array
	display(array, num_of_items);

	// Ensure to free our manually allocated memory
	free(array);
	
	// Return 0 signals succesful execution
	return 0;
}

// Fill_items function takes in an array and length n
// as parameters, as well as argv. This function just
// fills the parameter array with the input data from
// argv.
void fill_items(item *arr, int n, char **argv)
{
	// Iterating through input array and argv
	for (int i = 0; i < n; ++i)
	{
		arr[i].name = *(argv + 1 + (i * 4));
		arr[i].amount = atoi(*(argv + 2 + (i * 4)));
		arr[i].price = atof(*(argv + 3 + (i * 4)));
		arr[i].sale = atoi(*(argv + 4 + (i * 4)));
	}

	return;
}

// Display function takes in an array as parameter, and
// the length n of the array. Function just iterates through
// the array of data and prints them correctly.
void display(item *arr, int n)
{
	// Iterating through array to display data
	for (int i = 0; i < n; ++i)
	{
		// Print current item's data
		printf("%s,%i,%.2f,", arr[i].name, arr[i].amount, arr[i].price);
		// Check if item is onsale or not & output result
		if (arr[i].sale == 0)
		{
			printf("No Sale\n");
		} else {
			printf("On Sale\n");
		}
	}

	return;
}
