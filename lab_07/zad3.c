#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int my_strcmp(const void *a, const void *b)
{
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2)
    {
        return -1;
    }
    else if (len1 > len2)
    {
        return 1;
    }
    else
    {
        for(int i = 0; i < len1; i++)
        {
            int cmp = my_charcmp(*(str1 + i), *(str2 + i));
            if (cmp != 0)
            {
                return cmp;
            }
        }
        return 0;
    }
}

int main(int argc, char *argv[])
{
    const char *strings[] = {"Z", "u", "REh4HmPJRS", "One", "one", "[", "@$9325", "two", "THREE", "four", "415", "@#$325", "@#$315", "@#9325", "five", "alpha", "zet", "0zero", "0123", "0", "(text)", "8", "@#$325"};

    const int numStrings = sizeof(strings) / sizeof(strings[0]);
    qsort(strings, numStrings, sizeof(const char *), my_strcmp);
    //qsort(strings, numStrings, strlen(strings[0]), my_charcmp);

    for (int i = 0; i < numStrings; i++)
    {
        printf("%s\n", strings[i]);
    }
    return 0;
}