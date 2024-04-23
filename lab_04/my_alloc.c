#include <stdio.h>

double *my_alloc(int min, int max) 
{
  int size = max - min + 1;
  double *tmp = (double *)malloc(sizeof(double) * size);

  return tmp - min;
}
void *my_free(double **my_tab, int min) 
{
  free(*(my_tab)+min);
  *my_tab=NULL;
}