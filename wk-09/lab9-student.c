/*
 * Author: Niall Ryan
 *
 * Description: Initially accepts an array of two students with
 * 		a name, programme and grade. Programme checks if
 * 		the number of input students from the command line
 * 		is more than two, allocating more memory. Finally
 * 		printing all the students.
 *
 * Input: from argv, <name> <programme> <grade> <name> <programme> ...
 * Output: <name>, <programme>, <grade>\n for all students
 *
 */

// Header Files
#include <stdio.h>
#include <stdlib.h>

// Structs
typedef struct student {
	char *name;
	char *programme;
	float grade;
} student;

// Function Prototypes
student *allocate_students(int numStudents, char **argv);
void display_students(student *students, int numStudents);

// Main Function
int main(int argc, char **argv) 
{
	// Check if number of arguments is correct
	if (argc < 7)
	{
		printf("Usage: %s <name> <programme> <grade> ...\n", argv[0]);
		exit(0);
	}
	
	// Variable Declarations
	int numStudents = (argc - 1) / 3;
	// Call allocate_students to allocate memory and fill students
	student *students = allocate_students(numStudents, argv);
	// Call display_students to print out all students
	display_students(students, numStudents);

	// Free memory
	free(students);
	// Return 0
	return 0;
}

// Allocates first two students from argv, returning
// a pointer to the array of students
student *allocate_students(int numStudents, char **argv)
{
	// Variable Declarations
	int i;
	// Ensure we safely allocate memory for the initial two students
	student *students = malloc(2 * sizeof(student));
	if (!students)
	{
		printf("Error: malloc failed\n");
		exit(0);
	}
	// Loop through the first two students and assign
	for (i = 0; i < 6; i += 3)
	{
		students[i / 3].name = argv[i + 1];
		students[i / 3].programme = argv[i + 2];
		students[i / 3].grade = atof(argv[i + 3]);
	}
	// If there are more than two students, allocate more memory
	if (numStudents > 2)
	{
		student *tmp = (student *)realloc(students, numStudents * sizeof(student));
		if (!tmp)
		{
			printf("Error: realloc failed\n");
			exit(0);
		}
		students = tmp;
	}
	// Assign the rest of the students
	for (; i < numStudents * 3; i += 3)
	{
		students[i / 3].name = argv[i + 1];
		students[i / 3].programme = argv[i + 2];
		students[i / 3].grade = atof(argv[i + 3]);
	}
	// Return the pointer to the array of students
	return students;
}

// Prints all students in the array
void display_students(student *students, int numStudents)
{
	for (int i = 0; i < numStudents; i++)
	{
		printf("%s, %s, %.2f\n", students[i].name, students[i].programme, students[i].grade);
	}
	return;
}
