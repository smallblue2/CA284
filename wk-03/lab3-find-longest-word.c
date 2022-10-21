/* 
 * Author: Niall Ryan
 * Description: Finds the longest word in a sentence
 *
 * Input: A sentence from argv
 * Output: The longest word in that sentence
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char string[50];
    strcpy(string, argv[1]);
    int i, start = 0, longest = 0, longest_pos = 0;

    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ') {
            start = i + 1;
        } else {
            if (i - start > longest) {
                longest = i - start;
                longest_pos = start;
            }
        }
    }    
    printf("%.*s\n", longest + 1, string + longest_pos);

    return 0;
}
