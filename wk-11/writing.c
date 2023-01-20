/* Writing to a file */

#include <stdio.h>

int main(int argc, char **argv)
{
	const char *filename = *(argv + 1);
	FILE *my_file = fopen(filename, "w");

	if (!my_file)
	{
		printf("Error: Couldn't open file!");
		return 1;
	}
	fprintf(my_file, "%s\n", *(argv + 2));
	fclose(my_file);

	return 0;
}
