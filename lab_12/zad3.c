#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main() 
{
    FILE *file = fopen(input_file, "rb");
    size_t max_students = 10;
    size_t num_students = 0;
    Student *students = (Student *)malloc(max_students * sizeof(Student));
    size_t read = fread(&students[num_students], sizeof(Student), 1, file);
        if (read != 1) 
        {
            if (feof(file)) 
        {
        }
        num_students++;
    fclose(file);
    free(students);

    return 0;
}