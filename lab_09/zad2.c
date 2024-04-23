#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    STUDENT = 1,
    GRADUATE = 2,
    REMOVED = -1
} student_status;

typedef struct
{
    char *imie;
    char *nazwisko;
    int wiek;
    char adres[40];
    student_status status;
} Student;

void set_first_name(Student *student, const char *name)
{
    strcpy(student->imie, name);
}

void set_last_name(Student *student, const char *last)
{
    strcpy(student->nazwisko, last);
}

void set_age(Student *student, int age)
{
    student->wiek = age;
}

void set_address(Student *student, const char *address)
{
    strncpy(student->adres, address, sizeof(student->adres));
    student->adres[sizeof(student->adres) - 1] ='\0';
}

void set_status(Student *student, student_status status)
{
    student->status = status;
}

void initialize_student(Student *student, char *imie, char *nazwisko, int wiek, char *adres, student_status status)
{
    student->imie = (char *)malloc(strlen(imie) + 1);
    if (student->imie != NULL)
    {
        strcpy(student->imie, imie);
    }

    student->nazwisko = (char *)malloc(strlen(nazwisko) + 1);
    if (student->nazwisko != NULL)
    {
        strcpy(student->nazwisko, nazwisko);
    }
    set_age(student, wiek);
    set_address(student, adres);
    set_status(student, status);
}

void print_student(Student student)
{
    printf("%s, %s, %d, %s", student.imie, student.nazwisko, student.wiek, student.adres);
    printf("\n");
    switch (student.status)
    {
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
        break;
    }
}

Student *copy_of(Student *student)
{
    Student *copy = (Student *)malloc(sizeof(Student));
    if (copy == NULL)
    {
        return NULL;
    }

    initialize_student(copy, student->imie, student->nazwisko, student->wiek, student->adres, student->status);

    return copy;
}

Student get_older(Student stud1, Student stud2)
{
    if (stud1.wiek > stud2.wiek)
        return stud1;
    else
        return stud2;
}

int main()
{
    Student student1 = {"Kutas", "Kozla", 69, "Gory wa mac", -1};
    Student student2;
    initialize_student(&student2, "Siur", "Benis", 13, "Twoja stara", 1);
    Student *copy_of_1 = copy_of(&student2);
    Student starszy_chuj = get_older(student1, student2);
    Student tabelka_of_stud[4] = {student1, student2, *copy_of_1, starszy_chuj};

    for (int i = 0; i < 4; i++)
    {
        printf("\n");
        print_student(tabelka_of_stud[i]);
        printf("\n");
    }
    Student *tabelka_stud[4];
    for (int i = 0; i < 4; i++)
    {
        *(tabelka_stud + i) = malloc(sizeof(Student));
        *(*(tabelka_stud) + i) = tabelka_of_stud[i];
    }

    for (int i = 0; i < 4; i++)
    {
        free(*(tabelka_stud + i));
    }

    return 0;
}