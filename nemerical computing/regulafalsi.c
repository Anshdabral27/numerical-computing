#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - x - 2;
}

int main() {
    double a = 1, b = 2, c, fa, fb, fc, tol = 0.0001;

    fa = f(a);
    fb = f(b);

    if (fa * fb >= 0) {
        printf("Invalid interval\n");
        return 1;
    }

    do {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);

        if (fc == 0.0)
            break;
        else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    } while (fabs(fc) >= tol);

    printf("Root: %lf\n", c);
    return 0;
}
