/* 
 * Author: Niall Ryan
 * Description: Program accepts in two vectors and outputs
 * 		their dot-product.
 *
 * Input: From cmd args, first int is the size of the two
 * 	  the two vectors, following integers are the elements
 * 	  of the two vectors.
 *
 * Output: The dot product of the two vectors
 */

// Header files
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int *vec(int dim, char **argv, int start);
void display(int *vec, int dim);
int dot_product(int *vec1, int *vec2, int n);

// Main function
int main(int argc, char **argv)
{
	// Initialize dim as the dimension of our vectors
	// from cmd line
	int dim = atoi(argv[1]);

	// Initialize both int pointers as the return of
	// our vec function
	int *vec1 = vec(dim, argv, 0);
	int *vec2 = vec(dim, argv, dim);

	// Ensure our vectors were created succesfuly
	if (vec1 == NULL || vec2 == NULL)
	{
		printf("Failed to allocate memory for vectors\n");
		return 0;
	}

	// Print the output of the return of our dot_product
	// function when passed both our vectors as arguments
	printf("%i\n", dot_product(vec1, vec2, dim));
	
	// Free both vectors as their memory is allocated
	free(vec1);
	free(vec2);

	// Return 0 to signal succesful execution
	return 0;
}

// Vec function has parameters vector size 'n', argv and
// the starting position for the first element in argv.
// Allocates memory, creates and fills our vector, returning
// it as a pointer.
int *vec(int n, char **argv, int start)
{
	int *output = calloc(n, sizeof(int));
	if (!output)
	{
		return NULL;
	}

	for (int i = 0; i < n; ++i)
	{
		*(output + i) = atoi(argv[start + 2 + i]);
	}
	return output;
}

// Dot_product function has two parameters and their length
// as parameters. Calculates the dot product and returns the
// result.
int dot_product(int *vec1, int *vec2, int n)
{
	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		total += *(vec1 + i) * *(vec2 + i);
	}
	
	return total;
}

// Display function is unused in program and just for
// debugging. Takes in a vector and the length as parameters,
// and prints their elements.
void display(int *vec, int dim)
{
	printf("vector [");
	for (int i = 0; i < dim; ++i)
	{
		printf(" %i ", *(vec + i));
	}
	printf("]\n");
}
