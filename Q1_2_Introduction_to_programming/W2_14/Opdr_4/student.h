//
// Created by Eigenaar on 23-12-2023.
//

#ifndef OPDR_4_STUDENT_H
#define OPDR_4_STUDENT_H

typedef enum { INSUFFICIENT, SUFFICIENT, GOOD, OUTSTANDING } result_t;

typedef struct {
    char name[100];
    result_t grade;
} student_t;

/// Returns the text representation of a grade.
/// @param grade The grade to convert to text.
/// @return The text representation of the grade.
const char *grade_to_text(result_t grade);

/// function that asks the user to enter the name and grade of student and
///     writes it tho an array.
/// @param students the address of the array to fill with students
/// @param max the max amount of students
void read_students(student_t *students, int max);

/// Uses the console to read a student from the user.
/// @param prompt The prompt to display to the user.
/// @return The student entered by the user.
student_t read_student(const char *prompt);

/// Prints students (names and grades) to the console.
/// The grade is printed in text form as "insufficient", "sufficient", "good", or "outstanding".
/// @param students The array of student to print.
void print_students(student_t *students, int count);

/// Prints a student (name and grade) to the console.
/// The grade is printed in text form as "insufficient", "sufficient", "good", or "outstanding".
/// @param student The student to print.
void print_student(const student_t *student);

/// Counts the number of students that have a certain grade.
/// @param students The address of the array of students.
/// @param grade The grade students must have to be included in the count.
/// @return The number of students that have the specified grade.
int count_students_with_grade(student_t *students, result_t grade);

/// Function prints the number of grades in an array
/// @param students the array of students
void print_grades(student_t * students);


#endif //OPDR_4_STUDENT_H
