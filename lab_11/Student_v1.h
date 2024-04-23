#ifndef STUDENT_V1_H
#define STUDENT_V1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define EMAIL_MAX 50 // Rozmiar tablicy email w strukturze.

typedef struct
{
    char *first_name; // Uwaga: wskaźnik!
    char *last_name;  // Uwaga: wskaźnik!
    unsigned short age;
    char email[EMAIL_MAX];
} Student_v1;

void print_student(const Student_v1 *student);

void set_first_name(Student_v1 *student, const char *first_name);

void set_last_name(Student_v1 *student, const char *last_name);

void set_age(Student_v1 *student, unsigned int age);

void set_email(Student_v1 *student, const char *email);

void initialize_student(Student_v1 *student, const char *first_name, const char *last_name, unsigned short age, const char *email);

int students_cmp(const void *a, const void *b);

void free_student(Student_v1 *student);

#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student_v1.h"

#define MAX_LINE_LENGTH 256

int count_students(FILE *file) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    rewind(file); // Przewiń na początek pliku

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        count++;
    }

    return count;
}

void read_students(FILE *file, Student_v1 *students, int count) {
    rewind(file); // Przewiń na początek pliku

    for (int i = 0; i < count; i++) {
        Student_v1 student;
        fscanf(file, "%[^,],%[^,],%hu,%[^\n]%*c",
               student.first_name, student.last_name, &student.age, student.email);
        initialize_student(&students[i], student.first_name, student.last_name, student.age, student.email);
    }
}

int students_cmp(const void *a, const void *b) {
    const Student_v1 *student_a = (const Student_v1 *)a;
    const Student_v1 *student_b = (const Student_v1 *)b;

    // Porównanie po nazwisku
    int last_name_cmp = strcmp(student_a->last_name, student_b->last_name);
    if (last_name_cmp != 0) {
        return last_name_cmp;
    }

    // Porównanie po imieniu
    int first_name_cmp = strcmp(student_a->first_name, student_b->first_name);
    if (first_name_cmp != 0) {
        return first_name_cmp;
    }

    // Porównanie po wieku
    return student_a->age - student_b->age;
}

void write_students(FILE *file, const Student_v1 *students, int count) {
    fprintf(file, "SORTED\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%hu,%s\n",
                students[i].first_name, students[i].last_name, students[i].age, students[i].email);
    }
}

int main() {
    system("cp Students_or.csv Students.csv");

    FILE *file = fopen("Students.csv", "r+");
    if (file == NULL) {
        printf("Nie można otworzyć pliku Students.csv\n");
        return 1;
    }

    int num_students = count_students(file);
    Student_v1 *students = malloc(num_students * sizeof(Student_v1));

    if (students == NULL) {
        printf("Błąd alokacji pamięci\n");
        fclose(file);
        return 1;
    }

    read_students(file, students, num_students);
    qsort(students, num_students, sizeof(Student_v1), students_cmp);

    Student_v1 student_to_find = {.age = 33, .first_name = "Jillie", .last_name = "Gonnin"};
    Student_v1 *found_student = bsearch(&student_to_find, students, num_students, sizeof(Student_v1), students_cmp);

    if (found_student != NULL) {
        printf("Znaleziono studenta: %s %s\n", found_student->first_name, found_student->last_name);
    } else {
        printf("Nie znaleziono studenta\n");
    }

    write_students(file, students, num_students);

    free(students);
    fclose(file);

    return 0;
}
