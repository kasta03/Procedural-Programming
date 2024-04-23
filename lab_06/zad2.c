#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void join_snake_case(char **result, int *result_size, const char *str) {
//     int str_size = strlen(str);
//     int new_size = *result_size + str_size + 1; // Rozmiar nowego łańcucha z uwzględnieniem dodania '_' i str.
//     *result = (char *) realloc(*result, new_size * sizeof(char)); // Realokacja łańcucha wynikowego.
//     strcat(*result, "_"); // Dodanie znaku '_' na końcu łańcucha wynikowego.
//     strcat(*result, str); // Dodanie str na końcu łańcucha wynikowego.
//     *result_size = new_size - 1; // Zaktualizowanie rozmiaru łańcucha wynikowego (bez ostatniego znaku '_').
// }

void join_snake_case(char **dest, const char *sre) {
    size_t dest_len = strlen(*dest);
    size_t sre_len = strlen(sre);
    size_t new_len = dest_len + sre_len + 1;
    *dest = realloc(*dest, new_len * sizeof(char));
    strcat(*dest, "_");
    strcat(*dest, sre);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Nie podano żadnych parametrów wywołania.\n");
        return 1;
    }

    // Inicjalizacja łańcucha wynikowego.
    char *result = (char *) malloc(sizeof(char));
    result[0] = '\0';
    int result_size = 0;

    // Połączenie parametrów wywołania w łańcuch za pomocą funkcji join_snake_case.
    int i;
    for (i = 1; i < argc; i++) {
        join_snake_case(&result, &result_size, argv[i]);
    }

    printf("Wynik: %s\n", result);

    free(result); // Zwolnienie pamięci zajmowanej przez łańcuch wynikowy.

    return 0;
}
