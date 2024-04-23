#include <stdio.h>
#include <stdlib.h>
#define N 4

double *max_pointer(double (*tab)[N], int numberOfRows) {
  double *max = *tab;
  for (int i = 0; i < numberOfRows; i++) {
    for (int j = 0; j < N; j++) {
      if (*max < tab[i][j]) {
        max = &tab[i][j];
      }
    }
  }
  return max;
}


    // double *maxArray = malloc(rows * sizeof(double));
    // for (int i = 0; i < rows; i++) {
    //     double max = pointerArray[i][0];
    //     for (int j = 1; j < N; j++) {
    //         if (pointerArray[i][j] > max) {
    //             max = pointerArray[i][j];
    //         }
    //     }
    //     maxArray[i] = max;
    //return maxArray;


int main(void) {
  double tab[2][N] = {{10, 2, 11, 13}, {15, 1, 8, 7}};
  double* pointerArray = max_of_rows(tab, 2);

  for (int i = 0; i < 2; ++i)
    printf("%d ", *pointerArray[i]);
  printf("\n");
  free(pointerArray);
}