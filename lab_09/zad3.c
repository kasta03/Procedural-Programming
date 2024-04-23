#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double linear(double x);
double quadratic(double x);

#define X_MIN 0.0
#define X_MAX 5.0
#define DX 0.1

void print_info(void);
void print_value(double x, double (*fun)(double));

double (*jump_table[])(double) = {exp, fabs, exp2, sqrt, sin, cos, ceil, linear, quadratic};

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        print_info();
        exit(-1);
    }

    for (double x = X_MIN; x <= X_MAX; x += DX)
    {
        printf("%10g ", x); // Wypisywanie argumentu x
        for (int i = 1; i < argc; ++i)
        {
            int fun_nr = atoi(argv[i]); // Numer funkcji, wybranej przez użytkownika.
            if (fun_nr >= 0 && fun_nr < 9)
            {
                print_value(x, jump_table[fun_nr]);
            }
            else
            {
                printf("Brak funkcji o numerze %d\n", fun_nr);
            }
        }
        printf("\n");
    }
    return 0;
}

double linear(double x) { return 2 * x + 1.5; }

double quadratic(double x) { return x * x - 2 * x + 1.5; }

void print_value(double x, double (*fun)(double))
{
    double y = fun(x);
    printf("%10g ", y);
}

void print_info(void)
{
    printf("Podaj numer(y) funkcji:\n");
    printf("0 - f = e^x\n");
    printf("1 - f = |x|\n");
    printf("2 - f = 2^x\n");
    printf("3 - f = sqrt\n");
    printf("4 - f = sin\n");
    printf("5 - f = cos\n");
    printf("6 - f = ceil\n");
    printf("7 - f =  2x + 1.5\n");
    printf("8 - f = x^2 - 2x + 1.5\n");
}
