/*
 * Author: Niall Ryan
 * File: lab1-convert-units.c
 * Description: Takes input in cm and converts to inches
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	/* declare variables */
	float centimetres, inches;

	/* converts character array to integer */
	centimetres = atoi(argv[1]);

	/* calculations */
	inches = centimetres / 2.54;

	/* output */
	printf("%.2f\n", inches);

	return 0;
}
