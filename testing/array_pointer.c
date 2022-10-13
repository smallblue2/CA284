#include <stdio.h>

int main() {
	int my_array[5] = {1, 2, 3, 4, 5};
	int *pmy_array = &my_array[0];

	printf("Address of my array %p\n", &my_array);
	printf("Address of my pointer %p\n", pmy_array); 
	printf("Value of my array at 0, %i\n", my_array[0]);
	printf("Pointer derefernced %i\n", *pmy_array);
}
