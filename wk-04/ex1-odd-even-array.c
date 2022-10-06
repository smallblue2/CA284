/*
 * Author: Niall Ryan
 * Approach:
 * 	1. Use helper function to integerise and index arguments into two seperate lists,
 * 	   even and odd.
 * 	2. Use helper function to iterate over even and odd array and return sum or difference
 * 	3. Output result in main
 * 
 * Date: 6-10-22
 *
 * Input: A list of integers
 * Output: The sum of all even numbers, and the difference of all odd numbers
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void smart_fill(int argc, char **argv, int *even_list, int *odd_list);
int smart_sum(int *list);

/* Main function */
int main(int argc, char **argv) {
	// Initialize even list, worst-case expected to store 50 integers. Default empty values to 0
	int even_list[50] = {0};
	// Initialize odd list, worst-case expected to store 50 integers. Default empty values to 0
	int odd_list[50] = {0};
	// Call smart_fill function, fills our two lists from input, sorting evens and odds
	smart_fill(argc, argv, even_list, odd_list);
	// Initialize even_total to the return of our smart_sum function, passing in our even list
	int even_total = smart_sum(even_list);
	// Initialize odd_total to the return of our smart_sum function, passing in our odd list
	int odd_total = smart_sum(odd_list);
	// Output our result
	printf("%i\n%i\n", odd_total, even_total);

	// Return 0 for succesful execution of script
	return 0;
}

/* Smart fill function */
void smart_fill(int argc, char **argv, int *even_list, int *odd_list) {
	// Initialize the length of our list
	int length = argc - 1;
	// We have to have seperate indexes for both our lists, as 'i' in our for loop
	// is iterating over our arguments
	int odd_index = 0;
	int even_index = 0;
	// Initialize a current variable, as we have to convert the element to an integer 
	// if we're to check if it's even or odd
	int current;
	// Iterate over our arguments
	for ( int i = 0; i < length; ++i ) {
		// Assign current to current element, converted to an integer
		current = atoi(argv[i + 1]);
		// Check if current is even or odd
		if ( current % 2 == 0 ) {
			// If even, add the current element to the even list
			even_list[even_index] = current;
			// Increment our even index by one
			even_index++;
		} else {
			// If odd, add the current element to the odd list
			odd_list[odd_index] = current;
			// Increment our even index by one
			odd_index++;
		}
	}
	// Our function is void, so we return nothing
	return;
}

/* Smart sum function */
int smart_sum(int *list) {
	// Initialise total variable to keep track of our calculations
	int total;
	// Check if our list is even or odd, by checking the first element
	if (list[0] % 2 == 0) {
		// Since we want the first number to be positive we assign total to it
		total = list[0];
		// As total is our firt element, our iteration begins at i = 1
		// and we iterate through the entire list
		for ( int i = 1; i < 50; ++i) {
			// We take away all numbers in our odd list from our original positive number
			total -= list[i];
		}
	} else {
		// Assign total to 0, as we're simply summing all elements in our even list
		total = 0;
		// Iterate through the entire list, summing each number
		for ( int i = 0; i < 50; ++i) {
			total += list[i];
		}
	}
	// Return our total number
	return total;
}
