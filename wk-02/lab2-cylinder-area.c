/*
 * Author: Niall Ryan
 * Description: Computes the area of a cylinder 
 *
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* global variables */
double pi = 3.1415;

/* Main Function */
int main(int argc, char *argv[]) {

	/* Ensures enough arguments are given */
	if (argc == 3) {
		/* takes radius and height from args */
		double radius = atoi(argv[1]);
		double height = atoi(argv[2]);

		/* Ensures both values are positive */
		if (radius < 0 || height < 0) {
			printf("The radius or height cannot be negative!");
			return 0;
		}

		/* Calculations */
		double surface_area = 2*pi*radius*height + 2*pi*radius*radius;
		
		/* Output */
		printf("%.2f\n", surface_area);

	} else if (argc == 1) {
		printf("No input given!\n");
	} else  {
		printf("Two arguments needed!\n");
	}
		

	return 0;
}
