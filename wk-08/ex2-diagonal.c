/* 
 * Author: Niall Ryan
 * Description: Calculates the sum of the negative diagonal of a matrix
 *
 * Approach: I'll use a double pointer and malloc to build my matrix in
 * 	     memory. Filling it from argv, and then summing the anti-diagonal
 * 	     elements. I plan on taking a very similar approach to the previous
 * 	     'sum diagonal' task, iterating over my matrix with a single for loop.
 *
 * Input: First integer represents matrix dimension, 
 * 	  following integers are matrix elements.
 * Output: The negative diagonal summed
 *
 * Date: 03-11-22
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void display_matrix(int **matrix, int dimension);
void fill_matrix(int **matrix, int dimension, char **argv);
int sum_neg_diag(int **matrix, int dimension);

// Main Function
int main(int argc, char **argv)
{	
	// Initialize double pointer as NULL
	int **matrix = NULL;
	// Initialize matrix dimension from argv
	int dimension = atoi(argv[1]);
	// Assign memory to matrix equal to dimension * sizeof 
	matrix = (int **)malloc(dimension * sizeof(int *));
	// Ensure malloc didn't fail
	if (!matrix)
	{
		printf("Failed to allocate memory!");
		return 0;
	}
	// Assign pointers to matrix, allocating memory for each
	for (int i = 0; i < dimension; ++i)
	{
		*(matrix + i) = (int *)malloc(dimension * sizeof(int));
		// Ensure malloc didn't fail
		if (!*(matrix + i))
		{
			printf("Failed to allocate memory!\n");
			return 0;
		}
	}
	
	// Fill our matrix by calling fill_matrix
	fill_matrix(matrix, dimension, argv);
	// Print the output of our sum_neg_diag call
	printf("%i\n", sum_neg_diag(matrix, dimension));

	// Free allocated memory
	for (int i = 0; i < dimension; ++i)
	{
		free(*(matrix + i));
	}
	free(matrix);

	// Return 0 signals succesful execution
	return 0;
}

// Function that fill our matrix from argv
void fill_matrix(int **matrix, int dimension, char **argv)
{
	// Initialize element to keep a counter on what argv element
	// we're on
	int element = 0;
	// Iterate through matrix
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			// Assign matrix values & increment element
			*(*(matrix + i) + j) = atoi(*(argv + element + 2));
			element++;
		}
	}
}

// Function that displays our matrix for testing purposes
void display_matrix(int **matrix, int dimension)
{
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			printf("%i ", *(*(matrix + i) + j));
		}
		printf("\n");
	}
}

// Sum_neg_diag function sums the negative diagonal of the matrix
// and returns it
int sum_neg_diag(int **matrix, int dimension)
{
	// Initialize total counter
	int total = 0;
	// Iterate through matrix diagonal, summing each element
	for (int i = 0; i < dimension; ++i)
	{
		total += *(*(matrix + i) + (dimension - i - 1));
	}
	
	// Return total
	return total;
}
