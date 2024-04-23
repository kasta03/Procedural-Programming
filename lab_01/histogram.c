#include "../my_functions/functions_0d.h"
#include <stdio.h>
#include <time.h>
#define N 1000000
#define HIST 10
#define MIN -15
#define MAX 85

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    unsigned int tab[HIST] = {0};
    //double x = 0;
    double dx = 0;
    if (MIN * MAX < 0)
    {
        dx = (abs(MIN) + abs(MAX)) / HIST;
    }
    else
    {
        dx = abs(MIN - MAX) / HIST;
    }
    for (int i = 0; i < N; i++)
    {
        double x = d_rand(MIN, MAX);
        for (int k = 0; k < HIST; k++)
        {
            if (x < MIN + (k + 1) * dx)
            {
            tab[k]++;
            break;
            }
        }
    }
    for (int i = 0; i < HIST; i++)
    {
        printf("%d: %d\n", (i + 1), tab[i]);
    }
    return 0;
}
