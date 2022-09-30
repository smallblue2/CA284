/*
 * Program: lab1-hello-again.c
 * Author: Niall Ryan
 * Description: takes in a single cmd line argument, and outputs it with Hello
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("Hello %s\n", argv[1]);
}
