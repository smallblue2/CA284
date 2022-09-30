/*
 * Author: Niall Ryan
 * Description: Draws an Empty Square
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Main Function */
int main(int argc, char *argv[]) {

	/* Checks arguments are correct */
	if (argc == 2) {
		/* defines dimension */
		int dimension = atoi(argv[1]) - 1;

		/* outputs square */
		for (int i = 0; i <= dimension; ++i) {
			for (int j = 0; j <= dimension; ++j) {
				if ( i == 0 || i == dimension || j == 0 || j == dimension) {
					printf("*");
				} else {
					printf(" ");
				}
			}
			printf("\n");
		}
	} else {
		printf("One argument needed!");
	}

	return 0;
}
