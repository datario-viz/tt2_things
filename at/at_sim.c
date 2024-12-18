#include <stdlib.h>
#include <time.h>
#include <math.h>

int draw_index(double *weights, int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += weights[i];
    }

    double r = ((double)rand() / RAND_MAX) * total;
    for (int i = 0; i < size; i++) {
        if (r < weights[i]) {
            return i;
        }
        r -= weights[i];
    }
    return size - 1; // Fallback, though should never happen
}

int breakeven_c(int *nums, double *prob1, double *prob2, int size, double cost) {
    double sum1 = 0.0, sum2 = 0.0;
    int equipment = 0;

    while (fabs(sum1 - sum2) <= cost) {
        int index1 = draw_index(prob1, size);
        int index2 = draw_index(prob2, size);

        sum1 += nums[index1];
        sum2 += nums[index2];
        equipment += 1;
    }

    return equipment * 20;
}
