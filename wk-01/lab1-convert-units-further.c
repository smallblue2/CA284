/*
 * Author: Niall Ryan
 * File: lab1-convert-units-further.c
 * Description: Formatted output of centimetres to inches from
 * 		30 to 49 inclusive.
 */

/* includes */
#include <stdio.h>
#include <math.h>

int main() {
	/* declare variables */
	float inches;
	int centimetres = 30;
	
	/* while loop running from 30 to 49 inclusive */
	while (centimetres <= 49){
		
		/* convert calculation */
		inches = centimetres / 2.54;

		/* print calculation without newline */
		printf("%.2f ", inches);
		
		/* if 5 columns, start a new row */
		if ((centimetres + 1) % 5 == 0) {
			printf("\n");
		}
		
		/* increment centimetres by one */
		centimetres++;
	}

	return 0;
}
