/* 
 * Author: Niall Ryan
 * Description: Displays all leap years between two inputted years
 *
 * Input: Two years from cmd line argument
 * Output: All leap years inbetween
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void display(int y1, int y2);

// Main Function
int main(int argc, char **argv)
{
	// Initialize inputted years as functions
	int y1 = atoi(argv[1]);
	int y2 = atoi(argv[2]);

	// Call display function to printf leap years
	display(y1, y2);

	// Return 0 signals succesful exectuion
	return 0;
}

void display(int y1, int y2)
{
	// Initialize cur variable to keep track of years
	// between y1 and y2
	int cur = y1;
	// Iterate through years
	while (cur <= y2)
	{
		// Check if it's a leap year
		if ( (cur % 4 == 0) && ((cur % 100 != 0) || (cur % 400 == 0)) )
		{
			// If it's a leap year, print it
			printf("%i\n", cur);
		}
		// Increment to next year
		cur += 1;
	}
	// Return as function is void
	return;
}
