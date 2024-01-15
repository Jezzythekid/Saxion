//
// Created by Eigenaar on 23-12-2023.
//

#include "stdio.h"
#include "student.h"
#include "functions.h"
#include "string.h"

const int GRADE_COUNT = 4;

const char *grade_to_text(result_t grade) {
    switch (grade) {
        case INSUFFICIENT:
            return "Insufficient";
        case SUFFICIENT:
            return "Sufficient";
        case GOOD:
            return "Good";
        case OUTSTANDING:
            return "Outstanding";
        default:
            return "Grade not defined";
    }
}

void read_students(student_t *students, int max) {

    // until max is reached or the name is empty
    for (int i = 0; i < max; i++) {

        students[i] = read_student("please enter a name: ");

        if (students[i].name[0] == '\0') break;

    }

}

student_t read_student(const char *prompt) {

    const char * buff;
    student_t student;
    char grade;

    // read the name of the student, and copy it to the .name
    buff = read_string(prompt);
    strcpy(student.name, buff);

    // skip the rest of the function if name is empty;
    if (student.name[0] == '\0') {
        return student;
    }

    // let the user enter the grade of the student
    printf("Please enter the grade of %s (i, s, g, o)", student.name);
    grade = read_char(": ");

    // check if grade is valid if not try again
    while (grade != 'i' && grade != 's' && grade != 'g' && grade != 'o') {
        printf("Invalid input!\nPlease enter the grade of %s (i, s, g, o)", student.name);
        grade = read_char(": ");
    }

    // write the grade to the student
    switch (grade) {
        case 'i':
            student.grade = INSUFFICIENT;
            break;
        case 's':
            student.grade = SUFFICIENT;
            break;
        case 'g':
            student.grade = GOOD;
            break;
        case 'o':
            student.grade = OUTSTANDING;
            break;
    }

    return student;

}

void print_students(student_t *students, int count) {

    int i = 0;

    printf("\nGrades:\n");

    // while students exist print the name and grade of each student
    while (students[i].name[0] != '\0'){

        print_student(&students[i]);

        i++;

    }

}

void print_student(const student_t *student){

    // check the grade of the student and sprint the corresponding text.
    printf("%s: %s\n", student->name, grade_to_text(student->grade));

}

int count_students_with_grade(student_t *students, result_t grade){

    int i = 0;
    int count = 0;

    while (students[i].name[0] != '\0') {

        if (students[i].grade == grade) count++;
        i++;
    }

    return count;

}

void print_grades(student_t * students){

    printf("\nNumber of students per grade:\n");

    for (int i = 0; i < GRADE_COUNT; i++) {
        printf("%s: %d\n", grade_to_text(i), count_students_with_grade(students, i));
    }

}