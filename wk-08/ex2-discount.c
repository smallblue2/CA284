/*
 * Author: Niall Ryan
 * Description: Program takes in shopping cart data and
 * 		organises it into the custom item data structure.
 * 		Finally calculating the price and displaying the
 * 		total cost.
 *
 * Approach: I will create a function that calculates the price of
 * 	     a passed in item, and a function that calculates the total
 * 	     price, calling the total calculation function in my main,
 * 	     and outputting using print.
 *
 * Input: a list of item data from argv
 * Output: a single integer, the total cost of the shopping cart
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
float calc_total(item *grocery, int n);
float calc_item_price(item *grocery);

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
	// Output the return of calc_total on our array of items
	printf("%.2f\n", calc_total(array, num_of_items));

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

// Calc_item_price takes in a single parameter,
// which is an item pointer, pointing to one item.
// It calculates the price based on if it's on sale
// or not, and returns it's price.
float calc_item_price(item *grocery)
{
	if (grocery->sale == 1)
	{
		// Initialises reduction as the amount of groceries to be subtracted
		// from total price due to sale.
		int reduction = grocery->amount / 3;
		// Returns price of grocery based on sale.
		return (grocery->amount * grocery->price) - (reduction * grocery->price);
	}
	// Returns grocery total price
	return (grocery->amount * grocery->price);
}

// Calc_total function takes in an item pointer of n
// length, iterating over the items it contains and
// calling calc_item_price on each item, summing the
// return to a total counter, and returning total.
float calc_total(item *grocery, int n)
{
	// Initialise total as a counter to keep track
	// of total price
	float total = 0;

	// Iterates over all items, calling calc_item_price and
	// adding the return to total
	for (int i = 0; i < n; ++i)
	{
		total += calc_item_price(&*(grocery + i));
	}
	
	// Returns total price calculated
	return total;
}
