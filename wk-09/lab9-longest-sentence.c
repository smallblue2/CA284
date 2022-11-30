/* 
 * Author: Niall Ryan
 * Description: Program finds the longest word in an input string
 *
 * Input: A string from cmd line
 * Output: The longest word in a string
 */

// Header files
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int stringLength(char *string);
void longestWords(char **strings, int amt);
char **reset(char *string);
void display(char **longest, int len_array);

// Main function
int main(int argc, char **argv)
{
	char **strings = &*(argv + 1);
	longestWords(strings, argc - 1);
	return 0;
}

// Find the length of a string
int stringLength(char *string)
{
	int length = 0;
	while (*string != '\0')
	{
		length++;
		string++;
	}
	return length;
}

// Finds the longest word(s) from argv
void longestWords(char **strings, int amt)
{
	// Set up variables & pointers
	int len_array = 1;
	// Assign the first string to be the longest
	char **longest = reset(*(strings));
	int longest_len = stringLength(*(longest));
	int length = 0;
	// Loop through the rest of the strings
	for (int i = 1; i < amt; i++)
	{
		// Find the length of the current string
		length = stringLength(*(strings + i));
		// If it is larger, reset the longest array and place the
		// new string inside
		if (length > longest_len)
		{
			longest_len = length;
			longest = reset(*(strings + i));
			len_array = 1;
		// Else, expand the longest array's memory and add the
		// additional string inside
		} else if (length == longest_len) {
			len_array++;
			char **temp_longest = (char **)realloc(longest, len_array * sizeof(char *));
			if (!longest)
			{
				printf("Error: Memory allocation failed!\n");
				free(longest);
				return;
			}
			longest = temp_longest;
			*(longest + len_array - 1) = *(strings + i);
		}
	}
	// Display the longest word(s)
	display(longest, len_array);
	free(longest);
	longest = NULL;
	return;
}

// Resets the longest word array
char **reset(char *string)
{
	char **longest = (char **)malloc(sizeof(char *));
	if (!longest)
	{
		printf("Error: Memory Allocation Failed!\n");
		return NULL;
	}
	*(longest) = string;
	return longest;
}

// Displays the longest word(s)
void display(char **longest, int len_array)
{
	for (int i = 0; i < len_array; i++)
	{
		printf("%s\n", *(longest + i));
	}
	return;
}
