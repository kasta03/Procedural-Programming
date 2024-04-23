#ifndef FUNCTIONS_0D_H
#define FUNCTIONS_0D_H
#define RAND_MAX 2147483647
#include <stdio.h>
#include <stdlib.h>
#include "functions_0d.h"

int i_rand(int min, int max)
{
    return min + rand () % (max-min+1);
}

double d_rand(double min, double max)
{
    return ((double) rand() / RAND_MAX) * ((max - min) + min);
}

void i_swap(int *restrict first, int *restrict second)
{
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void swap(void * first, void * second, size_t size)
{
    char *p_first = first;
    char *p_second = second;
    char tmp;
    for (size_t i=0; i<size; i++)
    {
        tmp = *(p_first + i);
        *(p_first + i) = *(p_second + i);
        *(p_second + i) = tmp;
    }
}

#endif