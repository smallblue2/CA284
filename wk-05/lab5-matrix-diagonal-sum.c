/*
 * Author: Niall Ryan
 * Description: Takes integer arguments from command line
 * 		First argument signafies matrix's size, (n * n)
 * 		Remaining arguments fill matrix.
 * 		Then the main diagonal of the matrix is summed
 * 		and outputted
 * Input: Multiple integers as cmd line arguments, first signifies 
 * 	  matrix size (n * n)
 * Output: A single integer, the sum of the diagonals
 *
 */

// Includes
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void fill_matrix(int **matrix, int dimension, char **argv);
int sum_diag_matrix(int **matrix, int dimension);

// Main Function
int main(int argc, char **argv) {
	int **matric = {0};
	// Take cmd line args
	int dimension = atoi(argv[1]);
	// Assign and allocate double pointer enough memory for matrix of size dimension
	int **matrix = (int **) malloc(dimension * sizeof(int*));
	// Assign pointers inside double pointer of matrix enough memory for vector of size dimension
	for ( int i = 0; i < dimension; ++i ) {
		*(matrix + i) = (int *) malloc(dimension * sizeof(int));
	}
	// Call fill_matrix function to fill our matrix from cmd line args
	fill_matrix(matrix, dimension, argv);

	// Assign total to the return of our sum_diag_matrix function
	int total = sum_diag_matrix(matrix, dimension);
	// Output our total
	printf("%i\n", total);
	// Return 0 to signal script running correctly
	return 0;
}

// Fill matrix function fills the matrix passed of passed dimension from passed array
void fill_matrix(int **matrix, int dimension, char **arr) {
	// Initialize element integer to keep track of what element we're on
	int element = 0;
	// Nested loop iterates over matrix, filling out the values from the given array
	for ( int i = 0; i < dimension; ++i) {
		for ( int j = 0; j < dimension; ++j) {
			*(*(matrix + i) + j) = atoi(arr[element + 2]);
			element++;
		}
	}
	
	// Return nothing for void
	return;
}

// Sum diag matrix function sums the main diagonal of the matrix passed of passed dimension
int sum_diag_matrix(int **matrix, int dimension) {
	// Initialize total to keep track of sum
	int total = 0;
	// Iterate over diagonal elements of matrix
	for ( int i = 0; i < dimension; ++i) {
		total += *(*(matrix + i) + i);
	}
	
	// Return total sum
	return total;
}
