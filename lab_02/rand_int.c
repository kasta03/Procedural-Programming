#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max)
{
    return min + rand()%(max-min+1);
}
int main()
{
    srand(time(0));
    for (int i=0; i<100;i++)
    {
        int x = i_rand(10,20);
        printf("%d\n", x);
    }
    return 0;
}