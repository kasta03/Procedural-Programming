#include "../my_functions/functions_0d.h"
#include "stdio.h"
#include "time.h"
#define MIN 0
#define MAX 100

void sort(double *a, double *b, double *c)
{
    double *tab[3] = {a, b, c};
    for (int i = 0; i < 2; i++)
    {
        int k = i;
        for (int j = i + 1; j < 3; j++)
        {
            if (*tab[j] < *tab[k])
            {
                k = j;
            }
        }
        swap(tab[i], tab[k], sizeof(double));
    }
}
void sort_test(double pr)
{
    double a, b, c;
    for (int i = 0; i < pr; i++)
    {
        a = d_rand(MIN, MAX);
        b = d_rand(MIN, MAX);
        c = d_rand(MIN, MAX);
        printf("%f %f %f\n", a, b, c);
        sort(&a, &b, &c);
        printf("%f %f %f\n", a, b, c);
    }
}
int main()
{
    srand(time(0));
    //sort(&a, &b, &c);
    //printf("%f %f %f\n", a, b, c);
    //printf("");
    sort_test(100);
    return 0;
}