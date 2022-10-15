/* 
 * Author: Niall Ryan
 * Description: Multiplies two matrices together,
 * 		defined from command line
 *
 * Input: A list of integers from command line, defining matrices
 * Output: A matrix of the result
 *
 */

// Includes
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void display(int **m, int r, int c);
void fill(int **m, int r, int c, char **argv, int start);
void product(int **m1, int r1, int c1, int **m2, int r2, int c2);

// Main Function
int main(int argc, char **argv) {
	// Define matrix 1
	int r1 = atoi(argv[1]);
	int c1 = atoi(argv[2]);
	// Allocate space for matrix 1
	int **m1 = (int **)malloc(r1 * sizeof(int *));
	for (int i = 0; i < r1; ++i) {
		*(m1 + i) = (int *)malloc(c1 * sizeof(int));
	}

	// Define matrix 2 attributes
	int forward = (r1 * c1) + 2;
	int r2 = atoi(argv[forward + 1]);
	int c2 = atoi(argv[forward + 2]);
	// Allocate space for matrix 2
	int **m2 = (int **)malloc(r2 * sizeof(int *));
	for (int i = 0; i < r2; ++i) {
		*(m2 + i) = (int *)malloc(c2 * sizeof(int));
	}

	// Fill matrices
	fill(m1, r1, c1, argv, 3);
	fill(m2, r2, c2, argv, forward + 3);

	// Find the product of the matrices & display
	product(m1, r1, c1, m2, r2, c2);

	return 0;
}

// Display function will display a matrix in an easy-to-understand way.
// Iterates over elements in matrix array, and prints them.
void display(int **m, int r, int c) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (j != 0) printf(" ");
			printf("%i", *(*(m + i) + j));
		}
		printf("\n");
	}

	return;
}

// Fill function will fill our matrix arrays from command line
// Requires the matrix to be filled, rows, columns, argv and
// the start of where to fill the matrix from argv
void fill(int **m, int r, int c, char **argv, int start) {
	int element = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			*(*(m + i) + j) = atoi(*(argv + element + start));
			element++;
		}
	}

	return;
}

// Product function calculates the product of two matrices
// Requires both matrices and their rows and columns.
// Creates a result matrix to store the result.
// Iteratoes over both matrices, performing dot multiplication of
// their columns and rows, filling the result matrix along the way
// We then finally call the display function to display our result
// matrix.
void product(int **m1, int r1, int c1, int **m2, int r2, int c2) {
	
	int **result = (int **)malloc(r1 * sizeof(int *));
	for (int i = 0; i < r1; ++i) {
		*(result + i) = (int *)malloc(c2 * sizeof(int));
	}

	for (int i = 0; i < r1; ++i) {
		for (int j = 0; j < c2; ++j) {
			for (int k = 0; k < c1; ++k) {
				*(*(result + i) + j) += *(*(m1 + i) + k) * *(*(m2 + k) + j);
			}
		}
	}

	display(result, r1, c2);
	
	return;
}
