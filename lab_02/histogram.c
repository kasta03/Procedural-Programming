#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../my_functions/functions_0d.h"
#define MAX_HIST 10
#define dx 10.0
#define MAX 84.999999
#define MIN -15.0
#define RAND_AMOUNT 1000000

// double d_rand(int min, int max)
// {
//     return min + (double)rand()/RAND_MAX * (max - min);
// }
int main()
{
    //double interval_width = (MAX - MIN) / MAX_HIST;
   // printf("%f\n", interval_width);
    srand(time(NULL));
    int tab[MAX_HIST] = {0};
    for (int i = 0; i < RAND_AMOUNT; i++)
    {
        double x = d_rand(MIN, MAX);
        int index = (int)((x - MIN) / dx);
        tab[index]++;
    }
    for (int i = 0; i < MAX_HIST; i++)
        printf("%d. %d\n", i + 1, tab[i]);
    return 0;
}