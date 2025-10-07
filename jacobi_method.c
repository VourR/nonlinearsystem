/*
  Iterasi Titik Tetap (Jacobi) non-linear
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATION 1000

int main() {
    const float x0 = 1.5;
    const float y0 = 3.5;
    const float epsilon = 0.000001;

    int i = 0;
    double x[MAX_ITERATION];
    double y[MAX_ITERATION];
    float deltaX = 0, deltaY = 0;

    x[0] = x0;
    y[0] = y0;

    printf("--------------------------------------\n");
    printf("i\t   x\t\t   y\t\t  deltaX\t  deltaY\n");
    printf("--------------------------------------\n");

    do {
        if (i == MAX_ITERATION) break;
        x[i+1] = sqrt(10 - x[i] * y[i]);
        y[i+1] = sqrt((57 - y[i]) / (3 * x[i]));

        printf("%d\t %f\t %f\t %f\t %f\n", i, x[i], y[i], deltaX, deltaY);

        deltaX = fabs(x[i+1] - x[i]);
        deltaY = fabs(y[i+1] - y[i]);

        i++;
    } while (deltaX > epsilon || deltaY > epsilon);

    printf("\nSolusi hampiran:\n");
    printf("x = %.6lf\n", x[i]);
    printf("y = %.6lf\n", y[i]);
    printf("Iterasi = %d\n", i);

    return 0;
}
