/* 
 * Author: Niall Ryan
 * Description: Counts odd elements in array from input
 * Input: multiple integers from cmd line
 * Output: a single integer counting odd inputs
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Main functions */
int main(int argc, char *argv[]) {
	
	/* Check input */
	if ( argc > 1 ) {
		/* Total counter */
		int total = 0;
		/* Create input data array */
		int data[argc - 1];

		/* Fill Array */
		int i = 0;
		while ( i < argc - 1 ) {
			data[i] = atoi(argv[i + 1]);
			i++;
		}

		/* Iterate over array and sum odd numbers */
		i = 0;
		while ( i < argc - 1 ) {
			if ( data[i] % 2 == 1 ) {
				total += 1;
			}
			i++;
		}
		
		/* Output total */
		printf("%i\n", total);
	} else {
		printf("input needed!\n");
	}

	return 0;
}
