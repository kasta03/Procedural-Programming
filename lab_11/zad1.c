#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Student_v1.h"

#define MAX_LINE_LENGTH 256
#define MAX_STUDENTS 100

int main()
{
    FILE* file = fopen("Students.csv", "r+");
    int numStudents = 0;
    int maxLineLength = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) 
    {
        int lineLength = strlen(line);
        if (lineLength > maxLineLength) 
        {
            maxLineLength = lineLength;
        }
        numStudents++;
    }
        printf("%d\n", numStudents);
        Student_v1 students[numStudents];
        rewind(file);
        int num_students = numStudents;
        Student_v1 *students = malloc(num_Students * sizeof(Student_v1));

        for (int i = 0; i < numStudents; i++) 
        {
        fscanf(file, "%s ,%s ,%hu ,%s", students[i].first_name, students[i].last_name, &students[i].age, students[i].email);
        }

        qsort(students, numStudents, sizeof(Student_v1), students_cmp);

        Student_v1 student_to_find = {.age = 33, .first_name = "Jillie", .last_name = "Gonnin", .email = "jgonnin9@eepurl.com"};
        Student_v1 *foundStudent = bsearch(&student_to_find, students, numStudents, sizeof(Student_v1), students_cmp);
        if (*foundStudent != NULL) 
        {
        print_student(foundStudent);
        }
        fprintf(file, "SORTED\n");
    for (int i = 0; i < numStudents; i++) 
    {
        fprintf(file, "%s %s %hu %s\n", students[i].first_name, students[i].last_name, students[i].age, students[i].email);
    }
    fclose(file);
    for (int i = 0; i < numStudents; i++) 
    {
        free_student(&students[i]);
    }
    return 0;
}








