#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define SCREEN_COLS 50
#define MAX_WORD_SIZE 100
#define WORD_TO_GUESS "Warszawa"

void show_menu(void);
void clear_buffer(void);
void show_line_of_menu(const char *option, const char *text);
void show_char_line(char c, int times);
char get_choice(void);
void task_A(void);
void show_header(const char *header);
void task_B(void);
void tell_joke(void);
void get_2ints(int *a, int *b);
void get_string(char *guess);
bool string_isalpha(const char *string);
void string_1st_to_upper(char *string);

int main(int argc, char const *argv[])
{
    show_menu();
    char choice = 0;
    while ((choice = get_choice()) != 'Q')
    {
        switch (choice)
        {
        case 'A':
            task_A();
            break;
        case 'B':
            task_B();
            break;
        case 'D':
            tell_joke();
            break;
        default:
            printf("Nierozpoznana opcja [%c], podaj jeszcze raz!\n", choice);
        }
        printf("\n");
        show_menu();
    }
    printf("Koniec.\n");
    return 0;
}

void show_menu(void)
{
    show_char_line('*', SCREEN_COLS);
    printf("Wybierz opcje:\n");
    show_line_of_menu("A", "wykonaj mnozenie");
    show_line_of_menu("B", "zadaj zagadke");
    show_line_of_menu("D", "wyswietl dowcip");
    show_line_of_menu("Q", "zakoncz program");
    show_char_line('*', SCREEN_COLS);
}

void show_char_line(char c, int times)
{
    for (int i = 0; i < times; ++i)
        putchar(c);
    putchar('\n');
}

void show_line_of_menu(const char *option, const char *text)
{
    printf("--> %6s: %s.\n", option, text);
}

char get_choice(void)
{
    char c = 0;
    while (!isgraph(c = getchar()))
        continue;
    clear_buffer();
    return toupper(c);
}

void clear_buffer(void)
{
    while (getchar() != '\n')
        continue;
}

void task_A(void)
{
    show_char_line('-', SCREEN_COLS);
    show_header("1. ZADANIE");
    printf("Mnozenie int * int. Podaj a i b: ");
    int a, b;
    get_2ints(&a, &b);
    printf("%d * %d = %d\n", a, b, a * b);
    show_char_line('-', SCREEN_COLS);
}

void show_header(const char *header)
{
    printf("%*s\n", (int)((SCREEN_COLS + strlen(header)) / 2), header);
}

void get_2ints(int *a, int *b)
{
    while (scanf("%d %d", a, b) != 2)
    {
        clear_buffer();
        printf("Podano bledne wartosci. Podaj dwie liczby calkowite, oddzielone bialym znakiem: ");
    }
    clear_buffer();
}   

void task_B(void)
{
    show_char_line('-', SCREEN_COLS);
    show_header("2. ZADANIE");
    printf("Jakie miasto jest stolica Polski? Podaj nazwe miasta: ");
    char word[MAX_WORD_SIZE + 1];
    get_string(word);
    string_1st_to_upper(word);
    if (strncmp(WORD_TO_GUESS, word, strlen(WORD_TO_GUESS)) == 0)
        printf("Brawo, zgadles!\n");
    else
        printf("Nie, %s nie jest stolica Polski!\n", word);
    show_char_line('-', SCREEN_COLS);
}

void get_string(char *word)
{
    char format[10];
    sprintf(format, "%%%ds", MAX_WORD_SIZE);
    while (scanf(format, word) != 1 || !string_isalpha(word))
    {
        printf("Podaj prawidlowa nazwe miasta: ");
        clear_buffer();
    }
    clear_buffer();
}

bool string_isalpha(const char *string)
{
    while (*string)
    {
        if (!isalpha(*string++))
            return false;
    }
    return true;
}

void string_1st_to_upper(char *string)
{
    *string = toupper(*string);
    while (*++string)
        *string = tolower(*string);
}

void tell_joke(void)
{
    printf("Na swiecie jest 10 rodzajow ludzi: "
           "ci, ktorzy rozumieja system binarny, "
           "i ci, ktorzy go nie rozumieja.\n");
}
