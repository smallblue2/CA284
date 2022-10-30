#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubbleSort(int *array, int n);
void display_array(int *array, int n);
void swap(int *pX, int *pY);

int main(int argc, char **argv)
{
	int length = argc - 1;
	int array[length];
	for (int i = 1; i < argc; ++i)
	{
		array[i - 1] = atoi(argv[i]);
	}
	
	display_array(array, length);
	bubbleSort(array, length);
	display_array(array, length);

	return 0;
}

void bubbleSort(int *array, int n)
{
	// First loop controls number of passes through array
	for (int i = 0; i < n; ++i)
	{
		// Inner loop compares elements to eachother
		// notice length - 1, this is because we won't
		// be comparing final element and final element + 1,
		// as final element + 1 doesn't exist
		for (int j = 0; j < (n - 1); ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}

	return;
}

void swap(int *pX, int *pY)
{
	int temp = *pX;
	*pX = *pY;
	*pY = temp;

	return;
}

void display_array(int *array, int n)
{
	printf("{ ");
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", array[i]);
	}
	printf("}\n");

	return;
}
