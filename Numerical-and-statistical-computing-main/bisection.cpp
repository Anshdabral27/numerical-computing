#include <iostream>
#include <cmath>

using namespace std;


double f(double x) {
    return x * x - 4; 
}


double bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "Function values at a and b must have opposite signs." << endl;
        return NAN; 
    }

    double c;
    while ((b - a) >= tolerance) {
        c = (a + b) / 2; // Find midpoint

        if (f(c) == 0.0) {
            break; // c is the root
        } else if (f(c) * f(a) < 0) {
            b = c; // Root is in the left half
        } else {
            a = c; // Root is in the right half
        }
    }
    return (a + b) / 2; // Return the root
}

int main() {
    double a, b, tolerance;

    cout << "Enter the left endpoint (a): ";
    cin >> a;

    cout << "Enter the right endpoint (b): ";
    cin >> b;

    cout << "Enter the tolerance: ";
    cin >> tolerance;

    double root = bisection(a, b, tolerance);

    if (!isnan(root)) {
        cout << "Root found: " << root << endl;
    }

    return 0;
}