/* 
 * Author: Niall Ryan
 * Description: Takes cmd line argument and prints the correlating day of the week
 * Input: Single integer from cmd line
 * Output: A string including the day of the week
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Main function */
int main(int argc, char *argv[]) {
	
	/* Ensuring one single argument exists */
	if ( argc != 2 ) {
		printf("One argument required\n");
		return 0;
	}

	/* Creating a constant array of strings */
	const char *days_of_week[] = {
		"Sunday", "Monday",
		"Tuesday", "Wednesday",
		"Thursday", "Friday",
		"Saturday"};
	
	/* Declaring day variable */
	int day = atoi(argv[1]) - 1;

	/* Ensuring day variable is valid */
	if ( day > 6 || day < 0 ) {
		printf("Argument Invalid (Must be between 1 - 7)\n");
		return 0;
	}

	/* Output corresponding day to argument */
	printf("%s\n", days_of_week[day]);
}
