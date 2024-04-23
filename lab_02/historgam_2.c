#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN -15
#define MAX 84.999999
#define MAX_HIST 10
#define dx 10.0

double d_rand(double min, double max) {
    return ((double) rand() / RAND_MAX) * (max - min) + min;
}

int main() {
    int histogram[MAX_HIST] = {0};
    srand(time(NULL));

    for (int i = 0; i < 100000; i++) {
        double rand_num = d_rand(MIN, MAX);
        int hist_index = (int) ((rand_num - MIN) / dx);
        histogram[hist_index]++;
    }

    printf("Histogram:\n");
    for (int i = 0; i < MAX_HIST; i++) {
        printf("%d - %d: %d\n", i, i+1, histogram[i]);
    }

    return 0;
}
