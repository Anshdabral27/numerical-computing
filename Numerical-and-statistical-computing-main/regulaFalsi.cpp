#include <iostream>
#include <cmath>

using namespace std;


double f(double x) {
    return x * x - 4; 
}

double regulaFalsi(double a, double b, double tol, int maxIter) {
    if (f(a) * f(b) >= 0) {
        cout << "Function values at a and b must have opposite signs." << endl;
        return NAN; 
    }

    double c = 0;
    for (int i = 0; i < maxIter; i++) {
        
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        
        if (fabs(f(c)) < tol) {
            return c;
        }

        
        if (f(c) * f(a) < 0) {
            b = c; 
        } else {
            a = c; 
        }
    }

    return c; 
}

int main() {
    double a = 0; 
    double b = 5; 
    double tol = 0.0001;
    int maxIter = 100; 

    double root = regulaFalsi(a, b, tol, maxIter);

    if (!isnan(root)) {
        cout << "The root is: " << root << endl;
    }

    return 0;
}