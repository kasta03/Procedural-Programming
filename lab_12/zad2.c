#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "Student.h"
#include "list.h"

typedef enum { LOWER, UPPER } LETTER_CASE;

int cmp_student_by_last_name(const void* a, const void* b) 
{
	assert(a != NULL && b != NULL);

	const Student* student_a = *(const Student**)a;
	const Student* student_b = *(const Student**)b;

	return strcmp(student_a->last_name, student_b->last_name);
}
int i_rand(int min, int max)
{
	assert(min <= max);
	return rand() % (max - min + 1) + min;
}
char rand_letter(LETTER_CASE letter_case) 
{
	int rand_index = i_rand(0, 25);
	char rand_letter = 'a' + rand_index;

	if (letter_case == UPPER)
	{
		rand_letter = toupper(rand_letter);
	}

	return rand_letter;
}
void rand_name(char* array, size_t max_len) 
{
	size_t length = i_rand(1, max_len);
	array[0] = rand_letter(UPPER);
	for (size_t i = 1; i < length; i++) 
	{
		array[i] = rand_letter(LOWER);
	}
	array[length] = '\0';
}
Student* rand_student(void) 
{
	rand_name(student->first_name, sizeof(student->first_name));
	rand_name(student->last_name, sizeof(student->last_name));
	student->age = i_rand(18, 30);
	rand_email(student->email, sizeof(student->email));

	return student;
}

int main(int argc, char *argv[]) {
    if (argc < 3) 
    {
        return 1;
    }

    srand(time(NULL));
    SortedList list;
    int n = atoi(argv[1]);
    char *filename = argv[2];

    list_init(&list, cmp_student_by_last_name);

    for (int i = 0; i < n; i++) 
    {
        Student *student = rand_student();
        list_insert(&list, student);
    }

    printf("Lista:\n");
    list_print(&list, print_student);

    FILE *file = fopen(filename, "wb");
    if (file == NULL) 
    {
        printf("Błąd otwarcia pliku!\n");
        list_destroy(&list);
        return 1;
    }
    ListNode *current = list.head;
    while (current != NULL) 
    {
        fwrite(current->data, sizeof(Student), 1, file);
        current = current->next;
    }
    fclose(file);
    remove_all(&list.head);
    return 0;
}