/* 
 * Author: Niall Ryan
 * Description: Recieves country information from cmd line
 * 		and outputs line by line.
 *
 * Input: Two strings, a float, and an integer
 * Output: Country information, line by line
 *
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining my type Country as Country
typedef struct Country Country;

// Country data structure
struct Country
{
	char *name;
	char *capital;
	float population;
	int area;
};


// Main Function
int main(int argc, char **argv)
{
	// Initializing country as Country type, with information taken from cmd line
	Country country = {argv[1], argv[2], atof(argv[3]), atoi(argv[4])};

	// Displaying all information stored in country line by line
	printf("%s\n", country.name);
	printf("%s\n", country.capital);
	printf("%.2f million people\n", country.population);
	printf("%i km2\n", country.area);

	// Returning 0 signals succesful execution
	return 0;
}
