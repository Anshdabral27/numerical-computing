#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - x - 2;
}

double df(double x) {
    return 3 * x * x - 1;
}

int main() {
    double x0 = 1, x1, tol = 0.0001;

    x1 = x0 - f(x0) / df(x0);

    while (fabs(f(x1)) >= tol) {
        x0 = x1;
        x1 = x0 - f(x0) / df(x0);
    }

    printf("Root: %lf\n", x1);
    return 0;
}
