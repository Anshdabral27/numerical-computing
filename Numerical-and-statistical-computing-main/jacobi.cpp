#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void jacobi(vector<vector<double>>& a, vector<double>& b, vector<double>& x, int maxIterations, double tolerance) {
    int n = a.size();
    vector<double> x_old(n, 0.0); 

    for (int iteration = 0; iteration < maxIterations; iteration++) {
        vector<double> x_new(n); 
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += a[i][j] * x_old[j];
                }
            }
            x_new[i] = (b[i] - sum) / a[i][i];
        }

        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += abs(x_new[i] - x_old[i]);
        }
        if (error < tolerance) {
            cout << "Converged after " << iteration + 1 << " iterations." << endl;
            for (int i = 0; i < n; i++) {
                x[i] = x_new[i];
            }
            return;
        }

        
        for (int i = 0; i < n; i++) {
            x_old[i] = x_new[i];
        }
    }

    cout << "Did not converge within " << maxIterations << " iterations." << endl;
    for (int i = 0; i < n; i++) {
        x[i] = x_old[i]; 
    }
}

int main() {
    
    vector<vector<double>> a = {
        {10, -1, 2, 0},
        {-1, 11, -1, 3},
        {2, -1, 10, -1},
        {0, 3, -1, 8}
    };
    vector<double> b = {6, 25, -11, 15};
    vector<double> x(4, 0.0); 

    int maxIterations = 100;
    double tolerance = 1e-6;

    jacobi(a, b, x, maxIterations, tolerance);

    cout << fixed << setprecision(6);
    cout << "Solution:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}