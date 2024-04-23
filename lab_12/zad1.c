#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Student.h"

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