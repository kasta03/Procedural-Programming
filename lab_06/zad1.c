#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double min, double max)
{
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}
void d_array_set_random(double* first, double* last, double min, double max)
{
	while (last > first)
		*--last = d_rand(min, max);
}
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Nie podano liczby kolumn! \n");
		return 0;
	}
	size_t n = atoi(*(argv + 1));

	srand(time(0));
	double** triangle = (malloc(n * sizeof(double*)));
	for (size_t i = 0; i < n; i++)
	{
		triangle[i] = malloc((i + 1) * sizeof(double));
		d_array_set_random(triangle[i], triangle[i] + i + 1, 1, 5);
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j <= i; j++) printf("%f ", triangle[i][j]);
        printf("\n");
	}
	for (size_t i = 0; i < n; i++) free(triangle[i]);
    free (triangle);
	return 0;
}