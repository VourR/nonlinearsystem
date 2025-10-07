/*
  Iterasi Newton-Raphson Non-Linear 
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
    double u[MAX_ITERATION];
    double v[MAX_ITERATION];
    double dux, duy, dvx, dvy;
    double det, deltaX, deltaY;

    x[0] = x0;
    y[0] = y0;

    printf("--------------------------------------\n");
    printf("i\t   x\t\t   y\t\t  deltaX\t  deltaY\n");
    printf("--------------------------------------\n");

    do {
        if (i >= MAX_ITERATION) break;

        // Persamaan non-linear:
        // u = x^2 + xy - 10  --> dux = 2x + y, duy = x
        // v = y + 3xy^2 - 57 --> dvx = 3y^2, dvy = 1 + 6xy

        u[i] = x[i]*x[i] + x[i]*y[i] - 10;
        v[i] = y[i] + 3*x[i]*y[i]*y[i] - 57;

        // Variabel turunan parsial
        dux = 2*x[i] + y[i];
        duy = x[i];
        dvx = 3*y[i]*y[i];
        dvy = 1 + 6*x[i]*y[i];

        // Determinan Jacobi
        det = dux * dvy - duy * dvx;

        // Iterasi Newton-Raphson
        x[i+1] = x[i] - (u[i]*dvy - v[i]*duy) / det;
        y[i+1] = y[i] + (u[i]*dvx - v[i]*dux) / det;

        deltaX = fabs(x[i+1] - x[i]);
        deltaY = fabs(y[i+1] - y[i]);

        printf("%d\t %f\t %f\t %f\t %f\n", i, x[i], y[i], deltaX, deltaY);

        i++;
    } while (deltaX > epsilon || deltaY > epsilon);

    printf("\nSolusi hampiran:\n");
    printf("x = %.6lf\n", x[i]);
    printf("y = %.6lf\n", y[i]);
    printf("Iterasi = %d\n", i);

    return 0;
}
