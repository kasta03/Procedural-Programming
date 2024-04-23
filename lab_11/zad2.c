#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#define EMAIL_MAX 50  // Rozmiar tablicy email w strukturze.
#define F_NAME_MAX 50 // Rozmiar tablicy first_name w strukturze.
#define L_NAME_MAX 50 // Rozmiar tablicy last_name w strukturze.

typedef struct
{
  char first_name[F_NAME_MAX]; // Uwaga: tablica!
  char last_name[L_NAME_MAX];  // Uwaga: tablica!
  unsigned short age;
  char email[EMAIL_MAX];
} Student_v2;

void print_student(const Student_v1 *student)
{
    assert(student != NULL);
    printf("Dane studenta: %s %s, wiek: %u, adres: %s\n", student->first_name, student->last_name, student->age, student->email);
}

int main()
{
    int num_students;
    FILE *file = fopen("students.bin", "wb+");
    fwrite(&students, sizeof(Students_v2), num_students, file);
}