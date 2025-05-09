#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x - 4;
}

double df(double x) {
    return 2 * x;
}

double newtonRaphson(double x0, double tol, int maxIter) {
    double x1;
    for (int i = 0; i < maxIter; i++) {
        if (df(x0) == 0) {
            return NAN;
        }
        x1 = x0 - f(x0) / df(x0);
        if (fabs(x1 - x0) < tol) {
            return x1;
        }
        x0 = x1;
    }
    return x1;
}

int main() {
    double x0 = 5;
    double tol = 0.0001;
    int maxIter = 100;
    double root = newtonRaphson(x0, tol, maxIter);
    if (!isnan(root)) {
        cout << "The root is: " << root << endl;
    }
    return 0;
}