#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "Student_v2.h"

void print_student_v2(const Student_v2 *student) {
    printf("Imię: %s\n", student->first_name);
    printf("Nazwisko: %s\n", student->last_name);
    printf("Wiek: %hu\n", student->age);
    printf("Email: %s\n", student->email);
    printf("\n");
}

int main() {
    FILE *file = fopen("students.bin", "wb+"); // Otwarcie pliku w trybie zapisu i odczytu binarnego
    if (file == NULL) {
        printf("Nie można otworzyć pliku students.bin\n");
        return 1;
    }

    // Wypisanie zawartości tablicy do pliku
    for (int i = 0; i < num_students; i++) {
        fwrite(&students[i], sizeof(Student_v2), 1, file);
    }

    // Utworzenie nowej tablicy studentów
    Student_v2 loaded_students[num_students];

    // Powrót do początku pliku
    rewind(file);

    // Wczytanie danych z pliku do nowej tablicy
    fread(loaded_students, sizeof(Student_v2), num_students, file);

    // Wypisanie wczytanej tablicy
    for (int i = 0; i < num_students; i++) {
        print_student_v2(&loaded_students[i]);
    }

    fclose(file); // Zamknięcie pliku

    return 0;
}
