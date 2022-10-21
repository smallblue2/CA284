/* 
 * Author: Niall Ryan
 * Description: Lists country input data in a table format using structs
 *
 * Input: various types of data from cmd line
 * Output: A table of the input data
 *
 */

// Includes
#include <stdio.h>
#include <stdlib.h>

// Country data structure
struct Country
{
	char *name;
	char *capital;
	unsigned int area;
	float population;
};

// Defining a shorthand for our Country structure
typedef struct Country cty;

// Function Prototypes
void fill_countries(cty *countries, int n, char **argv);
void display(cty *countries, int n);

// Main function
int main(int argc, char **argv)
{
	// Initialize num of countries
	int num_of_countries = argc / 4;
	// Initialize array of countries
	cty country_table[num_of_countries];

	// Call fill_countries function to fill our country data types
	// inside our country_table array
	fill_countries(country_table, num_of_countries, argv);
	// Display our country_table
	display(country_table, num_of_countries);

	// Return 0 signifies succesful execution
	return 0;
}

void fill_countries(cty *countries, int n, char **argv)
{
	// Initialize index variable to keep track of our argv index
	int index = 1;

	// Iterate over our countries array
	for ( int i = 0; i < n; ++i )
	{
		// Assign field data
		countries[i].name = argv[index];
		countries[i].capital = argv[index + 1];
		countries[i].area = atoi(argv[index + 3]);
		countries[i].population = atof(argv[index + 2]);

		// Increase index by 4 to acces next country's data
		index += 4;
	}

	return;
}

void display(cty *countries, int n)
{
	// Display column labels
	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
	// Iterate over our countries array to display each country's data
	for ( int i = 0; i < n; ++i)
	{
		printf("%s\t\t\t", countries[i].name);
		printf("%s\t\t\t", countries[i].capital);
		printf("%i\t\t\t", countries[i].area);
		printf("%.2f\n", countries[i].population);
	}

	return;
}
