#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char string[strlen(argv[1]) + 1];
	strcpy(string, argv[1]);
	printf("%s\n", string);
	printf("sizeof argv[1]: %lu\nsizeof string: %lu\n", strlen(argv[1]), strlen(string));
	return 0;
}
