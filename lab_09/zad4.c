#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Typ wyliczeniowy reprezentujący status studenta
enum student_status {
    STUDENT = 1,
    GRADUATE = 2,
    REMOVED = -1
};

// Struktura przechowująca dane studenta
struct Student {
    char* first_name;
    char* last_name;
    int age;
    char address[100];
    enum student_status status;
};

// Funkcja ustawiająca imię studenta
void set_first_name(struct Student* student, const char* first_name) {
    student->first_name = strdup(first_name);
}

// Funkcja ustawiająca nazwisko studenta
void set_last_name(struct Student* student, const char* last_name) {
    student->last_name = strdup(last_name);
}

// Funkcja ustawiająca wiek studenta
void set_age(struct Student* student, int age) {
    student->age = age;
}

// Funkcja ustawiająca adres studenta
void set_address(struct Student* student, const char* address) {
    strncpy(student->address, address, sizeof(student->address));
    student->address[sizeof(student->address) - 1] = '\0';  // Upewniamy się, że adres jest zakończony null-terminatorem
}

// Funkcja ustawiająca status studenta
void set_status(struct Student* student, enum student_status status) {
    student->status = status;
}

// Funkcja inicjalizująca studenta
void initialize_student(struct Student* student, const char* first_name, const char* last_name, int age, const char* address, enum student_status status) {
    set_first_name(student, first_name);
    set_last_name(student, last_name);
    set_age(student, age);
    set_address(student, address);
    set_status(student, status);
}

// Funkcja wypisująca dane studenta
void print_student(struct Student student) {
    printf("Dane studenta: %s %s, wiek: %d, adres: %s, status: ", student.first_name, student.last_name, student.age, student.address);

    switch (student.status) {
        case STUDENT:
            printf("student\n");
            break;
        case GRADUATE:
            printf("absolwent\n");
            break;
        case REMOVED:
            printf("usunięty z listy studentów\n");
            break;
        default:
            printf("nieznany\n");
    }
}

// Funkcja tworząca kopię studenta
struct Student copy_of(struct Student source) {
    struct Student copy;
    initialize_student(&copy, source.first_name, source.last_name, source.age, source.address, source.status);
    return copy;
}

// Funkcja porównująca wiek dwóch studentów i zwracająca starszego
struct Student get_older(struct Student student1, struct Student student2) {
    if (student1.age > student2.age) {
        return student1;
    } else {
        return student2;
    }
}

int main() {
    // Inicjalizacja studentów
    struct Student student1 = {"Anna", "Nowak", 20, "ul. Warszawska, Kraków", STUDENT};
    struct Student student2;
    initialize_student(&student2, "Jan", "Kowalski", 22, "ul. Krakowska, Warszawa", GRADUATE);
    struct Student student3 = get_older(student1, student2);

    // Wypisanie danych studentów
    printf("Dane studenta 1:\n");
    print_student(student1);
    printf("\nDane studenta 2:\n");
    print_student(student2);
    printf("\nDane studenta 3 (starszy z studentów 1 i 2):\n");
    print_student(student3);

    // Inicjalizacja tablicy studentów
    struct Student students_array[3];
    students_array[0] = student1;
    students_array[1] = student2;
    students_array[2] = student3;

    printf("\nTablica studentów:\n");
    for (int i = 0; i < 3; i++) {
        print_student(students_array[i]);
    }

    // Inicjalizacja tablicy wskaźników do studentów
    struct Student* students_ptr_array[3];
    for (int i = 0; i < 3; i++) {
        students_ptr_array[i] = malloc(sizeof(struct Student));
        *students_ptr_array[i] = copy_of(students_array[i]);
    }

    printf("\nTablica wskaźników do studentów (kopie):\n");
    for (int i = 0; i < 3; i++) {
        print_student(*students_ptr_array[i]);
    }

    // Zwolnienie zaalokowanej pamięci
    for (int i = 0; i < 3; i++) {
        free(students_ptr_array[i]->first_name);
        free(students_ptr_array[i]->last_name);
        free(students_ptr_array[i]);
    }

    return 0;
}
