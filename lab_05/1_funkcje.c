#include <stdio.h>
#include <stdlib.h>

char *read_line(void)
{
    int x = 0;
    char *tab = malloc(sizeof(char[x]));
    int size = x;
    int i = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        if (i >= size)
        {
            size += x;
            tab = realloc(tab, sizeof(char[size]));
        }
        *(tab + i) = toupper(c);
        i++;
    }
    *(tab + i) = '\0';
    return tab;
}

char *trim(char *string)
{
    return realloc(string, strlen(string) + 1);
}

void safe_free(void **my_tab)
{
    if (*my_tab != NULL)
    {
        free(*my_tab);
        *my_tab = NULL;
    }
}