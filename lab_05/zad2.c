#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *find_first_char_from_set(const char *input_string, const char *set);

int main()
{   
    //char *tab_1 = "To jest pierwszy string";
    //char *tab_2 = "A oto drugi string";
    char *tab_1 = "string";
    char *tab_2 = "bak uyd ud ud";

    char *charakter = find_first_char_from_set(tab_1, tab_2);
     if (charakter != NULL)
    {
        printf("Znak: to: '%c' \n", *charakter);
    }
    else if (charakter==NULL)
    {
        printf("Brak znaków takich samych \n");
    }
}

char *find_first_char_from_set(const char *input_string, const char *set)
{
    for (int i = 0; i < strlen(input_string); i++)
    {
        if (strchr(set, *(input_string + i)) != NULL)
         {
             return (char*)(input_string + i);
         }
    }
    return NULL;
}