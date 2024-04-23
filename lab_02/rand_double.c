#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double min, double max)
{
    return (double)(min + rand()%(int)(max-min));
}
int main()
{
    srand(time(NULL));
    for (int i=0; i<100;i++)
    {
        double x = d_rand(10.0,20.0);
        printf("%d\n", x);
    }
    return 0;
}