#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_symmetric(const short *first, const short *last) 
{
    int size = last - first + 1;
    int sqrt_size = sqrt(size);
    if (sqrt_size * sqrt_size != size) 
    {
        return false;
    }

    for (int i = 0; i < sqrt_size; i++) 
    {
        for (int j = i + 1; j < sqrt_size; j++) 
        {
            if (*(first + i * sqrt_size + j) != *(first + j * sqrt_size + i)) 
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    short tab[3][3] = {{1, 2, 3}, {2, 7, 2}, {3, 2, 4}};
    short *first = &tab[0][0];
    short *last = &tab[3][3];

    printf("%d\n", is_symmetric(first, last));
}