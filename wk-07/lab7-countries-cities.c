/*
 * Author: Niall Ryan
 * Description: Finds the largest cities in each country
 * 		and outputs it.
 *
 * Input: Multiple country data of contained cities
 * Output: The largest cities in each individual country inputted
 *
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>

// Data Type Definitions
typedef struct Country cty;
typedef struct City cities;

// Data Structures
struct Country
{
	char *name;

	struct City
	{
		char *name;
		float size;
	} cities[3];
};

// Function Prototypes
void fill(cty *arr, int len, char **argv);
cty add_country(int i, char **argv);
char *largest(cities arr[3]);

// Main Function
int main(int argc, char **argv)
{
	// Initialize the number of countries
	int num_of_cty = argc / 7;
	// Initialize country list
	cty countries[num_of_cty];

	// Call fill function to fill our countries list
	fill(countries, num_of_cty, argv);

	// Output the largest city of each country, calling the largest function
	for (int i = 0; i < num_of_cty; ++i)
	{
		printf("%s: %s\n", countries[i].name, largest(countries[i].cities));
	}

	// Return 0 to signal succesful execution
	return 0;
}

// Fill function fills our countries list with data from argv
void fill(cty *arr, int len, char **argv)
{
	for (int i = 0; i < len; ++i)
	{
		// Indexes arr[i] to be the return of the add_country function
		arr[i] = add_country(i ,argv);
	}

	return;
}

// Takes information from the command line and places it into
// a country data type, returning it at the end
cty add_country(int i, char **argv)
{
	int index = i * 7;
	cty cur_cty;
	cur_cty.name = argv[index + 1];
	for (int j = 0; j < 3; ++j)
	{
		cur_cty.cities[j].name = argv[index + 2 + (j * 2)];
		cur_cty.cities[j].size = atof(argv[index + 3 + (j * 2)]);
	}

	return cur_cty;
}

// Largest function performs linear search to find the largest
// city in our cities list and returns the name
char *largest(cities arr[3])
{
	char *largest = NULL;
	int size = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (arr[i].size > size)
		{
			largest = arr[i].name;
			size = arr[i].size;
		}
	}
	
	return largest;
}
