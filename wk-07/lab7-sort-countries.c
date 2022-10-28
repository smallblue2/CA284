/* 
 * Author: Niall Ryan
 * Description: Takes country data as input in cmd args and 
 * 		inserts into country data structures, sorts
 * 		and displays them in a table format
 *
 * Input: Country data taken from cmd line
 * Output: A table of sorted country data
 *
 */

// Header files
#include <stdio.h>
#include <stdlib.h>

// Type Definitions
typedef struct Country cty;

// Data Structures
struct Country
{
	char *name;
	char *capital;
	int size;
	float population;
};

// Function Prototypes
void fill_list(cty *list, int len, char **argv);
cty add_country(int i, char **argv);
void display(cty *list, int len);
void sort_list(cty *list, int len);
void swap(cty *pX, cty *pY);

// Main Function
int main(int argc, char **argv)
{
	// Initializing number of countries
	int num_of_countries = argc / 4;
	// Initializing country list of length num countries
	cty countries[num_of_countries];

	// Call fill_list function to fill our country list
	fill_list(countries, num_of_countries, argv);
	// Sort our list
	sort_list(countries, num_of_countries);
	// Display our filled list
	display(countries, num_of_countries);

	// Return 0 to signal succesful execution
	return 0;
}

/* Fill list function fills the given array */
void fill_list(cty *list, int len, char **argv)
{
	// Iterates over array
	for (int i = 0; i < len; ++i)
	{
		// Calls add_country for each element of the array
		// and equals it to the function's return
		list[i] = add_country(i, argv);
	}
}

// Add_country returns a country, defined from argv
cty add_country(int i, char **argv)
{
	cty cur_cty;
	// Index allows us to group data from argv
	// in groups of 4. First country is 1-5,
	// next country is 5-9, and so on.
	int index = i * 4;
	cur_cty.name = argv[index + 1];
	cur_cty.capital = argv[index + 2];
	cur_cty.population = atof(argv[index + 3]);
	cur_cty.size = atoi(argv[index + 4]);

	return cur_cty;

}

// Displays country data in a table format
void display(cty *list, int len)
{
	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
	
	for (int i = 0; i < len; ++i)
	{
		printf("%s\t\t\t", list[i].name);
		printf("%s\t\t\t", list[i].capital);
		printf("%i\t\t\t", list[i].size);
		printf("%.2f\n", list[i].population);
	}

	return;
}

// sort_list implements bubblesort on the countries list
// on the basis of each countries' population
void sort_list(cty *list, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (list[i].population < list[i + 1].population) {
				swap(&list[i], &list[i + 1]);
				i = 0;
				j = 0;
			}
		}
	}
}

// Our swap function just swaps the addresses values
// to the addresses passed in
void swap(cty *pX, cty *pY)
{
	cty tmp = *pX;
	*pX = *pY;
	*pY = tmp;
	
	return;
}
