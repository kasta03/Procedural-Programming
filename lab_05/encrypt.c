#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TAB_INT 5

const char *const STRING = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *read_line(void);
char *trim(char *string);
void safe_free(void **my_tab);
char *generate_key(const char *key_init);
// void encrypt(char *input_string, const char *key);
// void decrypt(char *input_string, const char *key);

int main()
{
    char *a = read_line();
    a = trim(a);

    char *key_init = "testytestowe";
    char *b = generate_key(key_init);
    printf("generated key: %s\n", b);

    encrypt(a, b);

    safe_free((void **)&a);
    safe_free((void **)&b);
    return 0;
}

char *generate_key(const char *key_init)
{
    char *key = malloc(sizeof(char[26]));
    int i_key = 0;

    for (int i = 0; i < strlen(key_init); i++)
    {
        if (!strchr(key, toupper(*(key_init + i))))
        {
            *(key + i_key) = toupper(*(key_init + i));
            i_key++;
        }
    }

    for (int i = 0; i < strlen(STRING); i++)
    {
        if (!strchr(key, *(STRING + i)))
        {
            *(key + i_key) = *(STRING + i);
            i_key++;
        }
    }

    return key;
}

void encrypt(char *input_string, const char *key)
{
    char *encrypted = malloc(sizeof(char[strlen(input_string) + 1]));

    printf("input string: %s \n", input_string);
    for (int i = 0; i < strlen(STRING); i++)
    {
        for (int j = 0; j < strlen(input_string); j++)
        {
            if (*(STRING + i) == *(input_string + j))
            {
                *(encrypted + j) = *(key + i);
            }
        }
    }
    input_string = encrypted;
    printf("encrypted string: %s \n", input_string);
}

// Czytanie
char *read_line(void)
{
    char *tab = malloc(sizeof(char[TAB_INT]));
    int alloc_size = TAB_INT, i = 0;
    char tmp;
    while ((tmp = getchar()) != '\n')
    {
        if ((i + 1) > alloc_size)
        {
            alloc_size += TAB_INT;
            tab = realloc(tab, sizeof(char[alloc_size]));
        }
        *(tab + i) = toupper(tmp);
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