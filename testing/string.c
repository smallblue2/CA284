#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *string = argv[1];
	
	int count = 0;
	while (string[count] != 0) {
		++count;
	}

	printf("The string \"%s\" is %i letters long\n", string, count);

	return 0;
}
