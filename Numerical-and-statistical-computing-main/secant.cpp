#include <iostream>
#include <cmath>

using namespace std;


double f(double x) {
    return x * x - 4; 
}


double secant(double x0, double x1, double tol, int maxIter) {
    double x2;
    for (int i = 0; i < maxIter; i++) {
        
        if (f(x1) - f(x0) == 0) {
            cout << "Division by zero. Secant method failed." << endl;
            return NAN; 
        }
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        
        if (fabs(x2 - x1) < tol) {
            return x2;
        }

        
        x0 = x1;
        x1 = x2;
    }

    return x2; 
}

int main() {
    double x0 = 0; 
    double x1 = 5; 
    double tol = 0.0001; 
    int maxIter = 100; 

    double root = secant(x0, x1, tol, maxIter);

    if (!isnan(root)) {
        cout << "The root is: " << root << endl;
    }

    return 0;
}