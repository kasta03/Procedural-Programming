#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int num_args = 0;
    for (int i = 0; i < strlen(format); i++)
    {
        if (format[i] == '%')
            num_args++;
        i++;
    }
    int i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            char specifier = format[i + 1];
            switch (specifier)
            {
            case 'o':
            {
                int value = va_arg(args, int);
                printf("%o", value);
                break;
            }
            case 'u':
            {
                int value = va_arg(args, int);
                printf("%u", value);
                break;
            }
            case 's':
            {
                char *value = va_arg(args, char *);
                printf("%s", value);
                break;
            }
            case 'X':
            {
                unsigned int value = va_arg(args, unsigned int);
                printf("%X", value);
                break;
            }
            default:
            {
                putchar(specifier);
                break;
            }
            }
            i++;
        }
        else
        {
            putchar(format[i]);
        }
        i++;
    }
    va_end(args);
}

int main()
{

    const char *text8 = "Liczba osemkowa";
    const char *text10 = "Liczba dziesietna";
    const char *text16 = "Liczba szesnastkowa";
    unsigned int decimal = 2662834401u;

    my_printf("");
    my_printf("Brak specyfikatorow\n");
    my_printf("%s", text10);
    my_printf("\t%u\n", decimal);
    my_printf("Jeden specyfikator: %X, koniec!\n", decimal);
    my_printf("%s: %u, %s: %o, %s: %X\n", text10, decimal, text8, decimal, text16, decimal);

    return 0;
}