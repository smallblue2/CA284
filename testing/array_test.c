#include<stdio.h>

int main(int argc, char * argv[])
{
	int numbers[] = {1L, 2L, 3L , 4L}; /* declare an array with type long */
	int *pNumber = numbers; /* point the pNumber to the first byte of the array */

	for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); ++i)
	{
		printf("address pNumber + %d or &numbers[%d] is: %llu\n", i,i, (unsigned long long)(pNumber+i)); /* convert the address to a positive large number */
		printf("value *(pNumber+ %d) is: %d\n", i, *(pNumber+i));
	}
}
