#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int my_charcmp(char a, char b)
{
    if (isdigit(a) && isdigit(b))
    {
        return a - b;
    }
    else if ((isalpha(a) && isalpha(b)) || (isupper(a) && islower(b)) || (islower(a) && isupper(b)))
    {
        char lower_a = tolower(a);
        char lower_b = tolower(b);
        return lower_a - lower_b;
    }
    return a - b;
}

int main()
{
    char char1 = 'A';
    char char2 = 'a';
    char char3 = '1';
    char char4 = '!';
    char char5 = 'X';
    
    printf("Porównanie char1 i char2: %d\n", my_charcmp(char1, char2)); // Powinno być ujemne (char1 jest przed char2)
    printf("Porównanie char2 i char1: %d\n", my_charcmp(char2, char1)); // Powinno być dodatnie (char2 jest po char1)
    printf("Porównanie char3 i char4: %d\n", my_charcmp(char3, char4)); // Powinno być ujemne (char3 jest przed char4)
    printf("Porównanie char3 i char5: %d\n", my_charcmp(char3, char5)); // Powinno być ujemne (char3 jest przed char5)

    return 0;
}