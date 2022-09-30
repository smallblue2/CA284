/*
 * Program: lab1-hello_again_further.c
 * Author: Niall Ryan
 * Description: Takes input from keyboard and outputs with Hello
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>

int main() {
	char firstname[20];
	scanf("%s", firstname);
	printf("Hello\n%s\n", firstname);
	return 0;
}
