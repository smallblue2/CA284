/* Testing files here */

#include <stdio.h>

int main(int argc, char  **argv)
{
	const char *file_name = *(argv + 1);
	FILE *my_file = fopen(file_name, "r");
	if (!my_file)
	{
		printf("Error: File not found!\n");
		return 1;
	}
	int c = fgetc(my_file);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(my_file);
	}
	fclose(my_file);
	

	return 0;
}
