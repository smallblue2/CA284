#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char my_name[25];
	printf("Please enter your name;\n");
	fgets(my_name, sizeof(my_name), stdin);
	printf("Your name is %s\n", my_name);
}
