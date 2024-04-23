#include <stdio.h>

void i_array_print(const int *first, const int *last, const char *header)
{
    int range = last - first;
    int *marek = first;
    for (int i = 0; i < range; i++)
    {
        printf("%d ", marek);
    }
}
int main()
{
    int tab[] = {1, 3, 4, 5, 3, 3, 4, 6, 7, 2, 6, 5, 2, 3, 4, 1};
    i_array_print();
}