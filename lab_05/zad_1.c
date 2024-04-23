#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *read_line(void);
char *trim(char *string);
void safe_free(void **my_tab);

int main(void)
{
}
char *read_line(void)
{
    const int x = 10;
    char *tab = malloc(sizeof(char) * (x));
    int i = 0;
    int size = 10;
    char c;
    while ((c = getchar()) != '\n');
    {
        if (i >= size - 1)
        {
            size = size + x;
            tab = realloc(tab, sizeof(char) * (size));
        }
        *(tab + i) = c;
        i++;
    }
    *(tab + i)= '\0';
    return tab;
}
char *trim(char *string)
{
    return realloc(string, strlen(string) + 1);
}

void safe_free(void **my_tab)
{
    if (my_tab && *my_tab)
    {
        free(*my_tab);
        *my_tab = NULL;
    }
}
// Wywołanie safe_free(void**,&tab);
