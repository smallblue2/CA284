#include <stdio.h>

int main() {

	int my_array[5] = {1, 2, 3, 4, 5};
	int *pmy_array = &my_array;

	for ( int i = 0; i < 5; ++i) {
		printf("Value of array[%i] = %i\n", i, my_array[i]);
		printf("Value of *(pmy_array + %i) = %i\n", i, *(pmy_array + i));
	}
}
