/* 
 * Author: Niall Ryan
 * File: lab1-rugby.c
 * Description: calculates a rugby score from 4 cmd line arguments
 *
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int try = atoi(argv[1]) * 5;
	int con = atoi(argv[2]) * 2;
	int pen = atoi(argv[3]) * 3;
	int dro = atoi(argv[4]) * 3;

	int sum = try + con + pen + dro;
	printf("%i\n", sum);

	return 0;
}
