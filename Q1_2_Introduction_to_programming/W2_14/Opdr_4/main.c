#include <stdio.h>
#include "functions.h"
#include "student.h"

// Week 14, Opdr 4:
// Write a program that asks a user to enter the grades for a number of students.
// The program must stop asking for grades, when the user enters an empty name.
// After the user has entered all grades, the program must print the names and grades of all students,
// and print the number of students per grade.

int main() {

    student_t students[20];
    const int SIZE = sizeof(students) / sizeof(students[0]);

    read_students(students, SIZE);

    print_students(students, SIZE);

    print_grades(students);

    read_string("\n\nPress enter to exit...");

    return 0;
}
