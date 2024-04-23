#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define N 100

void print()
{
    printf("**************************************************\n"
    "Wybierz opcje:\n"
    "-->      A: wykonaj mnozenie.\n"
    "-->      B: zadaj zagadke.\n"
    "-->      D: wyswietl dowcip.\n"
    "-->      Q: zakoncz program.\n"
    "**************************************************\n");
}
char choice()
{
    char option;
    scanf(" %c", &option);
    return toupper(option);
}
int ints(int *x, int *y)
{
    scanf("%d %d",x,y);
    return 0;
}
int result(int first, int second)
{
    return first*second;
}
void task_A()
{
    int first, second;
    printf("Prosze podać 2 liczby całkowite: \n");
    ints(&first, &second);
    printf("Wynik mnożenia to: %d\n",result(first, second));
}
// void comparison(char *city, char *stolica)
// {
//     while(toupper(*city)!=toupper(warszawa))
// }
// void miasto(char city[N])
// {
//     fflush(stdin);
//     fgets(city, N, stdin);
// }
// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>
// #include <ctype.h>
// #define N 100

void print_ZADANIE_2()
{
    printf("    2. ZADANIE\n");
}
void clear_buffer(void)
{
    while (getchar() != '\n')
        continue;
}
void get_string(char *string)
{
    // fgets(string, N, stdin);
    scanf("%s", string);
    // clear_buffer();
}
void toupper_string(char *string)
{
    //*string=toupper(*string);
    while(*string!='\0')
    {
    *string=toupper(*string);
    string++;
    }
    // *word=toupper(*word);
    // while(*word!='\0')
    // {
    // word++;
    // *word=toupper(*word);
    // }
}
bool isWordInString(char* string, char* word)
{
    toupper_string(string);
    toupper_string(word);
    char buffer[64];
    unsigned place = 0;

    char* pointer = string;

    while ((*pointer) != '\0')
    {
        while (*pointer == ' ')
            pointer++;

        buffer[place] = *pointer;
        place++;

        if (*(pointer + 1) == ' ' || *(pointer + 1) == '\0')
        {
            buffer[place] = '\0';
            place = 0;
            printf("tu jest string: |%s|", buffer);
            if (strcmp( word, buffer) == 0)
                return true;
            pointer++;
        }
        pointer++;
    }
    return false;
}
void task_B()
{
    char string[N], word[]="WARSZAWA";
    print_ZADANIE_2();
    get_string(string);
    printf(string);
    if (isWordInString(string, word)==true)
        printf("Gratulacje, udało Ci się\n");
    else if (isWordInString(string, word)==false)
        printf("Nie, %s nie jest stolica Polski!\n", string);
}
void task_D()
{
    printf ("Na swiecie jest 10 rodzajow ludzi: ci, ktorzy rozumieja system binarny, "
    "i ci, ktorzy go nie rozumieja.\n");
}
int main()
{
    char option;
    while(option!='Q')
    {
    print();
    option=choice();
    switch (option)
    {
    case 'A':
        task_A();
        break;
    case 'B':
        task_B();
        break;
    case 'D':
        task_D();
        break;
    case 'Q':
        printf("Koniec\n");
        break;
    default:
        printf("Nierozpoznana opcja [%c], podaj jeszcze raz\n", option);
        break;
    }
    }
}