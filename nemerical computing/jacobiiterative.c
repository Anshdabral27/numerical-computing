#include <stdio.h>
#include <math.h>

#define MAX 10

void jacobi(double a[MAX][MAX], double b[MAX], double x[MAX], int n, double tol, int max_iter) {
    double x_new[MAX];
    int i, j, iter = 0;
    double sum, error;

    do {
        for (i = 0; i < n; i++) {
            sum = 0.0;
            for (j = 0; j < n; j++) {
                if (i != j)
                    sum += a[i][j] * x[j];
            }
            x_new[i] = (b[i] - sum) / a[i][i];
        }

        error = 0.0;
        for (i = 0; i < n; i++) {
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }

        iter++;
        if (iter >= max_iter)
            break;
    } while (error > tol);

    printf("Solution after %d iterations:\n", iter);
    for (i = 0; i < n; i++) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }
}

int main() {
    double a[MAX][MAX], b[MAX], x[MAX] = {0};
    int n, i, j;
    double tol = 0.0001;
    int max_iter = 1000;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the coefficient matrix (a):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the constant matrix (b):\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    jacobi(a, b, x, n, tol, max_iter);

    return 0;
}
