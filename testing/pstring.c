#include <stdio.h>

int counter(char *string);

int main() {
	char *my_string = "I love Zoe!";
	int length = counter(my_string);

	for ( int i = 0; i < length; ++i) {
		printf("Position of *(my_string + %i) = %c\n", i, *(my_string +i));
	}

	return 0;
}

int counter(char *string) {
	int count = 0;
	while (string[count] != '\0') {
		count++;
	}

	return count;
}
