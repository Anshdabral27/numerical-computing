#include <stdio.h>
#include <math.h>

#define MAX 10

void gauss_elimination(double a[MAX][MAX], double b[MAX], int n) {
    double x[MAX], temp;
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[j][i] != 0.0) {
                temp = a[j][i] / a[i][i];
                for (k = i; k < n; k++) {
                    a[j][k] = a[j][k] - temp * a[i][k];
                }
                b[j] = b[j] - temp * b[i];
            }
        }
    }

    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        x[i] = b[i];
        for (j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    for (i = 0; i < n; i++) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }
}

int main() {
    double a[MAX][MAX], b[MAX];
    int n, i, j;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (a|b):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
        scanf("%lf", &b[i]);
    }

    gauss_elimination(a, b, n);

    return 0;
}
