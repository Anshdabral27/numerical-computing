#include <stdio.h>
#include <math.h>

#define MAX 10

void gauss_seidel(double a[MAX][MAX], double b[MAX], double x[MAX], int n, double tol, int max_iter) {
    double sum, error;
    int i, j, iter = 0;

    for (i = 0; i < n; i++) {
        x[i] = 0.0;  // Initialize solution vector to 0
    }

    do {
        error = 0.0;
        for (i = 0; i < n; i++) {
            sum = 0.0;
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum += a[i][j] * x[j];
                }
            }
            double new_x = (b[i] - sum) / a[i][i];
            error += fabs(new_x - x[i]);  // Calculate error
            x[i] = new_x;  // Update solution for x[i]
        }

        iter++;
        if (iter >= max_iter) {
            break;
        }
    } while (error > tol);  // Repeat until error is within tolerance

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

    gauss_seidel(a, b, x, n, tol, max_iter);

    return 0;
}
