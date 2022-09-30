/*
 circle-area-further.c
 author Niall Ryan
 */

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions we may need*/

#define PI 3.1415 /*Defining PI as a constant*/

/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description:  Takes a single argument and computes area of circle
 */

int main(int argc, char * argv[])
{
	/* variable initialisation */
	float radius = 0;
	float area = 0.0;
	/* all command-line arguments come in as character strings, so atoi turns them into ints*/
	radius = atoi(argv[1]);

	/* Check for negative number. Auto-correct and make user aware */
	if (radius < 0) {
		radius *= -1;
		printf("Negative number invalid\n");
		printf("Switched to %.2f\n", radius);
	}

	radius = radius*radius; /* radius squared */

	area = radius*PI; /* calculate area of circle */

        /* print to two decimal places*/
        printf("%.2f\n",area); /* We only want to show only two values to the right of the decimal point*/

        return 0; 
	/* exit correctly*/
}
/* end program*/
