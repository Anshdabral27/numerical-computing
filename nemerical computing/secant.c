#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - x - 2;
}

int main() {
    double a = 1, b = 2, c, fa, fb, fc, tol = 0.0001;

    fa = f(a);
    fb = f(b);

    while (fabs(fb) >= tol) {
        c = b - fb * (b - a) / (fb - fa);
        fc = f(c);

        a = b;
        b = c;
        fa = fb;
        fb = fc;
    }

    printf("Root: %lf\n", c);
    return 0;
}
