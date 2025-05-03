#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - x - 2;
}

int main() {
    double a = 1, b = 2, c, tol = 0.0001;
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval\n");
        return 1;
    }

    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }

    printf("Root: %lf\n", c);
    return 0;
}
