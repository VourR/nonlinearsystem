/*
  Iterasi Secant Non-Linear 
*/

#include <stdio.h>
#include <math.h>

#define MAX_ITERATION 1000

// Fungsi f1(x,y) = x^2 + xy - 10
double f1(double x, double y) {
    return x*x + x*y - 10.0;
}

// Fungsi f2(x,y) = y + 3xy^2 - 57
double f2(double x, double y) {
    return y + 3.0*x*y*y - 57.0;
}

int main() {
    double x0 = 1.0, y0 = 3.0;     // tebakan awal pertama
    double x1 = 1.5, y1 = 3.5;     // tebakan awal kedua
    double f1x0, f1x1, f2x0, f2x1;
    double x2, y2;
    double deltaX, deltaY;
    double epsilon = 0.000001;
    int i = 0;

    printf("--------------------------------------\n");
    printf("i\t   x\t\t   y\t\t  deltaX\t  deltaY\n");
    printf("--------------------------------------\n");

    do {
        if (i >= MAX_ITERATION) break;

        f1x0 = f1(x0, y0);
        f1x1 = f1(x1, y1);
        f2x0 = f2(x0, y0);
        f2x1 = f2(x1, y1);

        double dx = (x1 - x0);
        double dy = (y1 - y0);

        // Update x dan y dengan metode secant
        x2 = x1 - f1x1 * (dx / (f1x1 - f1x0));
        y2 = y1 - f2x1 * (dy / (f2x1 - f2x0));

        deltaX = fabs(x2 - x1);
        deltaY = fabs(y2 - y1);

        // Tampilkan hasil dengan format fixed-point
        printf("%-3d\t%10.6f\t%10.6f\t%10.6f\t%10.6f\n", i, x2, y2, deltaX, deltaY);

        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;

        i++;
    } while (deltaX > epsilon || deltaY > epsilon);

    printf("\nSolusi hampiran:\n");
    printf("x = %.6lf\n", x2);
    printf("y = %.6lf\n", y2);
    printf("Iterasi = %d\n", i);

    return 0;
}