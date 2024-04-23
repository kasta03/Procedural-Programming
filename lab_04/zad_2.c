#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double *my_alloc(int min, int max) {
  int size = max - min + 1;
  double *tmp = (double *)malloc(sizeof(double) * size);

  return tmp - min;
}

double d_rand(double min, double max)
{
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}

void *my_free(double **my_tab, int min) {
  free(*(my_tab)+min);
  *my_tab=NULL;
}

void d_array_set_random(double *first, double *last, double min, double max)
{
    while (last > first)
        *--last = d_rand(min, max);
}

int main()
{
    srand(time(NULL));
    double *tab = my_alloc(-2, 4);

    for (int i = -2; i <= 4; i++)
    {
        tab[i] = 8.8;
        printf("tab[%d] = %f adres= %p\n", i, tab[i], &tab[i]);
    }

    d_array_set_random(tab - 1, tab + 4, 0, 100);

    printf("\n");

    for (int i = -2; i <= 4; i++)
    {
        printf("tab[%d] = %.1f adres= %p\n", i, tab[i], &tab[i]);
    }

    my_free(&tab, -2);
    return 0;
}
